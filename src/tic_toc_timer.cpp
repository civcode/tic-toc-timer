#include "tic_toc_timer.h"

//#include <iostream>
//#include <string>
//#include <cstdint>
//#include <chrono>
//#include <sstream>
//#include <iomanip>

using std::cout;
using std::endl;
using std::string;

// TicTocTimer::TicTocTimer(int precision, bool setfill, int setwidth) :
//     precision_(precision),
//     setfill_(setfill),
//     setwidth_(setwidth)
// {};


TicTocTimer::TicTocTimer() :
    unit_(ETimeUnit::kSecond),
    numberFormat_(EStringNumberFormat::kDefault),
    decimals_(0),
    precision_(0),
    w_(0),
    filler_('0')
{}

void TicTocTimer::tic() {
    start_ = std::chrono::high_resolution_clock::now();
}

TicTocTimer& TicTocTimer::toc() {
    // unit_ = ETimeUnit::kSecond;
    // numberFormat_ = EStringNumberFormat::kDefault;
    // decimals_ = 0;
    // precision_ = 0;
    // w_ = 0;
    auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start_);
    dt_ns_ = static_cast<uint64_t>(duration_ns.count());
    return *this;
}

TicTocTimer& TicTocTimer::s() {
    unit_ = ETimeUnit::kSecond;
    return *this;
}

TicTocTimer& TicTocTimer::ms() {
    unit_ = ETimeUnit::kMillisecond;
    return *this;
}

TicTocTimer& TicTocTimer::us() {
    unit_ = ETimeUnit::kMicrosecond;
    return *this;
}

TicTocTimer& TicTocTimer::ns() {
    unit_ = ETimeUnit::kNanosecond;
    return *this;
}

TicTocTimer& TicTocTimer::minute() {
    unit_ = ETimeUnit::kMinute;
    return *this; 
}

TicTocTimer& TicTocTimer::hour() {
    unit_ = ETimeUnit::kHour;
    return *this; 
}

TicTocTimer& TicTocTimer::day() {
    unit_ = ETimeUnit::kDay;
    return *this; 
}

TicTocTimer& TicTocTimer::fixed(int precision) {
    numberFormat_ = EStringNumberFormat::kFixed;
    precision_ = precision; 
    return *this;
}

TicTocTimer& TicTocTimer::leading_zeros(int decimals, int precision, char filler) {
    numberFormat_ = EStringNumberFormat::kLeadingZeros;
    decimals_ = decimals;
    precision_ = precision;
    filler_ = filler;
    return *this;
}

TicTocTimer& TicTocTimer::scientific() {
    numberFormat_ = EStringNumberFormat::kScientific;
    return *this;
}

TicTocTimer& TicTocTimer::default_all() {
    return (this->default_unit().default_string());
}

TicTocTimer& TicTocTimer::default_unit() {
    set_default_unit();
    return *this;
}

TicTocTimer& TicTocTimer::default_string() {
    set_default_string();
    return *this;
}

//template float  TicTocTimer::value<float>();
template double TicTocTimer::value<double>();
template int TicTocTimer::value<int>();

template <typename T>
T TicTocTimer::value() {
    //static_assert(!std::is_same<T, float>::value, "xxx");
    // static_assert(std::is_same<T, double>::value || 
    //               std::is_same<T, double>::value || 
    //               std::is_same<T, int>::value, 
    //               "xxx");
    //static_assert(std::is_signed<T>::value);
    static_assert(!std::is_same<T, unsigned int>::value);
    //static_assert(!std::is_same<T, int>::value);

    // static_assert(std::is_same<T, float>::value || 
    //               std::is_same<T, double>::value || 
    //               std::is_same<T, int>::value, 
    //               "xxx");



    if (std::is_same<T, float>::value)
        cout << "is float\n"; 
    if (std::is_same<T, double>::value)
        cout << "is double\n"; 
    if (std::is_same<T, int>::value)
        cout << "is int\n"; 

    double dt_s = static_cast<double>(dt_ns_)/1.0E9;
    double factor;
    
    switch (unit_) {
        case ETimeUnit::kSecond:      factor = 1.0; break;
        case ETimeUnit::kMillisecond: factor = 1.0E3; break;
        case ETimeUnit::kMicrosecond: factor = 1.0E6; break;
        case ETimeUnit::kNanosecond:  factor = 1.0E9; break;
        case ETimeUnit::kMinute:      factor = 1.0/60; break;
        case ETimeUnit::kHour:        factor = 1.0/60/60; break;
        case ETimeUnit::kDay:         factor = 1.0/60/60/24; break;
    }

    if (std::is_floating_point_v<T>) {
        return dt_s*factor;
    } else {
        double dt = dt_s*factor;
        if (dt < 1.0)
            cout << "[Warning: loss of precision (dt=" << dt_s << " s)] "; 
        return static_cast<T>(round(dt_s*factor));
    }
    //return dt_s/factor;
}

TicTocTimer& TicTocTimer::set_default_unit() {
    unit_ = ETimeUnit::kSecond;
    return *this;
}

TicTocTimer& TicTocTimer::set_default_string() {
    numberFormat_ = EStringNumberFormat::kDefault;
    decimals_ = 0;
    precision_ = 0;
    w_ = 0;
    filler_ = '0';
    return *this;
}

// double TicTocTimer::toc_v() {
//     return toc().s().value();
// }

// double TicTocTimer::toc() {
//     auto dt_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start_);
//     uint64_t dt = static_cast<uint64_t>(dt_ns.count());
//     return dt/1.E9;
// }

// uint64_t TicTocTimer::toc2uint(ETimeUnit unit) {
//     auto dt_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start_);
//     //long long unsigned int dt = static_cast<long long unsigned int>(dt_ns.count());
//     uint64_t dt = static_cast<uint64_t>(dt_ns.count());
//     switch (unit) {
//         case ETimeUnit::kNanosecond: dt /= 1; break;
//         case ETimeUnit::kMicrosecond: dt /= 1e3; break;
//         case ETimeUnit::kMillisecond: dt /= 1e6; break;
//         case ETimeUnit::kSecond: dt /= 1e9; break;
//     }
//     return dt;
// }

// float TicTocTimer::toc2float(ETimeUnit unit) {
//     auto dt_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start_);
//     float dt = static_cast<float>(dt_ns.count());
//     switch (unit) {
//         case ETimeUnit::kNanosecond: break;
//         case ETimeUnit::kMicrosecond: dt /= 1e3; break;
//         case ETimeUnit::kMillisecond: dt /= 1e6; break;
//         case ETimeUnit::kSecond: dt /= 1e9; break;
//     }
//     return dt;      
// }

// string TicTocTimer::toc2string(ETimeUnit unit, string postfix, string prefix) {
//     float dt = toc2float(unit);
    
//     auto float_to_string = [=](float val) {
//         std::ostringstream out;
//         out.precision(precision_);
//         if (setfill_)
//             out << std::fixed << std::setfill('0') << std::setw(setwidth_) << val;
//         else
//             out << std::fixed << val;
//         return out.str();
//     };
    
//     return prefix + float_to_string(dt) + postfix;
// }
// TicTocTimer& TicTocTimer::toc2() {
//     return *this;
// }

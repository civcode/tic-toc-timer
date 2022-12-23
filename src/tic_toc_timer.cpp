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

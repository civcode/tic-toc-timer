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

string TicTocTimer::get_unit_string() {
    string unit_string = "";
    switch (unit_) {
            case ETimeUnit::kSecond:      unit_string = "s"; break;
            case ETimeUnit::kMillisecond: unit_string = "ms"; break;
            case ETimeUnit::kMicrosecond: unit_string = "us"; break;
            case ETimeUnit::kNanosecond:  unit_string = "ns"; break;
            case ETimeUnit::kMinute:      unit_string = "minutes"; break;
            case ETimeUnit::kHour:        unit_string = "hours"; break;
            case ETimeUnit::kDay:         unit_string = "days"; break;
    }
    return unit_string; 
}

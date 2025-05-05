#include "tictoc/timer.hpp"

using std::cout;
using std::endl;
using std::string;

TicToc::TicToc() :
    unit_(Unit::kSecond),
    numberFormat_(Format::kDefault),
    decimals_(0),
    precision_(0),
    w_(0),
    filler_('0')
{}

void TicToc::tic() {
    start_ = std::chrono::high_resolution_clock::now();
}

TicToc& TicToc::toc() {
    // unit_ = Unit::kSecond;
    // numberFormat_ = Format::kDefault;
    // decimals_ = 0;
    // precision_ = 0;
    // w_ = 0;
    auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start_);
    dt_ns_ = static_cast<uint64_t>(duration_ns.count());
    return *this;
}

TicToc& TicToc::s() {
    unit_ = Unit::kSecond;
    return *this;
}

TicToc& TicToc::ms() {
    unit_ = Unit::kMillisecond;
    return *this;
}

TicToc& TicToc::us() {
    unit_ = Unit::kMicrosecond;
    return *this;
}

TicToc& TicToc::ns() {
    unit_ = Unit::kNanosecond;
    return *this;
}

TicToc& TicToc::minute() {
    unit_ = Unit::kMinute;
    return *this; 
}

TicToc& TicToc::hour() {
    unit_ = Unit::kHour;
    return *this; 
}

TicToc& TicToc::day() {
    unit_ = Unit::kDay;
    return *this; 
}

TicToc& TicToc::fixed(int precision) {
    numberFormat_ = Format::kFixed;
    precision_ = precision; 
    return *this;
}

TicToc& TicToc::leading_zeros(int decimals, int precision, char filler) {
    numberFormat_ = Format::kLeadingZeros;
    decimals_ = decimals;
    precision_ = precision;
    filler_ = filler;
    return *this;
}

TicToc& TicToc::scientific() {
    numberFormat_ = Format::kScientific;
    return *this;
}

TicToc& TicToc::default_all() {
    return (this->default_unit().default_string());
}

TicToc& TicToc::default_unit() {
    set_default_unit();
    return *this;
}

TicToc& TicToc::default_string() {
    set_default_string();
    return *this;
}


TicToc& TicToc::set_default_unit() {
    unit_ = Unit::kSecond;
    return *this;
}

TicToc& TicToc::set_default_string() {
    numberFormat_ = Format::kDefault;
    decimals_ = 0;
    precision_ = 0;
    w_ = 0;
    filler_ = '0';
    return *this;
}

string TicToc::get_unit_string() {
    string unit_string = "";
    switch (unit_) {
            case Unit::kSecond:      unit_string = "s"; break;
            case Unit::kMillisecond: unit_string = "ms"; break;
            case Unit::kMicrosecond: unit_string = "us"; break;
            case Unit::kNanosecond:  unit_string = "ns"; break;
            case Unit::kMinute:      unit_string = "minutes"; break;
            case Unit::kHour:        unit_string = "hours"; break;
            case Unit::kDay:         unit_string = "days"; break;
    }
    return unit_string; 
}

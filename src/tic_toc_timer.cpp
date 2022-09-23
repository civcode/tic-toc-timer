#include "tic_toc_timer.h"

#include <iostream>
#include <string>
#include <cstdint>
#include <chrono>
#include <sstream>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;

TicTocTimer::TicTocTimer(int precision, bool setfill, int setwidth) :
    precision_(precision),
    setfill_(setfill),
    setwidth_(setwidth)
{};

void TicTocTimer::tic() {
    start_ = std::chrono::high_resolution_clock::now();
}

uint64_t TicTocTimer::toc2uint(ETimeUnit unit) {
    auto dt_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start_);
    //long long unsigned int dt = static_cast<long long unsigned int>(dt_ns.count());
    uint64_t dt = static_cast<uint64_t>(dt_ns.count());
    switch (unit) {
        case ETimeUnit::kNanosecond: dt /= 1; break;
        case ETimeUnit::kMicrosecond: dt /= 1e3; break;
        case ETimeUnit::kMillisecond: dt /= 1e6; break;
        case ETimeUnit::kSecond: dt /= 1e9; break;
    }
    return dt;
}

float TicTocTimer::toc2float(ETimeUnit unit) {
    auto dt_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start_);
    float dt = static_cast<float>(dt_ns.count());
    switch (unit) {
        case ETimeUnit::kNanosecond: break;
        case ETimeUnit::kMicrosecond: dt /= 1e3; break;
        case ETimeUnit::kMillisecond: dt /= 1e6; break;
        case ETimeUnit::kSecond: dt /= 1e9; break;
    }
    return dt;      
}

string TicTocTimer::toc2string(ETimeUnit unit, string postfix, string prefix) {
    float dt = toc2float(unit);
    
    auto float_to_string = [=](float val) {
        std::ostringstream out;
        out.precision(precision_);
        if (setfill_)
            out << std::fixed << std::setfill('0') << std::setw(setwidth_) << val;
        else
            out << std::fixed << val;
        return out.str();
    };
    
    return prefix + float_to_string(dt) + postfix;
}

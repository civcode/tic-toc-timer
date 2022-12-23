#ifndef TIC_TOC_TIMER_H
#define TIC_TOC_TIMER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>
#include <chrono>
#include <type_traits>
#include <cmath>
//#include <sstream>
//#include <iomanip>

using std::cout;
using std::endl;
using std::string;

class TicTocTimer {
public:
    enum class ETimeUnit {
        kNanosecond,
        kMicrosecond,
        kMillisecond,
        kSecond,
        kMinute,
        kHour,
        kDay
    };

    enum class EStringNumberFormat {
        kDefault,
        kFixed,
        kLeadingZeros,
        kScientific
    };
    
    TicTocTimer();
    
    void tic();

    TicTocTimer& toc();
    TicTocTimer& s();
    TicTocTimer& ms();
    TicTocTimer& us();
    TicTocTimer& ns();
    TicTocTimer& minute();
    TicTocTimer& hour();
    TicTocTimer& day();

    TicTocTimer& fixed(int precision=3);
    TicTocTimer& leading_zeros(int decimals=5, int precision=2, char filler='0');
    TicTocTimer& scientific();

    TicTocTimer& default_all();
    TicTocTimer& default_unit();
    TicTocTimer& default_string();

    template <typename T=double>
    T value();

    template <typename T=double>
    //string to_string(bool add_unit=true, string prefix="") {
    string to_string(bool add_unit=true);
    
private:
    int decimals_;
    int precision_;
    int w_;
    char filler_;
    ETimeUnit unit_;
    EStringNumberFormat numberFormat_;

    uint64_t dt_ns_;
    std::chrono::high_resolution_clock::time_point start_;

    TicTocTimer& set_default_unit();
    TicTocTimer& set_default_string();

    string get_unit_string();

};

#include "tic_toc_timer.tpp"

#endif // TIC_TOC_TIMER_H

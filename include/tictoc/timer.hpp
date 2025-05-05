#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <chrono>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>

using std::cout;
using std::endl;
using std::string;

class TicToc {
public:
    enum class Unit {
        kNanosecond,
        kMicrosecond,
        kMillisecond,
        kSecond,
        kMinute,
        kHour,
        kDay
    };

    enum class Format {
        kDefault,
        kFixed,
        kLeadingZeros,
        kScientific
    };
    
    TicToc();
    
    void tic();

    TicToc& toc();
    TicToc& s();
    TicToc& ms();
    TicToc& us();
    TicToc& ns();
    TicToc& minute();
    TicToc& hour();
    TicToc& day();

    TicToc& fixed(int precision=3);
    TicToc& leading_zeros(int decimals=5, int precision=2, char filler='0');
    TicToc& scientific();

    TicToc& default_all();
    TicToc& default_unit();
    TicToc& default_string();

    template <typename T=double>
    T value();

    template <typename T=double>
    string to_string(bool add_unit=true);
    //string to_string(bool add_unit=true, string prefix="") {
    
private:
    int decimals_;
    int precision_;
    int w_;
    char filler_;
    Unit unit_;
    Format numberFormat_;

    uint64_t dt_ns_;
    std::chrono::high_resolution_clock::time_point start_;

    TicToc& set_default_unit();
    TicToc& set_default_string();

    string get_unit_string();

};

#include "tictoc/timer.tpp"

#endif // TIMER_HPP_

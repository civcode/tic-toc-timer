#ifndef TIC_TOC_TIMER_H
#define TIC_TOC_TIMER_H

//#include <iostream>
#include <string>
#include <cstdint>
#include <chrono>
//#include <sstream>
//#include <iomanip>

//using std::cout;
//using std::endl;
using std::string;

class TicTocTimer {
public:
    enum class ETimeUnit {
        kNanosecond,
        kMicrosecond,
        kMillisecond,
        kSecond,
    };
    
    TicTocTimer(int precision=2, bool setfill=false, int setwidth=9);
    
    void tic();
    uint64_t toc2uint(ETimeUnit unit=ETimeUnit::kMillisecond);
    float toc2float(ETimeUnit unit=ETimeUnit::kMillisecond);
    string toc2string(ETimeUnit unit=ETimeUnit::kMillisecond, string postfix="", string prefix="");
    
private:
    bool setfill_;
    int precision_;
    int setwidth_;
    std::chrono::high_resolution_clock::time_point start_;

};

#endif // TIC_TOC_TIMER_H

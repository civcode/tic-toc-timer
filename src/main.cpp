#include <iostream>

#include "tic_toc_timer.h"

using std::cout;
using std::endl;

int main() {

    {
        TicTocTimer timer;
        
        timer.tic();
        for (int i=0; i<1e9; i++) {
            volatile int v;
            v++;
        }
        cout << timer.toc2string(TicTocTimer::ETimeUnit::kNanosecond, " ns\n");
        cout << timer.toc2string(TicTocTimer::ETimeUnit::kMicrosecond, " us\n");
        cout << timer.toc2string(TicTocTimer::ETimeUnit::kMillisecond, " ms\n");
        cout << timer.toc2string(TicTocTimer::ETimeUnit::kSecond, " s\n");
        cout << endl;
        cout << endl;
    }

    { 
        TicTocTimer timer(3, true, 10);
        
        timer.tic();
        for (int i=0; i<1e9; i++) {
            volatile int v;
            v++;
        }
        cout << timer.toc2string(TicTocTimer::ETimeUnit::kNanosecond, " ns\n");
        cout << timer.toc2string(TicTocTimer::ETimeUnit::kMicrosecond, " us\n");
        cout << timer.toc2string(TicTocTimer::ETimeUnit::kMillisecond, " ms\n");
        cout << timer.toc2string(TicTocTimer::ETimeUnit::kSecond, " s\n");
        cout << endl;
        cout << endl;
    }

    {
        TicTocTimer timer;
        
        timer.tic();
        for (int i=0; i<1e9; i++) {
            volatile int v;
            v++;
        }

        cout << "uint64_t" << endl;
        uint64_t val;
        val = timer.toc2uint(TicTocTimer::ETimeUnit::kNanosecond);
        cout << val << " ns" << endl;
        val = timer.toc2uint(TicTocTimer::ETimeUnit::kMicrosecond);
        cout << val << " us" << endl;
        val = timer.toc2uint(TicTocTimer::ETimeUnit::kMillisecond);
        cout << val << " ms" << endl;
        cout << endl;

        cout << "float" << endl;
        float f;
        f = timer.toc2float(TicTocTimer::ETimeUnit::kNanosecond);
        cout << f << " ns" << endl;
        f = timer.toc2float(TicTocTimer::ETimeUnit::kMicrosecond);
        cout << f << " us" << endl;
        f = timer.toc2float(TicTocTimer::ETimeUnit::kMillisecond);
        cout << f << " ms" << endl;
    }

    return 0;
}
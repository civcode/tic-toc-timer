#include <iostream>

#include "tic_toc_timer.h"

using std::cout;
using std::endl;

int main() {

    {
        TicTocTimer timer;

        timer.tic();
        for (int i=0; i<1e6; i++) {
            volatile int v;
            v++;
        }

        //cout << timer.toc_v() << endl;
        //cout << "\n";
        cout << timer.toc().value() << endl;
        cout << "\n";

        cout << "dt = " << timer.toc().s().value() << " s" << endl;
        //cout << "dt = " << timer.toc().ns().value<int>() << " ns" << endl;
        cout << "dt = " << timer.ns().value<int>() << " ns" << endl;
        cout << "dt = " << timer.toc().ns().value() << " ns" << endl;
        cout << "dt = " << timer.toc().ms().value() << " ms" << endl;
        cout << timer.toc().ms().value() << endl;
        cout << timer.us().value<float>() << endl;
        timer.toc().us().value<int>();
        cout << timer.toc().ms().value() << endl;

        cout << "\n";
        cout << "dt = " << timer.toc().s().to_string() << endl;
        cout << "\n";
        cout << "dt = " << timer.toc().ms().to_string() << endl;
        cout << "dt = " << timer.toc().ms().fixed().to_string() << endl;;
        cout << "dt = " << timer.toc().ms().fixed(1).to_string() << endl;;
        cout << "dt = " << timer.ms().fixed().to_string<int>() << endl;;
        cout << "dt = " << timer.ms().fixed().leading_zeros().to_string<int>() << endl;;
        cout << "dt = " << timer.ms().fixed().leading_zeros(5,0,'*').to_string<int>() << endl;;
        cout << "dt = " << timer.toc().ms().leading_zeros().to_string() << endl;;
        cout << "dt = " << timer.toc().ms().leading_zeros(3,2,'*').to_string() << endl;;
        cout << "dt = " << timer.toc().ms().leading_zeros(3,2,'*').to_string<int>() << endl;;
        cout << "dt = " << timer.toc().s().scientific().to_string() << endl;;
        cout << "dt = " << timer.toc().s().fixed().scientific().to_string() << endl;;
        cout << "dt = " << timer.toc().s().scientific().fixed().to_string() << endl;;
        //cout << "dt = " << timer.toc().ms().fill().to_string() << endl;;
        // cout << "dt = " << timer.toc().us().to_string() << endl;;
        // cout << "dt = " << timer.toc().ns().to_string() << endl;;
        // cout << timer.toc().s().to_string(false) << endl;;
        //cout << timer.toc().s().to_string(true, "dt = ") << endl;;

    }

    {
        // TicTocTimer timer;
        
        // timer.tic();
        // for (int i=0; i<1e9; i++) {
        //     volatile int v;
        //     v++;
        // }
        // cout << timer.toc() << " s" << endl;
        // cout << timer.toc2string(TicTocTimer::ETimeUnit::kNanosecond, " ns\n");
        // cout << timer.toc2string(TicTocTimer::ETimeUnit::kMicrosecond, " us\n");
        // cout << timer.toc2string(TicTocTimer::ETimeUnit::kMillisecond, " ms\n");
        // cout << timer.toc2string(TicTocTimer::ETimeUnit::kSecond, " s\n");
        // cout << endl;
        // cout << endl;
    }

    { 
        //TicTocTimer timer(3, true, 10);
        // TicTocTimer timer(3, true, 6);
        
        // timer.tic();
        // for (int i=0; i<1e9; i++) {
        //     volatile int v;
        //     v++;
        // }
        // cout << timer.toc2string(TicTocTimer::ETimeUnit::kNanosecond, " ns\n");
        // cout << timer.toc2string(TicTocTimer::ETimeUnit::kMicrosecond, " us\n");
        // cout << timer.toc2string(TicTocTimer::ETimeUnit::kMillisecond, " ms\n");
        // cout << timer.toc2string(TicTocTimer::ETimeUnit::kSecond, " s\n");
        // cout << endl;
        // cout << endl;
    }

    {
        // TicTocTimer timer;
        
        // timer.tic();
        // for (int i=0; i<1e7; i++) {
        //     volatile int v;
        //     v++;
        // }

        // cout << "uint64_t" << endl;
        // uint64_t val;
        // val = timer.toc2uint(TicTocTimer::ETimeUnit::kNanosecond);
        // cout << val << " ns" << endl;
        // val = timer.toc2uint(TicTocTimer::ETimeUnit::kMicrosecond);
        // cout << val << " us" << endl;
        // val = timer.toc2uint(TicTocTimer::ETimeUnit::kMillisecond);
        // cout << val << " ms" << endl;
        // val = timer.toc2uint(TicTocTimer::ETimeUnit::kSecond);
        // cout << val << " s" << endl;
        // cout << endl;

        // cout << "float" << endl;
        // float f;
        // f = timer.toc2float(TicTocTimer::ETimeUnit::kNanosecond);
        // cout << f << " ns" << endl;
        // f = timer.toc2float(TicTocTimer::ETimeUnit::kMicrosecond);
        // cout << f << " us" << endl;
        // f = timer.toc2float(TicTocTimer::ETimeUnit::kMillisecond);
        // cout << f << " ms" << endl;
        // f = timer.toc2float(TicTocTimer::ETimeUnit::kSecond);
        // cout << f << " s" << endl;
    }

    return 0;
}
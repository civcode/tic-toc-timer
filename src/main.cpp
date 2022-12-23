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

        // cout << timer.toc().value<float>() << endl;
        // cout << timer.toc().value<double>() << endl;
        // cout << timer.toc().value<int>() << endl;
        cout << timer.toc().value<unsigned int>() << endl;
        return 0;
        // cout << timer.toc().ms().to_string() << endl;
        // cout << timer.ms().to_string() << endl;
        // cout << "\n";

        // cout << timer.toc().value() << endl;
        // cout << timer.toc().minute().to_string() << endl;
        // cout << timer.minute().value<int>() << endl;
        // cout << timer.hour().to_string() << endl;
        // cout << timer.day().to_string() << endl;
        cout << "\n";
        // cout << "dt = " << timer.toc().s().value() << " s" << endl;
        // cout << "dt = " << timer.ns().value<int>() << " ns" << endl;
        
        // for (int i=0; i<1e6; i++) {
        //     volatile int v;
        //     v++;
        // }
        // timer.tic();
        // cout << "dt = " << timer.toc().ns().value<int>() << " ns" << endl;
        // cout << "dt = " << timer.toc().s().value() << " s" << endl;

        // cout << "dt = " << timer.toc().ns().value() << " ns" << endl;
        // cout << "dt = " << timer.toc().ms().value() << " ms" << endl;
        // cout << timer.toc().ms().value() << endl;
        // cout << timer.us().value<float>() << endl;
        // timer.toc().us().value<int>();
        // cout << timer.toc().ms().value() << endl;

        cout << "\n";
        // cout << "dt = " << timer.toc().us().to_string() << endl;
        // cout << "dt = " << timer.to_string() << endl;
        // cout << "dt = " << timer.scientific().to_string() << endl;
        // cout << "dt = " << timer.default_unit().to_string() << endl;
        // cout << "dt = " << timer.fixed(2).ms().to_string() << endl;
        // cout << "dt = " << timer.default_unit().to_string() << endl;
        // cout << "dt = " << timer.us().leading_zeros(5,2,'x').to_string() << endl;
        // cout << "dt = " << timer.default_string().to_string() << endl;
        // cout << "dt = " << timer.default_all().to_string() << endl;
        cout << "\n";
        return 0;
        // cout << "dt = " << timer.toc().ms().to_string() << endl;
        // cout << "dt = " << timer.toc().ms().fixed().to_string() << endl;;
        // cout << "dt = " << timer.toc().ms().fixed(1).to_string() << endl;;
        // cout << "dt = " << timer.ms().fixed().to_string<int>() << endl;;
        // cout << "dt = " << timer.ms().fixed().leading_zeros().to_string<int>() << endl;;
        // cout << "dt = " << timer.ms().fixed().leading_zeros(5,0,'*').to_string<int>() << endl;;
        // cout << "dt = " << timer.toc().ms().leading_zeros().to_string() << endl;;
        // cout << "dt = " << timer.toc().ms().leading_zeros(3,2,'*').to_string() << endl;;
        // cout << "dt = " << timer.toc().ms().leading_zeros(3,2,'*').to_string<int>() << endl;;
        // cout << "dt = " << timer.toc().s().scientific().to_string() << endl;;
        // cout << "dt = " << timer.toc().s().fixed().scientific().to_string() << endl;;
        // cout << "dt = " << timer.toc().s().scientific().fixed().to_string() << endl;;
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
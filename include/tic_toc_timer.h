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
    };

    enum class EStringNumberFormat {
        kDefault,
        kFixed,
        kLeadingZeros,
        kScientific
    };
    
    //TicTocTimer(int precision=2, bool setfill=false, int setwidth=9);
    TicTocTimer();
    
    void tic();

    TicTocTimer& toc();
    TicTocTimer& s();
    TicTocTimer& ms();
    TicTocTimer& us();
    TicTocTimer& ns();
    // TicTocTimer& min();
    // TicTocTimer& hour();
    TicTocTimer& fixed(int precision=3);
    TicTocTimer& leading_zeros(int decimals=5, int precision=2, char filler='0');
    TicTocTimer& scientific();

    TicTocTimer& default_all();
    TicTocTimer& default_unit();
    TicTocTimer& default_string();

    //double toc_v();
    
    template <typename T=double>
    T value() {
        double dt_s = static_cast<double>(dt_ns_)/1.0E9;
        double factor;
        
        switch (unit_) {
            case ETimeUnit::kSecond:      factor = 1.0; break;
            case ETimeUnit::kMillisecond: factor = 1.0E3; break;
            case ETimeUnit::kMicrosecond: factor = 1.0E6; break;
            case ETimeUnit::kNanosecond:  factor = 1.0E9; break;
        }

        if (std::is_floating_point_v<T>) {
            return dt_s*factor;
        } else {
            return static_cast<T>(round(dt_s*factor));
        }
        //return dt_s/factor;
    }

    template <typename T=double>
    //string to_string(bool add_unit=true, string prefix="") {
    string to_string(bool add_unit=true) {
        double dt = value();
        string prefix = "";
        string postfix = "";

        if (add_unit) {
            switch (unit_) {
                case ETimeUnit::kSecond:      postfix = " s"; break;
                case ETimeUnit::kMillisecond: postfix = " ms"; break;
                case ETimeUnit::kMicrosecond: postfix = " us"; break;
                case ETimeUnit::kNanosecond:  postfix = " ns"; break;
            }
        }

        //auto value_to_string = [=](double val) {
        auto value_to_string = [=]() {
            std::ostringstream oss;
            if (std::is_floating_point_v<T>) {
                //cout << "is floating point" << endl; 
                // if (numberFormat_ == EStringNumberFormat::kFixed) {
                //     oss << std::setprecision(precision_) << std::fixed;
                // } else if (numberFormat_ == EStringNumberFormat::kLeadingZeros) {
                //     oss << std::setprecision(precision_) <<
                //            std::setfill(filler_) <<
                //            std::setw(decimals_ + precision_ + 1) <<
                //            std::fixed;
                // }  
                switch (numberFormat_) {
                    case EStringNumberFormat::kFixed:
                        oss << std::setprecision(precision_) << std::fixed;
                        break;
                    case EStringNumberFormat::kLeadingZeros:
                        oss << std::setprecision(precision_) <<
                               std::setfill(filler_) <<
                               std::setw(decimals_ + precision_ + 1) <<
                               std::fixed;
                        break;
                    case EStringNumberFormat::kScientific:
                        oss << std::scientific;
                        break;
                }
                // if (numberFormat_ == EStringNumberFormat::kScientific) {
                //     oss << std::scientific;
                // }
                oss << value();
            } else {
                //cout << "is int\n";
                switch (numberFormat_) {
                    case EStringNumberFormat::kFixed:
                        oss << std::setw(decimals_) << std::fixed;
                        break;
                    case EStringNumberFormat::kLeadingZeros:
                        oss << std::setprecision(precision_) <<
                               std::setfill(filler_) <<
                               //std::setw(decimals_ + precision_ + 1) <<
                               std::setw(decimals_) <<
                               std::fixed;
                        break;
                    // case EStringNumberFormat::kScientific:
                    //     oss << std::scientific;
                    //     break;
                }
                //uint64_t val = value<uint64_t>();
                //oss << std::setw(decimals_) << std::setfill(filler_);
                oss << value<uint64_t>();
            }
            //oss << val;
            return oss.str();
        };
        string s;
        //s = prefix + value_to_string(dt) + postfix;
        s = prefix + value_to_string() + postfix;
        return s; 

    }

    //void set_stringFormatFixed();
    //void set_stringFormatScientific();
    //void reset_stringFormat();



    //double toc();
    //uint64_t toc2uint(ETimeUnit unit=ETimeUnit::kMillisecond);
    //float toc2float(ETimeUnit unit=ETimeUnit::kMillisecond);
    //string toc2string(ETimeUnit unit=ETimeUnit::kMillisecond, string postfix="", string prefix="");

    //TicTocTimer& toc2();

    
private:
    //bool setfill_;
    //int precision_;
    //int setwidth_;
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

};

#endif // TIC_TOC_TIMER_H

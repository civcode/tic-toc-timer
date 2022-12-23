
template <typename T>
T TicTocTimer::value() {
    //static_assert(!std::is_same<T, char>::value, "Don't use small types.");
    static_assert(sizeof(T) >= 4, "Larger type is required.");
    //static_assert(!std::is_signed<T>::value);

    // if (std::is_same<T, float>::value)
    //     cout << "is float\n"; 
    // if (std::is_same<T, double>::value)
    //     cout << "is double\n"; 
    // if (std::is_same<T, int>::value)
    //     cout << "is int\n"; 

    double dt_s = static_cast<double>(dt_ns_)/1.0E9;
    double factor;
    
    switch (unit_) {
        case ETimeUnit::kSecond:      factor = 1.0; break;
        case ETimeUnit::kMillisecond: factor = 1.0E3; break;
        case ETimeUnit::kMicrosecond: factor = 1.0E6; break;
        case ETimeUnit::kNanosecond:  factor = 1.0E9; break;
        case ETimeUnit::kMinute:      factor = 1.0/60; break;
        case ETimeUnit::kHour:        factor = 1.0/60/60; break;
        case ETimeUnit::kDay:         factor = 1.0/60/60/24; break;
    }

    if (std::is_floating_point_v<T>) {
        return dt_s*factor;
    } else {
        double dt = dt_s*factor;
        if (dt < 1.0)
            cout << "[Warning: loss of precision (dt=" << dt_s << " s)] "; 
        return static_cast<T>(round(dt_s*factor));
    }
    //return dt_s/factor;
}

template <typename T>
string TicTocTimer::to_string(bool add_unit) {
    double dt = value();
    string prefix = "";
    string postfix = "";

    if (add_unit) {
        switch (unit_) {
            case ETimeUnit::kSecond:      postfix = " s"; break;
            case ETimeUnit::kMillisecond: postfix = " ms"; break;
            case ETimeUnit::kMicrosecond: postfix = " us"; break;
            case ETimeUnit::kNanosecond:  postfix = " ns"; break;
            case ETimeUnit::kMinute:      postfix = " minutes"; break;
            case ETimeUnit::kHour:        postfix = " hours"; break;
            case ETimeUnit::kDay:         postfix = " days"; break;
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
                    /** TODO
                     *  - print warning in case fo loss of precision
                    */

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
#include <cassert>

template <typename T>
T TicToc::value() {

    double dt_s = static_cast<double>(dt_ns_)/1.0E9;
    double factor;
    
    switch (unit_) {
        case Unit::kSecond:      factor = 1.0; break;
        case Unit::kMillisecond: factor = 1.0E3; break;
        case Unit::kMicrosecond: factor = 1.0E6; break;
        case Unit::kNanosecond:  factor = 1.0E9; break;
        case Unit::kMinute:      factor = 1.0/60; break;
        case Unit::kHour:        factor = 1.0/60/60; break;
        case Unit::kDay:         factor = 1.0/60/60/24; break;
    }

    double dt = dt_s*factor;

    if (std::is_floating_point_v<T>) {
        return dt;
    } else {
        if (dt_ns_ != 0 && dt < 1.0) {
            cout << "[Warning: loss of precision in conversion to " << get_unit_string() << " <integral_type> " " (" << dt_s << " s)] "; 
        }
        if (dt > std::numeric_limits<T>::max()) {
            cout << "[Warning: overflow in conversion to " << get_unit_string() << " (" << dt_s << " s)] ";
            dt = std::numeric_limits<T>::max();
        }
        return static_cast<T>(round(dt));
    }
}

template <typename T>
string TicToc::to_string(bool add_unit) {
    double dt = value();
    string prefix = "";
    string postfix = "";

    if (add_unit) {
        postfix = " " + get_unit_string();
    }

    auto value_to_string = [=]() {
        std::ostringstream oss;
        if (std::is_floating_point_v<T>) {
            switch (numberFormat_) {
                case Format::kFixed:
                    /** TODO
                     *  - print warning in case fo loss of precision
                    */
                    oss << std::setprecision(precision_) << std::fixed;
                    break;
                case Format::kLeadingZeros:
                    oss << std::setprecision(precision_) <<
                           std::setfill(filler_) <<
                           std::setw(decimals_ + precision_ + 1) <<
                           std::fixed;
                    break;
                case Format::kScientific:
                    oss << std::scientific;
                    break;
            }
            oss << value();
        } else {
            switch (numberFormat_) {
                case Format::kFixed:
                    oss << std::setw(decimals_) << std::fixed;
                    break;
                case Format::kLeadingZeros:
                    oss << std::setprecision(precision_) <<
                           std::setfill(filler_) <<
                           //std::setw(decimals_ + precision_ + 1) <<
                           std::setw(decimals_) <<
                           std::fixed;
                    break;
                // case Format::kScientific:
                //     oss << std::scientific;
                //     break;
            }
            oss << value<uint64_t>();
        }
        return oss.str();
    };
    string s;
    s = prefix + value_to_string() + postfix;
    return s; 
}
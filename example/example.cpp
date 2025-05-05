#include <iostream>
#include <chrono>
#include <thread>

#include "tictoc/timer.hpp"

using std::cout;
using std::endl;

int main() {

    TicToc timer;

    /* Set starting time */
    timer.tic();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    /* Withou calling .toc() time is still start time */
    cout << "Without calling .toc() time is still start time" << endl;
    cout << "start time: " << timer.s().value() << endl;
    cout << "start time: " << timer.us().value<int>() << endl;
    cout << "start time: " << timer.ns().value() << endl;
    cout << endl;

    /* Call .toc() to get elapsed time */
    cout << "Call .toc() to get elapsed time" << endl;
    timer.toc();
    timer.s();
    cout << "elapsed time: " << timer.value<float>() << endl;
    cout << "elapsed time: " << timer.value<double>() << endl;
    cout << "elapsed time: " << timer.ms().to_string() << endl;
    cout << endl;

    /* Type casting and more units */
    cout << "Type casting and more units" << endl;
    cout << (int)timer.ms().value<short>() << endl;
    cout << timer.ns().value<uint32_t>() << endl;
    cout << timer.ns().value<int>() << endl;
    cout << timer.s().value<int>() << endl;
    cout << endl;

    /* Timer warns of overflow in type casting */
    cout << "Timer warns of overflow in type casting" << endl;
    cout << (int)timer.ms().value<char>() << endl;
    cout << endl;

    /* Timer warns of loss of precision in type casting */
    cout << "Timer warns of loss of precision in type casting" << endl;
    cout << timer.minute().value<int>() << endl;
    cout << timer.hour().value<int>() << endl;
    cout << endl;

    /* Return string */
    cout << "Return string" << endl;
    cout << timer.hour().to_string() << endl;
    cout << timer.day().to_string() << endl;
    cout << endl;

    /* String number format */
    cout << "String number format" << endl;
    timer.toc().minute();
    cout << "dt = " << timer.to_string() << endl;
    cout << "dt = " << timer.scientific().to_string() << endl;
    cout << endl;

    /* Back to unit seconds (default_unit) */
    cout << "Back to unit seconds (default_unit)" << endl;
    cout << "dt = " << timer.default_unit().to_string() << endl;
    cout << endl;

    /* Fixed number of fractional digits */
    cout << "Fixed number of fractional digits" << endl;
    cout << "dt = " << timer.fixed(2).ms().to_string() << endl;
    cout << "dt = " << timer.default_unit().to_string() << endl;
    cout << endl;

    /* Leading zeros or custom character; fixed number of fractional digits */
    cout << "Leading zeros or custom character; fixed number of fractional digits" << endl;
    cout << "dt = " << timer.s().leading_zeros(5,2).to_string() << endl;
    cout << "dt = " << timer.s().leading_zeros(5,2,'x').to_string() << endl;
    cout << endl;

    /* Back to default settings (default_all)*/
    cout << "Back to default settings (default_all)" << endl;
    cout << "dt = " << timer.default_all().to_string() << endl;

    return 0;
}
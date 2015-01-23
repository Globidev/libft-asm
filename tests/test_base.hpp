#pragma once

#include <string>
#include <iostream>

template <class T>
void debug(const T & t) {
    std::cout << t << std::endl;
}

template <class T1, class T2, class... Tn>
void debug(const T1 & t1, const T2 & t2, const Tn &... tn) {
    std::cout << t1 << ", ";
    debug(t2, tn...);
}

struct test_base_t {

    static bool verbose;

    virtual void run() = 0;

protected:

    void assert(bool, const std::string &);

};

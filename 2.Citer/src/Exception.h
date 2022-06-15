//
// Created by bayus on 15/06/22.
//

#ifndef CITER_EXCEPTION_H
#define CITER_EXCEPTION_H

#include <string>
#include <exception>

class Exception: public std::exception {
private:
    const char* message;

public:
    explicit Exception(const char* message);
    ~Exception();

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
};


#endif //CITER_EXCEPTION_H

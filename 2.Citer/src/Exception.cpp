//
// Created by bayus on 15/06/22.
//

#include "Exception.h"

Exception::Exception(const char* message) {
    this->message = message;
}

Exception::~Exception() {}

const char *Exception::what() const noexcept {
    return this->message;
}

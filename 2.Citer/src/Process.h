//
// Created by bayus on 15/06/22.
//

#ifndef CITER_PROCESS_H
#define CITER_PROCESS_H

#include <string>

class Process {
private:
    int pid;

public:
    Process(int pid);

    bool is_exist() const;
    std::string get_name();
    std::string get_path();

    void memoryEdit(int address, char value);
};


#endif //CITER_PROCESS_H

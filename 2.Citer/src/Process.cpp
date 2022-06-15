//
// Created by bayus on 15/06/22.
//

#include "Process.h"
#include <dirent.h>
#include <cerrno>
#include <fstream>
#include <unistd.h>
#include <sstream>
#include <string>
#include "Exception.h"
using  namespace std;


std::string Process::get_name() {
    if(this->is_exist()){
        string path = "/proc/" + to_string(this->pid) + "/comm";
        ifstream fs(path);

        if(fs.is_open()){
            stringstream ss;
            ss << fs.rdbuf();
            return ss.str();
        }else{
            throw Exception("Failed to open process file");
        }
    }else{
        throw Exception("Process not found");
    }
}

std::string Process::get_path() {
    if(this->is_exist()){
        char path[PATH_MAX];
        string proc_path = "/proc/" + to_string(this->pid) + "/exe";

        readlink(proc_path.c_str(), path, PATH_MAX);

        return string(path);
    }else{
        throw Exception("Process not found");
    }
}

void Process::memoryEdit(int address, char value) {

}

bool Process::is_exist() const {
    DIR* dir = opendir(("/proc/" + to_string(this->pid)).c_str());

    if(dir){
        closedir(dir);
        return true;
    } else if(errno == ENOENT) {
        return false;
    } else {
        throw Exception("Some Unknown Error happened");
    }
}

Process::Process(int pid) {
    this->pid = pid;
}

#pragma once
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "flags.h"

class ALU {

public:
    ALU(std::shared_ptr<Flags> flags);

public:

    void mov(std::string& op1, const std::string& op2);
    void add(std::string& op1, const std::string& op2);
    void sub(std::string& op1, const std::string& op2);
    void mul(std::string& op1, const std::string& op2);
    void div(std::string& op1, const std::string& op2);
    void inc(std::string& op1, const std::string& op2 = "");
    void dec(std::string& op1, const std::string& op2 = "");
    void cmp(std::string& op1, const std::string& op2);

public:
    int je(std::string& label, const std::map<std::string, int>& labels);
    int jne(std::string& label, const std::map<std::string, int>& labels);
    int jg(std::string& label, const std::map<std::string, int>& labels);
    int jge(std::string& label, const std::map<std::string, int>& labels);
    int jl(std::string& label, const std::map<std::string, int>& labels);
    int jle(std::string& label, const std::map<std::string, int>& labels);

private:
    std::shared_ptr<Flags> flags;
    
};

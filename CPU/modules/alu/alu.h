#ifndef ALU_H
#define ALU_H

#pragma once
#include <map>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <systemc.h>

#include "modules/flags.h"



class ALU : public sc_module {
public:

    sc_in<uint32_t> op1;
    sc_in<uint32_t> op2;
    sc_in<uint8_t> operation;
    sc_out<uint32_t> out;

    SC_CTOR(ALU);
    ALU(sc_module_name name, std::shared_ptr<Flags> flags) : sc_module(name), flags(flags) {
        SC_THREAD(ALU_Main);
    }

    void mov(std::string& op1, const std::string& op2);
    void add(std::string& op1, const std::string& op2);
    void sub(std::string& op1, const std::string& op2);
    void mul(std::string& op1, const std::string& op2);
    void div(std::string& op1, const std::string& op2);
    void inc(std::string& op1, const std::string& op2 = "");
    void dec(std::string& op1, const std::string& op2 = "");
    void cmp(std::string& op1, const std::string& op2);

    int je(std::string& label, const std::map<std::string, int>& labels);
    int jne(std::string& label, const std::map<std::string, int>& labels);
    int jg(std::string& label, const std::map<std::string, int>& labels);
    int jge(std::string& label, const std::map<std::string, int>& labels);
    int jl(std::string& label, const std::map<std::string, int>& labels);
    int jle(std::string& label, const std::map<std::string, int>& labels);

    void ALU_Main();

private:
    std::shared_ptr<Flags> flags;
    
};

#endif
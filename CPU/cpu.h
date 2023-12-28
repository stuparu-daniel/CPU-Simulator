#pragma once

#include "alu.h"
#include "flags.h"

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>


class ALU;

class CPU {
public:
    CPU(std::shared_ptr<Flags> flags);
    bool is_register(const std::string& op); // checking is operand register or not

public:
    void fetch(std::ifstream& file); //reads from file and saves the containment in map: map<int, string> ram, where key is address of instruction, value is instruction 
    void execute(int i = 0); // executes instructions
    void print(const std::string& op1);

public:
    class InvalidOperandException : public std::exception {
    private:
        std::string message;

    public:
        InvalidOperandException(const std::string& operand)
            : message("Invalid operand: " + operand) {}

        const char* what() const noexcept override {
            return message.c_str();
        }
    };

private:
    ALU alu;
    std::map<int, std::string> ram;
    std::map<std::string, int> registers;
    std::map<int, std::string> instructions;
    std::shared_ptr<Flags> flags;
    std::map<std::string, int> labels; // keeps labels with their addresses
    int eip;

private:
    //helpers
    void name_instructions(); // initialize instructions
    void name_registers(); // initialize registers
    void check_operands(std::string& op1, std::string& op2, void (ALU::* fptr)(std::string&, const std::string&)); //checking for the operand: operands must be regiter register or register literal
    bool is_number(const std::string& str); // checking if string is number
    void remove_comma(std::string& op); // removes comma
    bool has_comma(const std::string& op); // checking if there is comma
};

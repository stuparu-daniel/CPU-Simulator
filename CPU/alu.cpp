#include "alu.h"

ALU::ALU(std::shared_ptr<Flags> flags) : flags(flags)
{
}

void ALU::mov(std::string& op1, const std::string& op2) {
    int num1 = std::stoi(op1);
    int num2 = std::stoi(op2);
    op1 = std::to_string(num2);
}

void ALU::add(std::string& op1, const std::string& op2) {
    int num1 = std::stoi(op1);
    int num2 = std::stoi(op2);
    num1 += num2;
    op1 = std::to_string(num1);
}

void ALU::sub(std::string& op1, const std::string& op2) {
    int num1 = std::stoi(op1);
    int num2 = std::stoi(op2);
    num1 -= num2;
    op1 = std::to_string(num1);
}

void ALU::mul(std::string& op1, const std::string& op2) {
    int num1 = std::stoi(op1);
    int num2 = std::stoi(op2);
    num1 *= num2;
    op1 = std::to_string(num1);
}

void ALU::div(std::string& op1, const std::string& op2) {
    int num1 = std::stoi(op1);
    int num2 = std::stoi(op2);
    num1 /= num2;
    op1 = std::to_string(num1);
}

void ALU::inc(std::string& op1, const std::string& op2) {
    int num = std::stoi(op1);
    ++num;
    op1 = std::to_string(num);
}

void ALU::dec(std::string& op1, const std::string& op2) {
    int num = std::stoi(op1);
    --num;
    op1 = std::to_string(num);
}

void ALU::cmp(std::string& op1, const std::string& op2) {
    std::string tmp = op1;
    sub(op1, op2);
    if (std::stoi(op1) > 0) {
        flags->set_flag("UF", 1);
        flags->set_flag("SF", 0);
        flags->set_flag("ZF", 0);
    }
    else if (std::stoi(op1) == 0) {
        flags->set_flag("UF", 0);
        flags->set_flag("SF", 0);
        flags->set_flag("ZF", 1);
    }
    else if (std::stoi(op1) < 0) {
        flags->set_flag("UF", 0);
        flags->set_flag("SF", 1);
        flags->set_flag("ZF", 0);
    }
    op1 = tmp;
}

int ALU::je(std::string& label, const std::map<std::string, int>& labels) {
    if (flags->get_flag("ZF") == 1) {
        label += ':';
        for (auto it = labels.begin(); it != labels.end(); ++it) {
            if (it->first == label) {
                return it->second + 1;
            }
        }
    }
    return -1;
}

int ALU::jne(std::string& label, const std::map<std::string, int>& labels) {
    if (flags->get_flag("ZF") == 0) {
        label += ':';
        for (auto it = labels.begin(); it != labels.end(); ++it) {
            if (it->first == label) {
                return it->second + 1;
            }
        }
    }
    return -1;
}

int ALU::jg(std::string& label, const std::map<std::string, int>& labels) {
    if (flags->get_flag("UF") == 1) {
        label += ':';
        for (auto it = labels.begin(); it != labels.end(); ++it) {
            if (it->first == label) {
                return it->second + 1;
            }
        }
    }
    return -1;
}

int ALU::jge(std::string& label, const std::map<std::string, int>& labels) {
    if (flags->get_flag("UF") == 1 || flags->get_flag("ZF") == 1) {
        label += ':';
        for (auto it = labels.begin(); it != labels.end(); ++it) {
            if (it->first == label) {
                return it->second + 1;
            }
        }
    }
    return -1;
}

int ALU::jl(std::string& label, const std::map<std::string, int>& labels) {
    if (flags->get_flag("SF") == 1) {
        label += ':';
        for (auto it = labels.begin(); it != labels.end(); ++it) {
            if (it->first == label) {
                return it->second + 1;
            }
        }
    }
    return -1;
}

int ALU::jle(std::string& label, const std::map<std::string, int>& labels) {
    if (flags->get_flag("SF") == 1 || flags->get_flag("ZF") == 1) {
        label += ':';
        for (auto it = labels.begin(); it != labels.end(); ++it) {
            if (it->first == label) {
                return it->second + 1;
            }
        }
    }
    return -1;
}

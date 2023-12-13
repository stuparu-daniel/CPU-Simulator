#pragma once

#include <map>
#include <string>

class Flags {

public:
	Flags();

	char get_flag(const std::string& flag);
	void set_flag(const std::string& flag, char code);

private:
	std::map<std::string, int> flags;
};

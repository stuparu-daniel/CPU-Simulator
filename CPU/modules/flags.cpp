#include "flags.h"

Flags::Flags()
{
	flags["ZF"] = 0; //if == 0 FLAG ZF = 1
	flags["SF"] = 0; // if < 0 flag SF = 1 
	flags["UF"] = 0; // if > 0 flag UF = 1
}

char Flags::get_flag(const std::string& flag)
{
	return flags[flag];
}

void Flags::set_flag(const std::string& flag, char code)
{
	flags[flag] = code;
}

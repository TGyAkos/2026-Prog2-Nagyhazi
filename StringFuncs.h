//
// Created by user on 06/04/2026.
//

#ifndef TITKOSITO_STRINGFUNCS_H
#define TITKOSITO_STRINGFUNCS_H
#include <string>
#include <vector>


struct StringFuncs {
    static std::vector<std::string> split(std::string s, const std::string &delimiter);
    static char shift_char(char c, int shift);
};



#endif //TITKOSITO_STRINGFUNCS_H

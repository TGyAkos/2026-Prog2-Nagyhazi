//
// Created by user on 06/04/2026.
//

#ifndef TITKOSITO_CIPHERFILE_H
#define TITKOSITO_CIPHERFILE_H
#include <string>
#include <vector>

#include "CipherList.h"

class CipherFile {

public:
    CipherFile() = default;
    static CipherList* loadFile(const std::string& file_name);
    static void saveToFile(const std::string& file_name, CipherList* cipher_list);
    ~CipherFile() = default;
};


#endif // TITKOSITO_CIPHERFILE_H

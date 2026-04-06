//
// Created by user on 06/04/2026.
//

#ifndef TITKOSITO_CIPHERFACTORY_H
#define TITKOSITO_CIPHERFACTORY_H
#include <functional>
#include <string>
#include <unordered_map>

#include "Cipher.h"


class CipherFactory {
    std::unordered_map<std::string, std::function<Cipher*(const std::vector<std::string>&)>> ciphers;
    static std::vector<std::string> parseCipherString(const std::string& cipher_string);
public:
    static CipherFactory& getInstance();
    void registerCipher(const std::string& name, std::function<Cipher*(const std::vector<std::string>&)> cipher);
    Cipher* createCipher(const std::string& name);
    bool cipherExists(const std::string& name) const;
    ~CipherFactory();
};



#endif //TITKOSITO_CIPHERFACTORY_H

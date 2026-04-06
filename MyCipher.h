//
// Created by user on 06/04/2026.
//

#ifndef TITKOSITO_MYCIPHER_H
#define TITKOSITO_MYCIPHER_H
#include <string>

#include "Cipher.h"
#include "Registrar.h"

class MyCipher : public Cipher {
    std::string key;
    int offset;
    static void validate_key(const std::string &key);
    static void validate_text(const std::string &text);
public:
    MyCipher(const char* key) : key(key), offset(0) {}
    MyCipher(const char* key, int offset) : key(key), offset(offset) {}
    MyCipher(const std::vector<std::string>& params) : key(params[0]), offset(params.size() > 1 ? stoi(params[1]) : 0) {}
    const std::string getCipherString() const override;
    Cipher *clone() const override;
    std::string encode(const std::string &message) override;
    std::string decode(const std::string &ciphertext) override;
    ~MyCipher() override;
};

#endif //TITKOSITO_MYCIPHER_H

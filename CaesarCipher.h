//
// Created by user on 06/04/2026.
//

#ifndef TITKOSITO_CAESARCIPHER_H
#define TITKOSITO_CAESARCIPHER_H
#include <string>


#include "Cipher.h"
#include "Registrar.h"


class CaesarCipher : public Cipher {
    int shift;
public:
    CaesarCipher(int shift) : shift(shift) {}
    CaesarCipher(const std::vector<std::string>& params) : shift(params[0][0] == '\\' ? 0 : stoi(params[0])) {}
    const std::string getCipherString() const override;
    Cipher *clone() const override;
    std::string encode(const std::string &message) override;
    std::string decode(const std::string &ciphertext) override;
    ~CaesarCipher() override;
};




#endif //TITKOSITO_CAESARCIPHER_H

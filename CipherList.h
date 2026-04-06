//
// Created by user on 06/04/2026.
//

#ifndef TITKOSITO_CIPHERLIST_H
#define TITKOSITO_CIPHERLIST_H
#include <string>
#include <vector>

#include "Cipher.h"


class CipherList {
    std::vector<Cipher *> ciphers;
public:
    using iterator = std::vector<Cipher*>::iterator;
    using const_iterator = std::vector<Cipher*>::const_iterator;
    CipherList();
    CipherList(const CipherList &other);
    CipherList &operator=(const CipherList &other);
    Cipher &operator[](size_t idx);
    const Cipher &operator[](size_t idx) const;
    void addCipher(Cipher *cipher);
    std::string encode(const std::string &message);
    std::string decode(const std::string &ciphertext);
    CipherList *clone() const;
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
    ~CipherList();
};


#endif // TITKOSITO_CIPHERLIST_H

/**
 * \file ciphers.cpp
 *
 * Ebben a fájlban kell megvalósítania az CaesarCipher, MyCipher, CipherQueue osztályok metódusait.
 * 
 * Ezt a fájlt be kell adni (fel kell tölteni) a megoldással.
 */

#include "memtrace.h"
#include "ciphers.h"

void validate_text(const std::string& text) {
    for (size_t i = 0; i < text.size(); ++i) {
        if (!(text[i] == ' ' || (text[i] >= 'a' && text[i] <= 'z'))) {
            throw "Q4JZL0";
        }
    }
}

char shift_char(char c, int shift) {
    if (c == ' ') {
        return c;
    }
    const int base = c - 'a';
    int s = shift % 26;
    if (s < 0) {
        s += 26;
    }
    return 'a' + (base + s) % 26;
}

void validate_key(const std::string& key) {
    if (key.empty()) {
        throw "Q4JZL0";
    }
    for (size_t i = 0; i < key.size(); ++i) {
        if (key[i] < 'a' || key[i] > 'z') {
            throw "Q4JZL0";
        }
    }
}


Cipher *CaesarCipher::clone() const {
    return new CaesarCipher(shift);
}

std::string CaesarCipher::decode(const std::string &ciphertext) {
    validate_text(ciphertext);
    std::string out = ciphertext;
    for (size_t i = 0; i < out.size(); ++i) {
        out[i] = shift_char(out[i], -shift);
    }
    return out;
}

std::string CaesarCipher::encode(const std::string &message) {
    validate_text(message);
    std::string out = message;
    for (size_t i = 0; i < out.size(); ++i) {
        out[i] = shift_char(out[i], shift);
    }
    return out;
}

CaesarCipher::~CaesarCipher() {}

Cipher *MyCipher::clone() const {
    return new MyCipher(key.c_str(), offset);
}

std::string MyCipher::decode(const std::string &ciphertext) {
    validate_key(key);
    validate_text(ciphertext);
    std::string out = ciphertext;
    const size_t key_len = key.size();
    for (size_t i = 0; i < out.size(); ++i) {
        int key_shift = key[i % key_len] - 'a';
        out[i] = shift_char(out[i], -(offset + i + key_shift));
    }
    return out;
}

std::string MyCipher::encode(const std::string &message) {
    validate_key(key);
    validate_text(message);
    std::string out = message;
    const size_t key_len = key.size();
    for (size_t i = 0; i < out.size(); ++i) {
        int key_shift = key[i % key_len] - 'a';
        out[i] = shift_char(out[i], offset + i + key_shift);
    }
    return out;
}

MyCipher::~MyCipher() {}

CipherQueue::CipherQueue(const CipherQueue& other) {
    for (size_t i = 0; i < other.ciphers.size(); ++i) {
        ciphers.push_back(other.ciphers[i]->clone());
    }
}

CipherQueue& CipherQueue::operator=(const CipherQueue& other) {
    if (this == &other) {
        return *this;
    }
    for (size_t i = 0; i < ciphers.size(); ++i) {
        delete ciphers[i];
    }
    ciphers.clear();
    for (size_t i = 0; i < other.ciphers.size(); ++i) {
        ciphers.push_back(other.ciphers[i]->clone());
    }
    return *this;
}

void CipherQueue::add(Cipher* cipher) {
    ciphers.push_back(cipher);
}

std::string CipherQueue::encode(const std::string &message) {
    std::string out = message;
    for (size_t i = 0; i < ciphers.size(); ++i) {
        out = ciphers[i]->encode(out);
    }
    return out;
}

std::string CipherQueue::decode(const std::string &ciphertext) {
    std::string out = ciphertext;
    for (size_t i = ciphers.size(); i > 0; --i) {
        out = ciphers[i - 1]->decode(out);
    }
    return out;
}

Cipher *CipherQueue::clone() const {
    return new CipherQueue(*this);
}

CipherQueue::~CipherQueue() {
    for (size_t i = 0; i < ciphers.size(); ++i) {
        delete ciphers[i];
    }
}

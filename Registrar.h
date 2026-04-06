//
// Created by user on 06/04/2026.
//

#ifndef TITKOSITO_REGISTRAR_H
#define TITKOSITO_REGISTRAR_H
#include <string>

#include "CipherFactory.h"

template <typename T>
struct Registrar {
    Registrar(const std::string& name) {
        CipherFactory::getInstance().registerCipher(name, [](const std::vector<std::string>& params) -> Cipher* { return new T(params); });
    }
};



#endif //TITKOSITO_REGISTRAR_H

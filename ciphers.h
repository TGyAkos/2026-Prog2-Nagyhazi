/**
 * \file ciphers.h
 *
 * Ezt a fájlt be kell adni (fel kell tölteni) a megoldással.
 */

#ifndef CipherS_H
#define CipherS_H

#include <string>
#include <vector>
#include "memtrace.h"

/**
 * Az ős osztály interfésze
 */ 
class Cipher {
public:
    /**
     * Titkosítja a kapott stringet
     * @param   message titkosítandó üzenet
     * @return  a message szöveg titkosított változata
     */
    virtual std::string encode(const std::string& message) = 0;
    /**
     * Dekódolja a kapott stringet
     * @param   ciphertext titkosított üzenet
     * @return  a megfejtett nyílt szöveg
     */
    virtual std::string decode(const std::string& ciphertext) = 0;
    /**
     * Létrehoz egy másolatot dinamikusan
     * @return  a létrehozott objektumra mutató pointer
     */
    virtual Cipher* clone() const = 0;
    /**
     * Alap destruktor
     */ 
    virtual ~Cipher() { };
};

//Osztályok, amiket meg kell csinálni a leírások és az osztálydiagram alapján
class CaesarCipher : public Cipher {
  int shift;
public:
  CaesarCipher(int shift) : shift(shift) {}
  Cipher *clone() const override;
  std::string decode(const std::string &ciphertext) override;
  std::string encode(const std::string &message) override;
  ~CaesarCipher() override;
};

class MyCipher : public Cipher {
  std::string key;
  int offset;
public:
  MyCipher(const char* key) : key(key), offset(0) {}
  MyCipher(const char* key, int offset) : key(key), offset(offset) {}
  Cipher *clone() const override;
  std::string decode(const std::string &ciphertext) override;
  std::string encode(const std::string &message) override;
  ~MyCipher() override;
};

class CipherQueue : public Cipher {
  std::vector<Cipher*> ciphers;
public:
  CipherQueue() {}
  CipherQueue(const CipherQueue& other);
  CipherQueue& operator=(const CipherQueue& other);
  void add(Cipher* cipher);
  std::string encode(const std::string &message) override;
  std::string decode(const std::string &ciphertext) override;
  Cipher *clone() const override;
  ~CipherQueue() override;
};

#endif
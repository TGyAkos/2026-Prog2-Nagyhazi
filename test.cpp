/**
 * \file test.cpp
 *
 * Cipher nevű szorgalmi feladat tesztjei gtest_lite eszközeivel megvalósítva
 * A szorgalmi feladat megoldásához ezt az állományt nem kell beadni (feltölteni).
 *
 */

#ifndef TITKOSITO_TEST_H
#define TITKOSITO_TEST_H

#include <iostream>
#include <ctime>

#include "CaesarCipher.h"
#include "CipherList.h"
#include "MyCipher.h"
#include "gtest_lite.h"
#include "memtrace.h"

void tests() {
    GTINIT(std::cin);
        //Caesar titkosítás ellenőrzése
        TEST(Caesar shift=4, _alma) {
            CaesarCipher cc(4);
            std::string alma = cc.encode("alma");
            EXPECT_STREQ("epqe", alma.c_str());
            std::string almacr = cc.decode(alma);
            EXPECT_STREQ("alma", almacr.c_str());
        } END

        TEST(Caesar shift=3, _uvwxyz) {
            CaesarCipher cc(3);
            std::string a = cc.encode("uvwxyz");
            EXPECT_STREQ("xyzabc", a.c_str());
            std::string b = cc.decode(a);
            EXPECT_STREQ("uvwxyz", b.c_str());
        } END

        TEST(Caesar shift=-10, _caesar) {
            CaesarCipher cc(-10);
            std::string a = cc.encode("caesar");
            EXPECT_STREQ("squiqh", a.c_str());
            std::string b = cc.decode(a);
            EXPECT_STREQ("caesar", b.c_str());
        } END

        TEST(Caesar shift=1000, _caesar) {
            CaesarCipher cc(1000);
            std::string a = cc.encode("caesar");
            EXPECT_STREQ("omqemd", a.c_str());
            std::string b = cc.decode(a);
            EXPECT_STREQ("caesar", b.c_str());
        } END

        TEST(Caesar shift=10, _ez egy uzenet) {
            CaesarCipher cc(10);
            const std::string str = "ez egy uzenet";
            std::string a = cc.encode(str);
            EXPECT_STREQ("oj oqi ejoxod", a.c_str());
            std::string b = cc.decode(a);
            EXPECT_STREQ("ez egy uzenet", b.c_str());
        } END

        TEST(My_Cipher key=abc counter=0, _titkositas) {
            MyCipher mc("abc");
            std::string a = mc.encode("titkositas");
            EXPECT_STREQ("tkxntzobkb", a.c_str());
            std::string b = mc.decode(a);
            EXPECT_STREQ("titkositas", b.c_str());
        } END

    //My cipher tesztek
        TEST(const My_Cipher key=cipher counter=10, _titkositas) {
            const MyCipher mc("cipher", 10);
            Cipher * const clone = mc.clone();
            std::string a = clone->encode("titkositas");
            EXPECT_STREQ("fbuegyashs", a.c_str());
            std::string b = clone->decode(a);
            EXPECT_STREQ("titkositas", b.c_str());
            delete clone;
        } END

        TEST(My_Cipher key=xyz counter=-3, _virtualis destruktor) {
            MyCipher mc("xyz", -3);
            std::string a = mc.encode("virtualis destruktor");
            EXPECT_STREQ("pepqtblkw ilybbdvgaf", a.c_str());
            std::string b = mc.decode(a);
            EXPECT_STREQ("virtualis destruktor", b.c_str());
        } END

    //CipherList tesztek
        TEST(Cipher_List: caesar + mycipher, _meg tobb szorgalmit prog2bol) {
            CipherList List;
            const CaesarCipher caesar(6);
            const MyCipher myCipher("abc", -2);
            List.addCipher(caesar.clone());
            List.addCipher(myCipher.clone());
            std::string str1 = List.encode("meg tobb szorgalmit progkettobol");
            EXPECT_STREQ("qko czln fofhyuehfp pqpjmizyvkwv", str1.c_str());
            std::string str2 = List.decode(str1);
            EXPECT_STREQ("meg tobb szorgalmit progkettobol", str2.c_str());
        } END

    CipherList List; //kell majd a következőkhöz is
        TEST(Cipher_List: inner List, _pointert mindenhova_alfa) {
            CipherList inner;
            inner.addCipher(new MyCipher("List"));
            inner.addCipher(new CaesarCipher(10));
            List += inner; //teszteli az operator+=-t is
            List += List; //ennek sem kellene gondot okoznia
            std::string str1 = List.encode("pointert mindenhova");
            EXPECT_STREQ("taqzfyhn ogpfotryno", str1.c_str());
            std::string str2 = List.decode(str1);
            EXPECT_STREQ("pointert mindenhova", str2.c_str());
        } END

        TEST(Cipher_List: inner List, _pointert mindenhova_beta) {
            std::srand(std::time(nullptr));
            CipherList inner;
            inner.addCipher(new MyCipher("List"));
            inner.addCipher(new CaesarCipher(std::rand() % 26));
            List += inner; //teszteli az operator+=-t is
            List += List; //ennek sem kellene gondot okoznia
            std::string str = List.decode(List.encode("pointert mindenhova"));
            EXPECT_STREQ("pointert mindenhova", str.c_str());
        } END


        //Neptun ellenőrzése
        TEST(Kivetelek, Caesar/MyCipher) {
            MyCipher mc("a");
            try {
                EXPECT_THROW_THROW(mc.encode("_"), std::runtime_error&);
            } catch (std::runtime_error &e) {
            }
        } END

    GTEND(std::cerr);
}

#endif // TITKOSITO_TEST_H
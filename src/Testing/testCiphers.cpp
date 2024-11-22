//! Unit Tests for MPAGSCipher VigenereCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <map>
#include <string>

#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include "CipherMode.hpp"
#include "CipherType.hpp"


std::map<CipherType, std::string> plainText{
    {CipherType::Caesar, "HELLOWORLD"},
    {CipherType::Playfair, "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ"},
    {CipherType::Vigenere, "THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES"}
};

std::map<CipherType, std::string> cipherText{
    {CipherType::Caesar, "ROVVYGYBVN"},
    {CipherType::Playfair, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA"},
    {CipherType::Vigenere, "ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ"}
};




bool testCipher (const Cipher& cipher, const CipherMode cipherMode, const std::string& inputText, const std::string& outputText){

    return cipher.applyCipher(inputText, cipherMode) == outputText;
}

TEST_CASE("Cipher encryption", "[ciphers]") {
    CaesarCipher cc{10};
    VigenereCipher vc{"hello"};
    PlayfairCipher pc{"hello"};

    REQUIRE(testCipher(cc,CipherMode::Encrypt, plainText[CipherType::Caesar], cipherText[CipherType::Caesar]));
    REQUIRE(testCipher(vc,CipherMode::Encrypt, plainText[CipherType::Vigenere], cipherText[CipherType::Vigenere]));
    REQUIRE(testCipher(pc,CipherMode::Encrypt, plainText[CipherType::Playfair], cipherText[CipherType::Playfair]));
}

TEST_CASE("Cipher decryption", "[ciphers]") {
    CaesarCipher cc{10};
    VigenereCipher vc{"hello"};
    PlayfairCipher pc{"hello"};

    REQUIRE(testCipher(cc,CipherMode::Decrypt, plainText[CipherType::Caesar], cipherText[CipherType::Caesar]));
    REQUIRE(testCipher(vc,CipherMode::Decrypt, plainText[CipherType::Vigenere], cipherText[CipherType::Vigenere]));
    REQUIRE(testCipher(pc,CipherMode::Decrypt, plainText[CipherType::Playfair], cipherText[CipherType::Playfair]));
}
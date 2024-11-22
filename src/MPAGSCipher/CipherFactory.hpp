#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP

#include "Cipher.hpp"
#include <memory>


enum class CipherType { Caesar, PLayfair, Vigenere};

namespace CipherFactory {

    std::unique_ptr<Cipher> makeCipher(const CipherType cipherType, const int )
}


#endif 
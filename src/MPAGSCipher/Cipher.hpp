#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

#include <string>
#include "CipherMode.hpp"

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the pure Abstract Base Class Cipher.
 */

/** \class Cipher
 * \brief a pure abstract base class for ciphers
 */
class Cipher{
    public:
        Cipher() = default;
        Cipher(const Cipher& rhs) = default;
        Cipher(Cipher&& rhs) = default;
        Cipher& operator=(const Cipher& rhs) = default;
        Cipher& operator=(Cipher&& rhs) = default;
        virtual ~Cipher() = default;

    /// pure virtual member function applyCipher
    virtual std::string applyCipher( const std::string& input, const CipherMode cipherMode) const = 0;
};



#endif 
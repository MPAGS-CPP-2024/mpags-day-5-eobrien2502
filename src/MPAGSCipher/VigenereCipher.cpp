#include "VigenereCipher.hpp"
#include "Alphabet.hpp"
//#include "CaesarCipher.hpp"

#include <algorithm>
#include <string>
#include <iostream>



VigenereCipher::VigenereCipher(const std::string& key)
{
    this->setKey(key);
}

void VigenereCipher::setKey(const std::string& key)
{
    // Store the original key
    key_ = key;

    // Make sure the key is uppercase
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                   ::toupper);

    // Remove non alphabetic characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_),
                              [](char c) { return !std::isalpha(c); }),
               std::end(key_));

    // Check if the key is empty and replace with a default key if so
    if (key_.empty()){
        // if the key is empty, replace with the default key whcih will be KEY
        key_ = "VIGENEREEXAMPLE";
        std::cerr << "[warning] key provided to VigenereCipher is empty, setting it to the default:" << key_ << std::endl;
            
    }

    //loop over the key
    charLookup_.clear();
    for (const char letter : key){
        if (charLookup_.find(letter) != charLookup_.end()){
            continue;
        }
    
    // getting the position of the letter from the key in the alphabet
    const std::size_t index{Alphabet::alphabet.find(letter)};

    // giving this letter and the number i to the char and caesar cipher things that make up the map.
    charLookup_.emplace(std::piecewise_construct, std::make_tuple(letter), std::make_tuple(index));
    }


}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode cipherMode) const {

    const std::size_t inputSize{inputText.size()};
    const std::size_t keySize{key_.size()};

    
    std::string outputText{""};
    outputText.reserve(inputSize);

    // For each letter in input:    
    for (std::size_t i{0}; i < inputSize; ++i){
        // Find the corresponding letter in the key

        const char keyChar{key_[i%keySize]};

        // Find the Casear Cipher from the lookup
        const CaesarCipher& cipher{charLookup_.at(keyChar)};

        // Run the encryption/decryption
        const std::string oldChar{inputText[i]};
        // Add the result to the output
        outputText+= cipher.applyCipher(oldChar, cipherMode);


    }

        
    return outputText;
}
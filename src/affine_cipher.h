#ifndef AFFINE_CIPHER_H
#define AFFINE_CIPHER_H

#include <string>

/**
 * @brief Вычисляет наибольший общий делитель (НОД)
 */
int gcd(int a, int b);

/**
 * @class AffineCipher
 * @brief Аффинный шифр с поддержкой русского и английского алфавита
 */
class AffineCipher {
    int a;               // ключ a
    int b;               // ключ b
    std::wstring alphabet;
    int m;               // размер алфавита

    int modInverse(int a, int m) const;
    int charToInt(wchar_t c) const;
    wchar_t intToChar(int i) const;

public:
    AffineCipher(int a_, int b_, const std::wstring& alph);

    std::wstring encrypt(const std::wstring& text);
    std::wstring decrypt(const std::wstring& text);
};

#endif // AFFINE_CIPHER_H

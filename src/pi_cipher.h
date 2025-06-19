#ifndef PI_CIPHER_H
#define PI_CIPHER_H

#include <string>
#include <unordered_map>

/**
 * @class PiCipher
 * @brief Класс для шифрования и дешифрования текста по методу Pi Cipher.
 */
class PiCipher {
public:
    static void build_codebooks(
        int key,
        const std::wstring& alphabet,
        std::unordered_map<wchar_t, std::wstring>& enc_map,
        std::unordered_map<std::wstring, wchar_t>& dec_map);

    static std::wstring encrypt(
        const std::wstring& text,
        const std::unordered_map<wchar_t, std::wstring>& enc_map);

    static std::wstring decrypt(
        const std::wstring& cipher,
        const std::unordered_map<std::wstring, wchar_t>& dec_map);
};

#endif // PI_CIPHER_H

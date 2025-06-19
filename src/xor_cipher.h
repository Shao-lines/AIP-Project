#ifndef XOR_CIPHER_H
#define XOR_CIPHER_H

#include <string>
#include <vector>

/**
 * @class XORCipher
 * @brief Класс для шифрования/дешифрования текста методом XOR
 *
 * Поддерживает русский и английский алфавиты, преобразование в HEX-формат,
 * проверку корректности вводимых данных.
 */
class XORCipher {
private:
    std::vector<wchar_t> key;   ///< Вектор символов ключа
    std::wstring alphabet;      ///< Используемый алфавит

    void validateKey(const std::wstring& k);
    void validateText(const std::wstring& text);
    std::vector<wchar_t> stringToWide(const std::wstring& str);
    wchar_t hexToChar(wchar_t h);
    std::wstring xorProcess(const std::wstring& input);

public:
    XORCipher(const std::wstring& k, const std::wstring& alph);
    std::wstring encrypt(const std::wstring& text);
    std::wstring encryptToHex(const std::wstring& text);
    std::wstring decryptFromHex(const std::wstring& hex);
};

#endif // XOR_CIPHER_H

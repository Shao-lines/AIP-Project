#include "gronsfeld_cipher.h"
#include <cmath>
#include <stdexcept>

/**
 * @brief Конструктор.
 * Инициализирует ключ и алфавит, нормализует ключ и проверяет корректность.
 */
GronsfeldCipher::GronsfeldCipher(const std::vector<int>& k, const std::wstring& alph)
    : key(k), alphabet(alph) {
    if (alphabet.empty()) {
        throw std::invalid_argument("Alphabet must not be empty.");
    }
    if (key.empty()) {
        throw std::invalid_argument("Key must not be empty.");
    }
    normalizeKey();
    validateKey();
}

/**
 * @brief Нормализует ключ по длине алфавита.
 */
void GronsfeldCipher::normalizeKey() {
    for (int& num : key) {
        num = std::abs(num) % alphabet.size();
    }
}

/**
 * @brief Проверяет корректность ключа после нормализации.
 */
void GronsfeldCipher::validateKey() {
    for (int num : key) {
        if (num < 0 || num >= static_cast<int>(alphabet.size())) {
            throw std::invalid_argument("Key digit is out of valid range.");
        }
    }
}

/**
 * @brief Создает полный повторённый ключ, соответствующий длине текста.
 * @param length Длина текста.
 * @return Повторённый ключ.
 */
std::vector<int> GronsfeldCipher::createFullKey(size_t length) const {
    std::vector<int> fullKey(length);
    for (size_t i = 0; i < length; ++i) {
        fullKey[i] = key[i % key.size()];
    }
    return fullKey;
}

/**
 * @brief Выполняет шифрование или дешифрование текста.
 * Символы, не входящие в алфавит, не изменяются.
 * 
 * @param text Входной текст.
 * @param encrypt true - шифрование, false - дешифрование.
 * @return Результат обработки.
 */
std::wstring GronsfeldCipher::process(const std::wstring& text, bool encrypt) {
    if (text.empty()) {
        return L"";
    }

    std::wstring result;
    std::vector<int> fullKey = createFullKey(text.size());

    for (size_t i = 0; i < text.size(); ++i) {
        wchar_t c = text[i];
        size_t pos = alphabet.find(c);
        if (pos != std::wstring::npos) {
            int shift = fullKey[i] * (encrypt ? 1 : -1);
            pos = (pos + shift + alphabet.size()) % alphabet.size();
            result += alphabet[pos];
        } else {
            result += c;
        }
    }
    return result;
}

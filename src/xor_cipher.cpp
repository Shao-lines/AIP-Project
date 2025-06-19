/**
 * @file xor_cipher.cpp
 * @brief Реализация класса XORCipher для шифрования и дешифрования методом XOR с поддержкой Unicode и HEX.
 */

#include "xor_cipher.h"
#include <stdexcept>
#include <cwctype> ///< Для towupper
#include <algorithm>

using namespace std;

/**
 * @brief Конструктор класса XORCipher.
 *
 * Инициализирует объект шифра с заданным ключом и алфавитом.
 * Проверяет корректность ключа и сохраняет его в виде вектора символов.
 *
 * @param k Ключ шифрования.
 * @param alph Алфавит, используемый для проверки символов.
 * @throw std::runtime_error Если ключ некорректен.
 */
XORCipher::XORCipher(const wstring& k, const wstring& alph) : alphabet(alph) {
    validateKey(k);
    key = stringToWide(k);
}

/**
 * @brief Проверяет ключ на пустоту и допустимость символов.
 *
 * Ключ должен состоять только из символов алфавита или пробелов.
 *
 * @param k Ключ для проверки.
 * @throw std::runtime_error Если ключ пуст или содержит недопустимые символы.
 */
void XORCipher::validateKey(const wstring& k) {
    if (k.empty()) {
        throw runtime_error("Ключ не может быть пустым");
    }
    for (wchar_t c : k) {
        if (alphabet.find(c) == wstring::npos && c != L' ') {
            throw runtime_error("Ключ содержит символы не из алфавита");
        }
    }
}

/**
 * @brief Проверяет текст на соответствие алфавиту.
 *
 * Текст должен состоять только из символов алфавита или пробелов.
 *
 * @param text Текст для проверки.
 * @throw std::runtime_error Если текст содержит недопустимые символы.
 */
void XORCipher::validateText(const wstring& text) {
    for (wchar_t c : text) {
        if (alphabet.find(c) == wstring::npos && c != L' ') {
            throw runtime_error("Текст содержит символы не из алфавита");
        }
    }
}

/**
 * @brief Преобразует строку в вектор символов.
 *
 * @param str Входная строка.
 * @return Вектор символов строки.
 */
vector<wchar_t> XORCipher::stringToWide(const wstring& str) {
    return vector<wchar_t>(str.begin(), str.end());
}

/**
 * @brief Конвертирует один HEX-символ в число.
 *
 * Поддерживаются цифры 0-9 и буквы A-F (регистр не имеет значения).
 *
 * @param h HEX-символ.
 * @return Числовое значение символа.
 * @throw std::runtime_error Если символ не является допустимой HEX-цифрой.
 */
wchar_t XORCipher::hexToChar(wchar_t h) {
    if (h >= L'0' && h <= L'9') return h - L'0';
    if (h >= L'A' && h <= L'F') return h - L'A' + 10;
    if (h >= L'a' && h <= L'f') return h - L'a' + 10;
    throw runtime_error("Некорректный HEX-символ");
}

/**
 * @brief Выполняет XOR-шифрование или дешифрование текста.
 *
 * Каждый символ входного текста XOR-ится с соответствующим символом ключа.
 * Пробелы остаются без изменений.
 *
 * @param input Входной текст.
 * @return Результат XOR-операции.
 */
wstring XORCipher::xorProcess(const wstring& input) {
    vector<wchar_t> result;
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == L' ') {
            result.push_back(L' ');
        } else {
            result.push_back(input[i] ^ key[i % key.size()]);
        }
    }
    return wstring(result.begin(), result.end());
}

/**
 * @brief Шифрует текст методом XOR.
 *
 * Выполняет проверку текста и применяет XOR-шифрование.
 *
 * @param text Текст для шифрования.
 * @return Зашифрованный текст.
 * @throw std::runtime_error Если текст содержит недопустимые символы.
 */
wstring XORCipher::encrypt(const wstring& text) {
    validateText(text);
    return xorProcess(text);
}

/**
 * @brief Шифрует текст методом XOR и возвращает результат в HEX-формате.
 *
 * Каждый байт результата конвертируется в пару HEX-символов.
 *
 * @param text Текст для шифрования.
 * @return HEX-строка с пробелами между байтами.
 */
wstring XORCipher::encryptToHex(const wstring& text) {
    wstring encrypted = encrypt(text);
    wstring result;
    const wchar_t hex[] = L"0123456789ABCDEF";

    for (wchar_t c : encrypted) {
        result += hex[(c >> 4) & 0x0F];
        result += hex[c & 0x0F];
        result += L' ';
    }
    return result;
}

/**
 * @brief Дешифрует строку из HEX-формата обратно в исходный текст.
 *
 * Удаляет пробелы и недопустимые символы, преобразует HEX в байты,
 * затем выполняет XOR-дешифрование.
 *
 * @param hex HEX-строка (можно с пробелами).
 * @return Расшифрованный текст.
 * @throw std::runtime_error Если строка имеет некорректный HEX-формат.
 */
wstring XORCipher::decryptFromHex(const wstring& hex) {
    vector<wchar_t> bytes;
    wstring cleanHex;

    for (wchar_t c : hex) {
        if ((c >= L'0' && c <= L'9') ||
            (c >= L'A' && c <= L'F') ||
            (c >= L'a' && c <= L'f')) {
            cleanHex += towupper(c);
        }
    }

    if (cleanHex.size() % 2 != 0) {
        throw runtime_error("Некорректная длина HEX-строки");
    }

    for (size_t i = 0; i + 1 < cleanHex.size(); i += 2) {
        wchar_t high = hexToChar(cleanHex[i]);
        wchar_t low = hexToChar(cleanHex[i + 1]);
        bytes.push_back((high << 4) | low);
    }

    return xorProcess(wstring(bytes.begin(), bytes.end()));
}

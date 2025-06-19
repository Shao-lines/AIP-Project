/**
 * @file affine_cipher.cpp
 * @brief Реализация класса AffineCipher для шифрования и дешифрования текста аффинным шифром
 * @author 
 * @date 
 */

#include "affine_cipher.h"
#include <stdexcept>
#include <cwctype> ///< Для towupper

/**
 * @brief Вычисляет наибольший общий делитель (НОД) двух чисел.
 * 
 * Используется для проверки взаимной простоты ключа a и длины алфавита.
 *
 * @param a Первое целое число.
 * @param b Второе целое число.
 * @return НОД чисел a и b.
 */
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

/**
 * @brief Конструктор класса AffineCipher.
 *
 * Инициализирует объект с заданными ключами a и b, а также выбранным алфавитом.
 * Проверяет условие взаимной простоты ключа a и длины алфавита.
 *
 * @param a_ Ключ a (множитель).
 * @param b_ Ключ b (сдвиг).
 * @param alph Алфавит, используемый для шифрования.
 * @throw std::invalid_argument Если ключ a не взаимно прост с длиной алфавита.
 */
AffineCipher::AffineCipher(int a_, int b_, const std::wstring& alph)
    : a(a_), b(b_), alphabet(alph) {
    m = static_cast<int>(alphabet.size());
    if (gcd(a, m) != 1)
        throw std::invalid_argument("Key 'a' and alphabet length must be coprime.");
}

/**
 * @brief Вычисляет модульный обратный элемент для заданного числа по модулю.
 *
 * Используется для дешифрования аффинного шифра.
 *
 * @param a Число, для которого вычисляется обратный элемент.
 * @param m Модуль.
 * @return Обратный элемент a^(-1) mod m.
 * @throw std::invalid_argument Если обратного элемента не существует.
 */
int AffineCipher::modInverse(int a, int m) const {
    int m0 = m, x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m; a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

/**
 * @brief Преобразует символ в индекс в алфавите.
 *
 * Если символ не найден в алфавите, возвращает -1.
 *
 * @param c Символ для поиска.
 * @return Индекс символа или -1, если символ не найден.
 */
int AffineCipher::charToInt(wchar_t c) const {
    for (int i = 0; i < m; ++i) {
        if (alphabet[i] == c) return i;
    }
    return -1;
}

/**
 * @brief Преобразует индекс в символ алфавита.
 *
 * @param i Индекс символа.
 * @return Соответствующий символ алфавита.
 */
wchar_t AffineCipher::intToChar(int i) const {
    return alphabet[i];
}

/**
 * @brief Шифрует текст с использованием аффинного шифра.
 *
 * Формула шифрования: E(x) = (a * x + b) mod m.
 * Пробелы и символы, не входящие в алфавит, сохраняются без изменений.
 *
 * @param text Исходный текст для шифрования.
 * @return Зашифрованный текст.
 */
std::wstring AffineCipher::encrypt(const std::wstring& text) {
    std::wstring result;
    for (wchar_t c : text) {
        if (c == L' ') {
            result += L' ';
            continue;
        }
        int index = charToInt(towupper(c));
        if (index == -1) {
            result += c;
        } else {
            int encrypted = (a * index + b) % m;
            result += intToChar(encrypted);
        }
    }
    return result;
}

/**
 * @brief Дешифрует текст, зашифрованный аффинным шифром.
 *
 * Формула дешифрования: D(x) = a^(-1) * (x - b) mod m.
 * Пробелы и символы, не входящие в алфавит, сохраняются без изменений.
 *
 * @param text Зашифрованный текст для дешифрования.
 * @return Расшифрованный текст.
 */
std::wstring AffineCipher::decrypt(const std::wstring& text) {
    std::wstring result;
    int a_inv = modInverse(a, m);
    for (wchar_t c : text) {
        if (c == L' ') {
            result += L' ';
            continue;
        }
        int index = charToInt(towupper(c));
        if (index == -1) {
            result += c;
        } else {
            int decrypted = (a_inv * (index - b + m)) % m;
            result += intToChar(decrypted);
        }
    }
    return result;
}

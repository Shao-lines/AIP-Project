/**
 * @file reverser_cipher.h
 * @brief Заголовочный файл для класса ReverserCipher.
 */

#pragma once

#include <string>

/**
 * @class ReverserCipher
 * @brief Класс для шифрования и дешифрования текста методом реверса по блокам с поддержкой уменьшения размера блока.
 */
class ReverserCipher {
public:
    /**
     * @brief Шифрует текст методом реверса по блокам.
     * @param text Исходный текст.
     * @param block_size Размер блока.
     * @param shrinking Если true — блоки уменьшаются.
     * @return Зашифрованный текст.
     */
    static std::wstring encrypt(const std::wstring& text, int block_size, bool shrinking);

    /**
     * @brief Дешифрует текст, зашифрованный методом реверса по блокам.
     * @param text Зашифрованный текст.
     * @param block_size Размер блока.
     * @param shrinking Если true — блоки уменьшались.
     * @return Расшифрованный текст.
     */
    static std::wstring decrypt(const std::wstring& text, int block_size, bool shrinking);

private:
    /**
     * @brief Выполняет реверс блока символов.
     * @param result Строка для реверса.
     * @param start Начало блока.
     * @param end Конец блока (не включительно).
     */
    static void reverse_block(std::wstring& result, size_t start, size_t end);
};

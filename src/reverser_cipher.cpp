/**
 * @file reverser_cipher.cpp
 * @brief Реализация класса ReverserCipher для шифрования и дешифрования методом реверса по блокам.
 * @author 
 * @date 
 */

#include "reverser_cipher.h"
#include <algorithm>
#include <vector>

/**
 * @class ReverserCipher
 * @brief Класс для шифрования и дешифрования текста методом реверса по блокам с возможностью уменьшения размера блока.
 */

/**
 * @brief Выполняет реверс блока символов внутри строки.
 *
 * Разворачивает символы на интервале [start, end) в строке result.
 *
 * @param result Строка, в которой выполняется реверс.
 * @param start Индекс начала блока.
 * @param end Индекс конца блока (не включительно).
 */
void ReverserCipher::reverse_block(std::wstring& result, size_t start, size_t end) {
    size_t left = start, right = end - 1;
    while (left < right) {
        std::swap(result[left], result[right]);
        ++left;
        --right;
    }
}

/**
 * @brief Шифрует текст методом реверса по блокам.
 *
 * Текст разбивается на блоки фиксированного размера. Каждый блок инвертируется.
 * Если включён режим уменьшения, размер блока уменьшается на 1 после каждого шага,
 * но не может быть меньше 2.
 *
 * @param text Исходный текст для шифрования.
 * @param block_size Начальный размер блока.
 * @param shrinking true — блоки уменьшаются, false — размер фиксирован.
 * @return Зашифрованный текст.
 */
std::wstring ReverserCipher::encrypt(const std::wstring& text, int block_size, bool shrinking) {
    std::wstring result = text;
    size_t len = text.size();
    size_t i = 0;
    int cur_block = block_size;

    while (i < len) {
        size_t end = std::min(i + static_cast<size_t>(cur_block), len);
        reverse_block(result, i, end);
        i += cur_block;

        if (shrinking && cur_block > 2) {
            --cur_block;
            if (cur_block < 2) cur_block = 2;
        }
    }
    return result;
}

/**
 * @brief Дешифрует текст, зашифрованный методом реверса по блокам.
 *
 * Для правильного восстановления текста блоки реверсируются в обратном порядке,
 * с использованием той же последовательности длин, что была при шифровании.
 *
 * @param text Зашифрованный текст.
 * @param block_size Начальный размер блока.
 * @param shrinking true — блоки уменьшались при шифровании, false — размер фиксирован.
 * @return Расшифрованный текст.
 */
std::wstring ReverserCipher::decrypt(const std::wstring& text, int block_size, bool shrinking) {
    std::vector<int> blocks;
    size_t len = text.size();
    int cur_block = block_size;
    size_t i = 0;

    // Формируем последовательность длин блоков
    while (i < len) {
        int this_block = std::min(cur_block, static_cast<int>(len - i));
        blocks.push_back(this_block);
        i += this_block;

        if (shrinking && cur_block > 2) {
            --cur_block;
            if (cur_block < 2) cur_block = 2;
        }
    }

    // Реверсируем блоки в обратном порядке
    std::wstring result = text;
    size_t pos = len;

    for (auto it = blocks.rbegin(); it != blocks.rend(); ++it) {
        pos -= *it;
        reverse_block(result, pos, pos + *it);
    }

    return result;
}

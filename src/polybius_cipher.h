/**
 * @file polybius_cipher.h
 * @brief Заголовочный файл для класса PolybiusCipher (шифр Polybius).
 */

#pragma once

#include <vector>
#include <string>

/**
 * @class PolybiusCipher
 * @brief Класс для шифрования и дешифрования текста методом Polybius с доской 8x8.
 */
class PolybiusCipher {
public:
    /**
     * @brief Построение матрицы Polybius 8x8 с циклическим сдвигом алфавита.
     * @param alphabet Алфавит.
     * @param key Ключ-сдвиг (по модулю 64).
     * @return Матрица 8x8.
     */
    static std::vector<std::vector<wchar_t>> build_board(const std::wstring& alphabet, int key);

    /**
     * @brief Шифрование текста.
     * @param text Открытый текст.
     * @param board Матрица 8x8.
     * @return Зашифрованный текст.
     */
    static std::wstring encrypt(const std::wstring& text, const std::vector<std::vector<wchar_t>>& board);

    /**
     * @brief Дешифрование текста.
     * @param code Зашифрованный текст.
     * @param board Матрица 8x8.
     * @return Расшифрованный текст.
     */
    static std::wstring decrypt(const std::wstring& code, const std::vector<std::vector<wchar_t>>& board);

private:
    /**
     * @brief Поиск координат символа на доске.
     * @param board Матрица 8x8.
     * @param c Символ.
     * @return Координаты или (-1, -1).
     */
    static std::pair<int, int> find_coords(const std::vector<std::vector<wchar_t>>& board, wchar_t c);
};

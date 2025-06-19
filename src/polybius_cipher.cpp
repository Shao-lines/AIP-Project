/**
 * @file polybius_cipher.cpp
 * @brief Реализация класса PolybiusCipher для шифрования и дешифрования текста методом Polybius.
 */

#include "polybius_cipher.h"
#include <cwctype>

/**
 * @brief Построение матрицы Polybius размером 8x8 на основе алфавита и ключа.
 */
std::vector<std::vector<wchar_t>> PolybiusCipher::build_board(const std::wstring& alphabet, int key) {
    std::vector<std::vector<wchar_t>> board(8, std::vector<wchar_t>(8, L' '));
    std::vector<wchar_t> full_alpha(64, L' ');

    key %= 64;
    int n = alphabet.size();

    for (int i = 0; i < n; ++i)
        full_alpha[(i + key) % 64] = alphabet[i];

    for (int i = 0; i < 64; ++i)
        board[i / 8][i % 8] = full_alpha[i];

    return board;
}

/**
 * @brief Поиск координат символа.
 */
std::pair<int, int> PolybiusCipher::find_coords(const std::vector<std::vector<wchar_t>>& board, wchar_t c) {
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (board[row][col] == c) {
                return { row, col };
            }
        }
    }
    return { -1, -1 };
}

/**
 * @brief Шифрует текст.
 */
std::wstring PolybiusCipher::encrypt(const std::wstring& text, const std::vector<std::vector<wchar_t>>& board) {
    std::wstring res;
    for (wchar_t c : text) {
        if (c == L' ' || c == L'\t' || c == L'\n') {
            res += L' ';
            continue;
        }

        c = std::towupper(c);
        auto coords = find_coords(board, c);
        if (coords.first == -1) continue;

        wchar_t col_letter = L'a' + coords.second;
        wchar_t row_digit = L'1' + coords.first;

        res += col_letter;
        res += row_digit;
    }
    return res;
}

/**
 * @brief Дешифрует текст.
 */
std::wstring PolybiusCipher::decrypt(const std::wstring& code, const std::vector<std::vector<wchar_t>>& board) {
    std::wstring res;
    size_t i = 0;
    while (i < code.size()) {
        if (code[i] == L' ' || code[i] == L'\t' || code[i] == L'\n') {
            res += L' ';
            ++i;
            continue;
        }

        if (i + 1 >= code.size()) break;

        int col = code[i] - L'a';
        int row = code[i + 1] - L'1';
        i += 2;

        if (row >= 0 && row < 8 && col >= 0 && col < 8) {
            res += board[row][col];
        }
    }
    return res;
}

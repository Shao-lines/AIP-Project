/**
 * @file turn_grid_cipher.cpp
 * @brief Реализация класса TurnGridCipher — шифра поворотной решётки с поддержкой Unicode.
 *
 * Класс TurnGridCipher выполняет шифрование или дешифрование текста с помощью квадратной решётки с отверстиями.
 * Решётка поворачивается по часовой стрелке четыре раза, при каждом повороте происходит вставка или чтение символов.
 */

#include "turn_grid_cipher.h"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <locale>

/**
 * @class TurnGridCipher
 * @brief Класс поворотного шифра решётки (Turning Grille Cipher).
 *
 * Работает с квадратной решёткой чётного размера. Позволяет шифровать и дешифровать текст.
 */

/**
 * @brief Конструктор. Задаёт размер решётки.
 * @param size Размер решётки (чётное число).
 * @throw std::invalid_argument Если размер нечётный.
 */
TurnGridCipher::TurnGridCipher(int size) : size_(size) {
    if (size_ % 2 != 0) {
        throw std::invalid_argument("Grille size must be even.");
    }
}

/**
 * @brief Шифрует или дешифрует текст.
 * @param text Входной текст.
 * @param encrypt true — шифровать, false — дешифровать.
 * @return Результат.
 */
std::wstring TurnGridCipher::process(const std::wstring& text, bool encrypt) {
    if (text.empty()) return L"";

    auto grille = createGrille();
    validateGrilleHoles(grille);

    std::vector<std::vector<wchar_t>> grid(size_, std::vector<wchar_t>(size_, L' '));
    size_t pos = 0;

    for (int rotation = 0; rotation < 4 && pos < text.size(); ++rotation) {
        for (int i = 0; i < size_; ++i) {
            for (int j = 0; j < size_; ++j) {
                if (grille[i][j] && pos < text.size()) {
                    grid[i][j] = text[pos++];
                }
            }
        }
        std::wcout << L"\n[Rotation " << rotation + 1 << L"]\n";
        printGrille(grille);
        printGrid(grid);
        rotateGrille(grille);
    }

    std::wstring result;
    for (int j = 0; j < size_; ++j) {
        for (int i = 0; i < size_; ++i) {
            if (grid[i][j] != L' ') {
                result += grid[i][j];
            }
        }
    }

    std::wcout << L"Final output: " << result << L"\n";
    return result;
}

// === Вспомогательные методы класса ===

std::vector<std::vector<bool>> TurnGridCipher::createGrille() const {
    std::vector<std::vector<bool>> grille(size_, std::vector<bool>(size_, false));

    if (size_ == 4) {
        grille[0][0] = true;
        grille[1][3] = true;
        grille[2][2] = true;
        grille[3][1] = true;
    } else {
        for (int i = 0; i < size_; i += 2) {
            grille[i][i] = true;
        }
    }
    return grille;
}

void TurnGridCipher::printGrille(const std::vector<std::vector<bool>>& grille) const {
    std::wcout << L"Grille state:\n";
    for (const auto& row : grille) {
        for (bool cell : row) {
            std::wcout << (cell ? L"1 " : L". ");
        }
        std::wcout << L"\n";
    }
    std::wcout << std::endl;
}

void TurnGridCipher::printGrid(const std::vector<std::vector<wchar_t>>& grid) const {
    std::wcout << L"Grid state:\n";
    for (const auto& row : grid) {
        for (wchar_t c : row) {
            std::wcout << (c == L' ' ? L". " : std::wstring(1, c) + L" ");
        }
        std::wcout << L"\n";
    }
    std::wcout << std::endl;
}

void TurnGridCipher::rotateGrille(std::vector<std::vector<bool>>& grille) const {
    const int n = grille.size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - i - 1; ++j) {
            bool temp = grille[i][j];
            grille[i][j] = grille[n-1-j][i];
            grille[n-1-j][i] = grille[n-1-i][n-1-j];
            grille[n-1-i][n-1-j] = grille[j][n-1-i];
            grille[j][n-1-i] = temp;
        }
    }
}

void TurnGridCipher::validateGrilleHoles(const std::vector<std::vector<bool>>& grille) const {
    int holeCount = 0;
    for (const auto& row : grille) {
        for (bool cell : row) {
            if (cell) holeCount++;
        }
    }
    int expected = (size_ * size_) / 4;
    if (holeCount != expected) {
        throw std::runtime_error("Grille hole count must be size^2 / 4.");
    }
}

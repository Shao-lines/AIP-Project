/**
 * @file rail_fence_cipher.cpp
 * @brief Реализация класса RailFenceCipher — шифра рельсовой погони (Rail Fence Cipher).
 *
 * Класс позволяет шифровать и дешифровать Unicode-тексты методом рельсовой погони.
 */

#include "rail_fence_cipher.h"
#include <vector>
#include <stdexcept>

/**
 * @brief Конструктор. Задаёт количество рельс.
 */
RailFenceCipher::RailFenceCipher(int rails) : rails_(rails) {
    if (rails_ <= 0) {
        throw std::invalid_argument("Number of rails must be positive");
    }
}

/**
 * @brief Шифрует текст методом рельсовой погони.
 */
std::wstring RailFenceCipher::encrypt(const std::wstring& text) const {
    if (rails_ == 1 || text.empty()) return text;

    std::vector<std::wstring> fence(rails_);
    int rail = 0;
    int direction = 1;

    for (wchar_t c : text) {
        fence[rail] += c;
        rail += direction;
        if (rail == rails_ - 1 || rail == 0) direction = -direction;
    }

    std::wstring encrypted;
    for (const auto& rail_str : fence) {
        encrypted += rail_str;
    }
    return encrypted;
}

/**
 * @brief Дешифрует текст, зашифрованный методом рельсовой погони.
 */
std::wstring RailFenceCipher::decrypt(const std::wstring& text) const {
    if (rails_ == 1 || text.empty()) return text;

    std::vector<int> rail_indices(text.size());
    int rail = 0, direction = 1;
    for (size_t i = 0; i < text.size(); ++i) {
        rail_indices[i] = rail;
        rail += direction;
        if (rail == rails_ - 1 || rail == 0) direction = -direction;
    }

    std::vector<size_t> rail_lengths(rails_, 0);
    for (int r : rail_indices) {
        rail_lengths[r]++;
    }

    std::vector<std::wstring> fence(rails_);
    size_t pos = 0;
    for (int r = 0; r < rails_; ++r) {
        fence[r] = text.substr(pos, rail_lengths[r]);
        pos += rail_lengths[r];
    }

    std::wstring decrypted;
    rail = 0; direction = 1;
    std::vector<size_t> rail_positions(rails_, 0);

    for (size_t i = 0; i < text.size(); ++i) {
        decrypted += fence[rail][rail_positions[rail]++];
        rail += direction;
        if (rail == rails_ - 1 || rail == 0) direction = -direction;
    }

    return decrypted;
}

#ifndef RAIL_FENCE_CIPHER_H
#define RAIL_FENCE_CIPHER_H

#include <string>

/**
 * @class RailFenceCipher
 * @brief Класс для шифрования и дешифрования текста методом рельсовой погони (Rail Fence Cipher).
 *
 * Алгоритм реализует зигзагообразное распределение символов по рельсам
 * и их объединение в зашифрованный текст. Поддерживает Unicode (wchar_t).
 */
class RailFenceCipher {
public:
    /**
     * @brief Конструктор.
     * @param rails Количество рельс (должно быть положительным).
     * @throw std::invalid_argument Если rails <= 0.
     */
    explicit RailFenceCipher(int rails);

    /**
     * @brief Шифрует текст методом рельсовой погони.
     * @param text Исходный текст.
     * @return Зашифрованный текст.
     */
    std::wstring encrypt(const std::wstring& text) const;

    /**
     * @brief Дешифрует текст, зашифрованный методом рельсовой погони.
     * @param text Зашифрованный текст.
     * @return Расшифрованный текст.
     */
    std::wstring decrypt(const std::wstring& text) const;

private:
    int rails_;
};

#endif // RAIL_FENCE_CIPHER_H

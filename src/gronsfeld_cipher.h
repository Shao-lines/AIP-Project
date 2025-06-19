#ifndef GRONSFELD_CIPHER_H
#define GRONSFELD_CIPHER_H

#include <string>
#include <vector>

/**
 * @class GronsfeldCipher
 * @brief Класс для реализации шифра Гронсфельда с поддержкой Unicode алфавитов.
 */
class GronsfeldCipher {
private:
    std::vector<int> key;     ///< Числовой ключ шифрования
    std::wstring alphabet;    ///< Используемый алфавит

    /**
     * @brief Нормализует ключ по размеру алфавита.
     */
    void normalizeKey();

    /**
     * @brief Проверяет ключ на корректность после нормализации.
     */
    void validateKey();

    /**
     * @brief Генерирует повторённый ключ по длине текста.
     * @param length Длина текста.
     * @return Вектор повторённого ключа.
     */
    std::vector<int> createFullKey(size_t length) const;

public:
    /**
     * @brief Конструктор.
     * @param k Числовой ключ.
     * @param alph Алфавит.
     */
    GronsfeldCipher(const std::vector<int>& k, const std::wstring& alph);

    /**
     * @brief Шифрует или дешифрует текст.
     * @param text Входной текст.
     * @param encrypt true - шифрование, false - дешифрование.
     * @return Результат.
     */
    std::wstring process(const std::wstring& text, bool encrypt);
};

#endif // GRONSFELD_CIPHER_H

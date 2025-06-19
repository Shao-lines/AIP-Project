#ifndef VIGENERE_CIPHER_H
#define VIGENERE_CIPHER_H

#include <string>

/**
 * @class VigenereCipher
 * @brief Класс для шифрования и дешифрования текста методом Виженера с поддержкой русского алфавита (через wchar_t).
 *
 * Данный класс реализует классический шифр Виженера, который выполняет символьный сдвиг
 * в пределах алфавита. Для русских букв используется 32-буквенный алфавит (без 'Ё').
 *
 * Пример использования:
 * @code
 * VigenereCipher cipher(L"КЛЮЧ");
 * std::wstring encrypted = cipher.zasifrovat(L"ПРИМЕР ТЕКСТА");
 * std::wstring decrypted = cipher.rasshifrovat(encrypted);
 * @endcode
 */
class VigenereCipher {
public:
    /**
     * @brief Конструктор шифра Виженера.
     * 
     * Валидирует ключ и сохраняет его для последующего использования.
     *
     * @param klyuch Строка ключа (широкая строка).
     * @throw std::invalid_argument Если ключ пустой или содержит недопустимые символы.
     */
    explicit VigenereCipher(const std::wstring& klyuch);

    /**
     * @brief Шифрует открытый текст методом Виженера.
     *
     * @param tekst Исходный открытый текст (wchar_t).
     * @return Зашифрованный текст.
     */
    std::wstring zasifrovat(const std::wstring& tekst) const;

    /**
     * @brief Дешифрует шифр-текст, полученный методом Виженера.
     *
     * @param tekst Зашифрованный текст (wchar_t).
     * @return Расшифрованный текст.
     */
    std::wstring rasshifrovat(const std::wstring& tekst) const;

private:
    /**
     * @brief Внутренний метод для обработки текста.
     *
     * Выполняет символьный сдвиг в зависимости от режима шифрования.
     *
     * @param tekst Входной текст (wchar_t).
     * @param shifrovat true — шифровать, false — дешифровать.
     * @return Результат обработки.
     */
    std::wstring obrabotatTekst(const std::wstring& tekst, bool shifrovat) const;

    /**
     * @brief Сохраняемый ключ (wchar_t).
     */
    std::wstring klyuch_;
};

#endif // VIGENERE_CIPHER_H
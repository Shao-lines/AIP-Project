/**
 * @file vigenere_cipher.cpp
 * @brief Реализация шифра Виженера с поддержкой русского алфавита через wchar_t.
 */

#include "vigenere_cipher.h"
#include <stdexcept>
#include <cwctype> // для iswalpha, towupper
#include <iostream>
#include <string>

namespace
{
    constexpr wchar_t RUS_UPPER_A = L'А'; ///< Первая буква русского верхнего регистра.
    constexpr wchar_t RUS_LOWER_A = L'а'; ///< Первая буква русского нижнего регистра.
    constexpr int RUS_ALPHABET_SIZE = 32; ///< Размер русского алфавита (без Ё).

    /**
     * @brief Проверяет ключ на корректность.
     * @param klyuch Ключ.
     * @throw std::invalid_argument Если ключ пустой или содержит недопустимые символы.
     */
    void proveritKlyuch(const std::wstring &klyuch)
    {
        if (klyuch.empty())
        {
            throw std::invalid_argument("Ключ не может быть пустым");
        }
        for (wchar_t c : klyuch)
        {
            if (!iswalpha(c) && c != L' ')
            {
                throw std::invalid_argument("Ключ должен содержать только буквы и пробелы");
            }
        }
    }

    /**
     * @brief Шифрует или дешифрует одну букву.
     * @param bukva Символ текста.
     * @param bukvaKlyucha Символ ключа.
     * @param shifrovat true — шифровать, false — дешифровать.
     * @return Результат обработки буквы.
     */
    wchar_t obrabotatBukvu(wchar_t bukva, wchar_t bukvaKlyucha, bool shifrovat)
    {
        if (bukva == L' ' || !iswalpha(bukva))
            return bukva;

        wchar_t upper_a;
        int alphabet_size;

        // Определяем язык буквы (рус или англ)
        if ((bukva >= L'A' && bukva <= L'Z') || (bukva >= L'a' && bukva <= L'z'))
        {
            upper_a = iswupper(bukva) ? L'A' : L'a';
            alphabet_size = 26;
        }
        else if ((bukva >= L'А' && bukva <= L'Я') || (bukva >= L'а' && bukva <= L'я'))
        {
            upper_a = iswupper(bukva) ? L'А' : L'а';
            alphabet_size = 32;
        }
        else
        {
            return bukva; // не буква
        }

        // Для буквы ключа аналогично: используем регистр и алфавит буквы текста
        wchar_t key_upper_a = iswupper(bukvaKlyucha) ? upper_a : towlower(upper_a);
        int sdvig = towupper(bukvaKlyucha) - towupper(key_upper_a);
        if (!shifrovat)
            sdvig = -sdvig;

        int normSdvig = (bukva - upper_a + sdvig + alphabet_size) % alphabet_size;
        return static_cast<wchar_t>(normSdvig + upper_a);
    }

    /**
     * @brief Формирует строку-лозунг для вывода.
     * @param tekst Текст.
     * @param shifrovat true — открытый текст, false — шифр-текст.
     * @return Лозунг.
     */
    std::wstring sozdatLozung(const std::wstring &tekst, bool shifrovat)
    {
        if (tekst.empty())
            return L"";

        std::wstring lozung;
        if (shifrovat)
        {
            lozung = L"Открытый текст: ";
        }
        else
        {
            lozung = L"Шифр-текст: ";
        }

        if (tekst.length() > 20)
        {
            lozung += tekst.substr(0, 17) + L"...";
        }
        else
        {
            lozung += tekst;
        }

        return lozung;
    }
}

/**
 * @brief Конструктор шифра Виженера.
 * @param klyuch Ключ шифрования.
 * @throw std::invalid_argument Если ключ некорректен.
 */
VigenereCipher::VigenereCipher(const std::wstring &klyuch) : klyuch_(klyuch)
{
    proveritKlyuch(klyuch_);
}

/**
 * @brief Шифрует текст методом Виженера.
 * @param tekst Исходный текст.
 * @return Зашифрованная строка.
 */
std::wstring VigenereCipher::zasifrovat(const std::wstring &tekst) const
{
    std::wstring result = obrabotatTekst(tekst, true);
    std::wcout << sozdatLozung(tekst, true) << std::endl;
    std::wcout << sozdatLozung(result, false) << std::endl;
    return result;
}

/**
 * @brief Дешифрует текст, зашифрованный методом Виженера.
 * @param tekst Зашифрованный текст.
 * @return Расшифрованная строка.
 */
std::wstring VigenereCipher::rasshifrovat(const std::wstring &tekst) const
{
    std::wstring result = obrabotatTekst(tekst, false);
    std::wcout << sozdatLozung(tekst, false) << std::endl;
    std::wcout << sozdatLozung(result, true) << std::endl;
    return result;
}

/**
 * @brief Внутренняя обработка текста (шифрование или дешифрование).
 * @param tekst Входной текст.
 * @param shifrovat true — шифровать, false — дешифровать.
 * @return Результат.
 */
std::wstring VigenereCipher::obrabotatTekst(const std::wstring &tekst, bool shifrovat) const
{
    std::wstring rezultat;
    rezultat.reserve(tekst.length());
    size_t poziciyaKlyucha = 0;

    for (wchar_t c : tekst)
    {
        if (!iswalpha(c) && c != L' ')
        {
            rezultat += c;
            continue;
        }

        wchar_t bukvaKlyucha = klyuch_[poziciyaKlyucha % klyuch_.length()];
        if (c == L' ')
        {
            rezultat += L' ';
        }
        else
        {
            rezultat += obrabotatBukvu(c, bukvaKlyucha, shifrovat);
        }

        if (bukvaKlyucha != L' ')
            poziciyaKlyucha++;
    }

    return rezultat;
}

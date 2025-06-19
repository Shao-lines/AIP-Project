/**
 * @file pi_cipher.cpp
 * @brief Реализация модуля PiCipher для шифрования и дешифрования текста с использованием числа Пи.
 * @author 
 * @date 
 */

#include "pi_cipher.h"
#include <unordered_map>
#include <cwctype> ///< Для towupper

/**
 * @brief Последовательность цифр числа Пи после запятой.
 *
 * Используется для генерации уникальных двузначных кодов для символов алфавита.
 */
const std::wstring pi_digits =
    L"14159265358979323846264338327950288419716939937510"
    L"58209749445923078164062862089986280348253421170679"
    L"82148086513282306647093844609550582231725359408128"
    L"48111745028410270193852110555964462294895493038196"
    L"44288109756659334461284756482337867831652712019091"
    L"45648566923460348610454326648213393607260249141273"
    L"72458700660631558817488152092096282925409171536436"
    L"78925903600113305305488204665213841469519415116094"
    L"33057270365759591953092186117381932611793105118548"
    L"07446237996274956735188575272489122793818301194912"
    L"98336733624406566430860213949463952247371907021798"
    L"60943702770539217176293176752384674818467669405132"
    L"00056812714526356082778577134275778960917363717872"
    L"14684409012249534301465495853710507922796892589235"
    L"42019956112129021960864034418159813629774771309960"
    L"51870721134999999837297804995105973173281609631859"
    L"50244594553469083026425223082533446850352619311881"
    L"71010003137838752886587533208381420617177669147303"
    L"59825349042875546873115956286388235378759375195778"
    L"18577805321712268066130019278766111959092164201989";

/**
 * @brief Генерирует таблицы кодирования и декодирования для Pi Cipher.
 *
 * Каждому символу алфавита присваивается уникальный двузначный код из последовательности числа Пи.
 *
 * @param key Позиция начала в последовательности Пи (1 = первая цифра после запятой).
 * @param alphabet Алфавит символов.
 * @param[out] enc_map Таблица кодирования: символ → двузначный код.
 * @param[out] dec_map Таблица декодирования: двузначный код → символ.
 */
void PiCipher::build_codebooks(
    int key,
    const std::wstring& alphabet,
    std::unordered_map<wchar_t, std::wstring>& enc_map,
    std::unordered_map<std::wstring, wchar_t>& dec_map)
{
    std::unordered_map<std::wstring, bool> used;
    int pi_len = pi_digits.size();
    int pos = key - 1;

    for (wchar_t c : alphabet) {
        while (pos + 1 < pi_len) {
            std::wstring num = pi_digits.substr(pos, 2);
            pos += 2;
            if (!used[num]) {
                used[num] = true;
                enc_map[c] = num;
                dec_map[num] = c;
                break;
            }
        }
    }
}

/**
 * @brief Шифрует текст с использованием Pi Cipher.
 *
 * Каждая буква заменяется на соответствующий двузначный код.
 *
 * @param text Исходный текст.
 * @param enc_map Таблица кодирования: символ → код.
 * @return Зашифрованная строка (только цифры).
 */
std::wstring PiCipher::encrypt(
    const std::wstring& text,
    const std::unordered_map<wchar_t, std::wstring>& enc_map)
{
    std::wstring res;
    for (wchar_t c : text) {
        wchar_t up = std::towupper(c);
        if (enc_map.count(up))
            res += enc_map.at(up);
    }
    return res;
}

/**
 * @brief Дешифрует строку, зашифрованную с использованием Pi Cipher.
 *
 * Каждая пара цифр интерпретируется как код и заменяется символом.
 *
 * @param cipher Зашифрованная строка.
 * @param dec_map Таблица декодирования: код → символ.
 * @return Расшифрованный текст.
 */
std::wstring PiCipher::decrypt(
    const std::wstring& cipher,
    const std::unordered_map<std::wstring, wchar_t>& dec_map)
{
    std::wstring res;
    for (size_t i = 0; i + 1 < cipher.size(); i += 2) {
        std::wstring num = cipher.substr(i, 2);
        res += dec_map.count(num) ? dec_map.at(num) : L'?';
    }
    return res;
}

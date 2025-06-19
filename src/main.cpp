#include <iostream>
#include <string>
#include <vector>
#include <locale.h>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include <algorithm>

// Подключаем все шифры
#include "xor_cipher.h"
#include "gronsfeld_cipher.h"
#include "vigenere_cipher.h"
#include "rail_fence_cipher.h"
#include "turn_grid_cipher.h"
#include "reverser_cipher.h"
#include "polybius_cipher.h"
#include "affine_cipher.h"
#include "pi_cipher.h"

const std::wstring RU_ALPHABET = L"АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
const std::wstring EN_ALPHABET = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

enum Alphabet
{
    ENGLISH = 1,
    RUSSIAN = 2
};
Alphabet currentAlphabet = ENGLISH;

void selectAlphabet()
{
    int choice;
    std::cout << "Select alphabet:\n";
    std::cout << "1. English\n";
    std::cout << "2. Russian\n";
    std::cout << "Your choice: ";
    std::cin >> choice;
    currentAlphabet = (choice == 2) ? RUSSIAN : ENGLISH;
    std::cin.ignore();
}

bool isCoprime(int a, int m)
{
    while (m != 0)
    {
        int t = m;
        m = a % m;
        a = t;
    }
    return a == 1;
}

void processXOR()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    std::wstring alphabet = (currentAlphabet == RUSSIAN)
                                ? RU_ALPHABET
                                : EN_ALPHABET;

    std::wcout << L"Введите ключ: ";
    std::wstring wkey;
    std::getline(std::wcin, wkey);

    // Исправленное приведение к верхнему регистру:
    std::transform(wkey.begin(), wkey.end(), wkey.begin(),
                   [](wchar_t c)
                   { return std::towupper(c); });

    XORCipher cipher(wkey, alphabet);

    std::wcout << L"Выберите режим:\n1 - Зашифровать (HEX)\n2 - Расшифровать из HEX\n> ";
    int xorAction;
    std::wcin >> xorAction;
    std::wcin.ignore();

    if (xorAction == 1)
    {
        std::wcout << L"Введите текст для шифрования: ";
        std::wstring wInputText;
        std::getline(std::wcin, wInputText);

        std::wstring result = cipher.encryptToHex(wInputText);
        std::wcout << L"Зашифрованный HEX: " << result << std::endl;
    }
    else if (xorAction == 2)
    {
        std::wcout << L"Введите HEX-строку для дешифрования: ";
        std::wstring inputText;
        std::getline(std::wcin, inputText);

        std::wstring decrypted = cipher.decryptFromHex(inputText);
        std::wcout << L"Расшифрованный текст: " << decrypted << std::endl;
    }
    else
    {
        std::wcout << L"Неверный выбор режима!" << std::endl;
    }
}

void processGronsfeld(bool encryptMode)
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    std::wcout << L"Введите цифры ключа через пробел (завершите -1): ";
    std::vector<int> key;
    int num;
    while (std::wcin >> num)
    {
        if (num == -1)
            break;
        key.push_back(num);
    }
    std::wcin.ignore();

    std::wstring alphabet = (currentAlphabet == RUSSIAN)
                                ? L"АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"
                                : L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    GronsfeldCipher cipher(key, alphabet);

    std::wcout << L"Введите текст: ";
    std::wstring wtext;
    std::getline(std::wcin, wtext);

    std::wstring wresult = cipher.process(wtext, encryptMode);
    std::wcout << L"Результат: " << wresult << std::endl;
}

void processVigenere(bool encryptMode)
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    std::wcout << L"=== Vigenere Cipher ===" << std::endl;

    std::wstring key;
    std::wcout << L"Enter key: ";
    std::getline(std::wcin, key);

    VigenereCipher cipher(key);

    std::wstring inputText;
    std::wcout << L"Enter text: ";
    std::getline(std::wcin, inputText);

    std::wstring result;
    if (encryptMode)
    {
        result = cipher.zasifrovat(inputText);
    }
    else
    {
        result = cipher.rasshifrovat(inputText);
    }

    std::wcout << L"Result: " << result << std::endl;
}

void processAffine(bool encryptMode)
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    int a, b;
    std::wcout << L"Enter coefficients a and b: ";
    std::wcin >> a >> b;
    std::wcin.ignore();

    std::wstring alphabet = (currentAlphabet == RUSSIAN) ? RU_ALPHABET : EN_ALPHABET;

    if (!isCoprime(a, static_cast<int>(alphabet.size())))
    {
        std::wcout << L"Error: a must be coprime with alphabet size\n";
        return;
    }

    std::wcout << L"Enter text: ";
    std::wstring wInputText;
    std::getline(std::wcin, wInputText);

    std::wstring wresult;
    try
    {
        AffineCipher cipher(a, b, alphabet);
        wresult = encryptMode ? cipher.encrypt(wInputText) : cipher.decrypt(wInputText);
        std::wcout << L"Result: " << wresult << std::endl;
    }
    catch (const std::exception &e)
    {
        std::wcerr << L"Error: " << e.what() << L"\n";
    }
}

void processRailFence(bool encryptMode)
{
    _setmode(_fileno(stdout), _O_U16TEXT); // Для Unicode вывода
    _setmode(_fileno(stdin), _O_U16TEXT);  // Для Unicode ввода

    std::wcout << L"=== Rail Fence Cipher ===" << std::endl;

    int rails;
    std::wcout << L"Enter number of rails: ";
    std::wcin >> rails;
    std::wcin.ignore();

    std::wstring inputText;
    std::wcout << L"Enter text: ";
    std::getline(std::wcin, inputText);

    std::wstring result;
    try
    {
        RailFenceCipher cipher(rails); //  Создаём объект класса

        if (encryptMode)
        {
            result = cipher.encrypt(inputText);
        }
        else
        {
            result = cipher.decrypt(inputText);
        }
        std::wcout << L"Result: " << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::wcerr << L"Error: " << e.what() << std::endl;
    }
}

void processTurnGrid(bool encryptMode)
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    std::wcout << L"=== Turning Grille Cipher ===" << std::endl;

    int size;
    std::wcout << L"Enter grid size (even number): ";
    std::wcin >> size;
    std::wcin.ignore();

    if (size <= 0 || size % 2 != 0)
    {
        std::wcerr << L"Error: Size must be even and positive!" << std::endl;
        return;
    }

    std::wcout << L"Enter text: ";
    std::wstring inputText;
    std::getline(std::wcin, inputText);

    std::wstring result;
    try
    {
        TurnGridCipher cipher(size);
        std::wstring result = cipher.process(inputText, encryptMode);
    }
    catch (const std::exception &e)
    {
        std::wcerr << L"Error: " << e.what() << std::endl;
    }
}

void processReverser()
{
    int blockSize;
    std::cout << "Enter block size (0 for full reverse): ";
    std::cin >> blockSize;
    std::cin.ignore();

    bool shrinking;
    std::cout << "Shrink block size? (1 = yes, 0 = no): ";
    std::cin >> shrinking;
    std::cin.ignore();

    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    std::wcout << L"Введите текст: ";
    std::wstring wtext;
    std::getline(std::wcin, wtext);

    std::wstring result = ReverserCipher::encrypt(wtext, blockSize, shrinking);
    std::wcout << L"Зашифрованный текст: " << result << std::endl;
}

void processPolybius()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    std::setlocale(LC_ALL, "Russian");

    std::wcout << L"=== Polybius Chessboard Cipher ===\n";

    // ✅ Используем выбор из main
    std::wstring alphabet;
    if (currentAlphabet == ENGLISH)
    {
        alphabet = EN_ALPHABET;
        std::wcout << L"Используется английский алфавит (A-Z).\n";
    }
    else
    {
        alphabet = RU_ALPHABET;
        std::wcout << L"Используется русский алфавит (А-Я).\n";
    }

    std::wcout << L"Введите целочисленный ключ (сдвиг по mod 64): ";
    int key;
    std::wcin >> key;
    std::wcin.ignore();

    auto board = PolybiusCipher::build_board(alphabet, key);

    std::wcout << L"Режим (1 = шифрование, 0 = дешифрование): ";
    bool encryptMode;
    std::wcin >> encryptMode;
    std::wcin.ignore();

    std::wcout << L"Введите текст: ";
    std::wstring inputText;
    std::getline(std::wcin, inputText);

    std::wstring result;
    if (encryptMode)
    {
        result = PolybiusCipher::encrypt(inputText, board);
        std::wcout << L"Зашифрованный текст: " << result << L"\n";
    }
    else
    {
        result = PolybiusCipher::decrypt(inputText, board);
        std::wcout << L"Расшифрованный текст: " << result << L"\n";
    }
}

void processPiCipher()
{
    // Включаем поддержку Unicode
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    std::setlocale(LC_ALL, "");

    std::wcout << L"=== Pi Cipher ===\n";

    //  Используем глобальный выбор алфавита
    std::wstring alphabet = (currentAlphabet == RUSSIAN) ? RU_ALPHABET : EN_ALPHABET;

    // Сообщаем пользователю какой алфавит выбран
    if (currentAlphabet == RUSSIAN)
    {
        std::wcout << L"Используется русский алфавит (А-Я).\n";
    }
    else
    {
        std::wcout << L"Используется английский алфавит (A-Z).\n";
    }

    std::wcout << L"Ключ (позиция в числе Пи): ";
    int key;
    std::wcin >> key;
    std::wcin.ignore();

    std::unordered_map<wchar_t, std::wstring> enc_map;
    std::unordered_map<std::wstring, wchar_t> dec_map;
    PiCipher::build_codebooks(key, alphabet, enc_map, dec_map);

    std::wcout << L"Режим (1 = шифрование, 0 = дешифрование): ";
    bool encryptMode;
    std::wcin >> encryptMode;
    std::wcin.ignore();

    std::wcout << L"Введите текст: ";
    std::wstring inputText;
    std::getline(std::wcin, inputText);

    std::wstring result;
    if (encryptMode)
    {
        result = PiCipher::encrypt(inputText, enc_map);
        std::wcout << L"Зашифрованный текст: " << result << L"\n";
    }
    else
    {
        result = PiCipher::decrypt(inputText, dec_map);
        std::wcout << L"Расшифрованный текст: " << result << L"\n";
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "");

    selectAlphabet();

    std::cout << "Select cipher:\n"
              << "1. XOR\n"
              << "2. Gronsfeld\n"
              << "3. Vigenere\n"
              << "4. Affine\n"
              << "5. Rail Fence\n"
              << "6. Turning Grille\n"
              << "7. Reverser\n"
              << "8. Polybius\n"
              << "9. Pi Cipher\n";

    int cipherChoice;
    std::cin >> cipherChoice;
    std::cin.ignore();

    bool encryptMode = true;
    if (!(cipherChoice == 1 || cipherChoice == 7 || cipherChoice == 8 || cipherChoice == 9))
    {
        std::cout << "Mode (0 = decrypt, 1 = encrypt): ";
        std::cin >> encryptMode;
        std::cin.ignore();
    }

    switch (cipherChoice)
    {
    case 1:
        processXOR();
        break;
    case 2:
        processGronsfeld(encryptMode);
        break;
    case 3:
        processVigenere(encryptMode);
        break;
    case 4:
        processAffine(encryptMode);
        break;
    case 5:
        processRailFence(encryptMode);
        break;
    case 6:
        processTurnGrid(encryptMode);
        break;
    case 7:
        processReverser();
        break;
    case 8:
        processPolybius();
        break;
    case 9:
        processPiCipher();
        break;
    default:
        std::cout << "Invalid selection\n";
        return 1;
    }

    return 0;
}
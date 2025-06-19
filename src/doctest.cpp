#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "doctest.h"

#include "pi_cipher.h"
#include "reverser_cipher.h"
#include "polybius_cipher.h"

#include "xor_cipher.h"
#include "gronsfeld_cipher.h"
#include "affine_cipher.h"

#include "vigenere_cipher.h"
#include "rail_fence_cipher.h"
#include "turn_grid_cipher.h"

#include <unordered_map>
#include <string>
#include <vector>

// ---------- HELPER FUNCTION ----------
bool wstrings_equal(const std::wstring& a, const std::wstring& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i)
        if (a[i] != b[i]) return false;
    return true;
}

// ============================
// TESTS FOR PiCipher
// ============================
TEST_SUITE("PiCipher") {

TEST_CASE("encrypt - typical usage") { // обычное шифрование
    std::wstring alphabet = L"ABC";
    std::unordered_map<wchar_t, std::wstring> enc_map;
    std::unordered_map<std::wstring, wchar_t> dec_map;
    PiCipher::build_codebooks(1, alphabet, enc_map, dec_map);

    std::wstring text = L"ABCA";
    std::wstring enc = PiCipher::encrypt(text, enc_map);
    CHECK(enc.size() == 8); // 4 символа * 2 цифры
    std::wstring dec = PiCipher::decrypt(enc, dec_map);
    CHECK(wstrings_equal(dec, L"ABCA"));
}

TEST_CASE("encrypt - text with non-alphabet chars") { // символы вне алфавита игнорируются
    std::wstring alphabet = L"ABC";
    std::unordered_map<wchar_t, std::wstring> enc_map;
    std::unordered_map<std::wstring, wchar_t> dec_map;
    PiCipher::build_codebooks(5, alphabet, enc_map, dec_map);

    std::wstring text = L"A BAD Z";
    CHECK(wstrings_equal(PiCipher::encrypt(text, enc_map), enc_map[L'A'] + enc_map[L'B'] + enc_map[L'A']));
}

TEST_CASE("encrypt - empty input") { // пустая строка
    std::wstring alphabet = L"ABC";
    std::unordered_map<wchar_t, std::wstring> enc_map;
    std::unordered_map<std::wstring, wchar_t> dec_map;
    PiCipher::build_codebooks(10, alphabet, enc_map, dec_map);

    CHECK(wstrings_equal(PiCipher::encrypt(L"", enc_map), L""));
}

TEST_CASE("decrypt - typical usage") { // обычная расшифровка
    std::wstring alphabet = L"XYZ";
    std::unordered_map<wchar_t, std::wstring> enc_map;
    std::unordered_map<std::wstring, wchar_t> dec_map;
    PiCipher::build_codebooks(2, alphabet, enc_map, dec_map);

    std::wstring text = L"XYZ";
    std::wstring enc = PiCipher::encrypt(text, enc_map);
    std::wstring dec = PiCipher::decrypt(enc, dec_map);
    CHECK(wstrings_equal(dec, L"XYZ"));
}

TEST_CASE("decrypt - unknown codes replaced by question") { // неизвестные коды заменяются на '?'
    std::wstring alphabet = L"AB";
    std::unordered_map<wchar_t, std::wstring> enc_map;
    std::unordered_map<std::wstring, wchar_t> dec_map;
    PiCipher::build_codebooks(1, alphabet, enc_map, dec_map);

    std::wstring encrypted = enc_map[L'A'] + L"99" + enc_map[L'B'];
    std::wstring dec = PiCipher::decrypt(encrypted, dec_map);
    CHECK(dec.size() == 3);
    CHECK(dec[0] == L'A');
    CHECK(dec[1] == L'?');
    CHECK(dec[2] == L'B');
}

TEST_CASE("decrypt - empty input") { // пустой вход
    std::unordered_map<std::wstring, wchar_t> dec_map;
    CHECK(wstrings_equal(PiCipher::decrypt(L"", dec_map), L""));
}

// // === Тест с ошибкой для encrypt ===
// TEST_CASE("encrypt - throws if codebook not built (key < 1)") { // ошибка: key < 1
//     std::wstring alphabet = L"ABC";
//     std::unordered_map<wchar_t, std::wstring> enc_map;
//     std::unordered_map<std::wstring, wchar_t> dec_map;
//     // build_codebooks должен выбросить!
//     CHECK_THROWS_AS(PiCipher::build_codebooks(0, alphabet, enc_map, dec_map), std::invalid_argument);
// }

// // === Тест с ошибкой для decrypt ===
// TEST_CASE("decrypt - throws if codebook not built (key too large)") { // ошибка: key слишком большой
//     std::wstring alphabet = L"ABC";
//     std::unordered_map<wchar_t, std::wstring> enc_map;
//     std::unordered_map<std::wstring, wchar_t> dec_map;
//     // build_codebooks должен выбросить!
//     CHECK_THROWS_AS(PiCipher::build_codebooks(10000, alphabet, enc_map, dec_map), std::invalid_argument);
// }

} // END SUITE PiCipher

// ============================
// TESTS FOR ReverserCipher
// ============================
TEST_SUITE("ReverserCipher") {

// --- 2 теста для encrypt ---
TEST_CASE("encrypt - typical usage, no shrinking") { // обычное шифрование, фиксированный блок
    std::wstring text = L"ABCDEFGH";
    std::wstring enc = ReverserCipher::encrypt(text, 3, false); // блоки: ABC DEF GH
    // -> CBA FED GH
    CHECK(enc == L"CBAFEDHG");
}

TEST_CASE("encrypt - shrinking blocks") { // shrinking=true, блок уменьшается
    std::wstring text = L"ABCDEFGH";
    std::wstring enc = ReverserCipher::encrypt(text, 3, true); // блоки: 3->2->2->2: ABC DE FG H
    CHECK(enc == L"CBAEDGFH");
}

// --- 2 теста для decrypt ---
TEST_CASE("decrypt - typical roundtrip") { // encrypt/decrypt без shrinking
    std::wstring text = L"EXAMPLETEXT";
    std::wstring enc = ReverserCipher::encrypt(text, 4, false); // блоки: 4-4-3
    std::wstring dec = ReverserCipher::decrypt(enc, 4, false);
    CHECK(dec == text);
}

TEST_CASE("decrypt - shrinking roundtrip") { // encrypt/decrypt с shrinking
    std::wstring text = L"SECRETMESSAGE";
    std::wstring enc = ReverserCipher::encrypt(text, 5, true);
    std::wstring dec = ReverserCipher::decrypt(enc, 5, true);
    CHECK(dec == text);
}

// // --- 1 тест с ошибкой для encrypt ---
// TEST_CASE("encrypt - throws on non-positive block size") { // ошибка: блок <= 0
//     CHECK_THROWS_AS(ReverserCipher::encrypt(L"FAIL", 0, false), std::invalid_argument);
//     CHECK_THROWS_AS(ReverserCipher::encrypt(L"FAIL", -2, true), std::invalid_argument);
// }

// // --- 1 тест с ошибкой для decrypt ---
// TEST_CASE("decrypt - throws on non-positive block size") { // ошибка: блок <= 0
//     CHECK_THROWS_AS(ReverserCipher::decrypt(L"FAIL", 0, false), std::invalid_argument);
//     CHECK_THROWS_AS(ReverserCipher::decrypt(L"FAIL", -1, true), std::invalid_argument);
// }

} // END SUITE ReverserCipher

// ============================
// TESTS FOR PolybiusCipher
// ============================
TEST_SUITE("PolybiusCipher") {

const std::wstring ALPHABET = L"ABCDEFGH";
const int BOARD_SIZE = 8;

// --- 2 теста для encrypt ---
TEST_CASE("encrypt - typical usage") { // обычное шифрование
    auto board = PolybiusCipher::build_board(ALPHABET, 0);
    std::wstring input = L"ABH";
    std::wstring result = PolybiusCipher::encrypt(input, board);
    CHECK(result == L"a1b1h1"); // Проверяем корректное шифрование
}

TEST_CASE("encrypt - ignores non-alphabet chars and preserves spaces") { // неалфавитные пропускаются, пробелы сохраняются
    auto board = PolybiusCipher::build_board(ALPHABET, 0);
    std::wstring input = L"DAD";
    std::wstring result = PolybiusCipher::encrypt(input, board);
    CHECK(result == L"d1a1d1");
}

// --- 2 теста для decrypt ---
TEST_CASE("decrypt - typical usage") { // обычная расшифровка
    auto board = PolybiusCipher::build_board(ALPHABET, 0);
    std::wstring enc = L"a1b1h1";
    std::wstring dec = PolybiusCipher::decrypt(enc, board);
    CHECK(dec == L"ABH");
}

TEST_CASE("decrypt - preserves spaces and ignores bad pairs") { // пробелы сохраняются, некорректные пары игнорируются
    auto board = PolybiusCipher::build_board(ALPHABET, 0);
    std::wstring enc = L"a1x9b1";
    std::wstring dec = PolybiusCipher::decrypt(enc, board);
    CHECK(dec == L"AB");
}

// // --- 1 тест с ошибкой для encrypt ---
// TEST_CASE("encrypt - empty board returns empty string") { // ошибка: пустая доска (алфавит)
//     auto board = PolybiusCipher::build_board(L"", 0); // board заполнен пробелами
//     CHECK(PolybiusCipher::encrypt(L"ANY", board) == L"");
// }

// // --- 1 тест с ошибкой для decrypt ---
// TEST_CASE("decrypt - incomplete pair at end is ignored") { // ошибка: нечетная длина шифртекста
//     auto board = PolybiusCipher::build_board(ALPHABET, 0);
//     std::wstring enc = L"a1b"; // последний символ 'b' без пары координат — должен игнорироваться
//     std::wstring dec = PolybiusCipher::decrypt(enc, board);
//     CHECK(dec == L"A");
// }

} // END SUITE PolybiusCipher

// ============================ 
// TESTS FOR GronsfeldCipher
// ============================
TEST_SUITE("GronsfeldCipher") {

// --- Тест шифрования с ключом из нескольких цифр ---
TEST_CASE("encrypt - multi-digit key") { 
    std::wstring alphabet = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::vector<int> key = {4, 3, 2, 1}; // будет циклически повторяться
    GronsfeldCipher cipher(key, alphabet);

    std::wstring text = L"SECRET";
    // Индексы:  S(18)+4=22->W, E(4)+3=7->H, C(2)+2=4->E, R(17)+1=18->S, E(4)+4=8->I, T(19)+3=22->W
    std::wstring expected = L"WHESIW";
    CHECK(cipher.process(text, true) == expected);
}

TEST_CASE("encrypt - with spaces and repeated letters") { // шифрование строки с пробелами и повторяющимися символами
    std::wstring alphabet = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ "; // алфавит с пробелом
    std::vector<int> key = {1, 2, 3}; // ключ для Гронсфельда
    GronsfeldCipher cipher(key, alphabet);

    std::wstring text = L"MEET ME";
    // Алгоритм по символам:
    // M(12)+1=13->N, E(4)+2=6->G, E(4)+3=7->H, T(19)+1=20->U,
    //  ' ' (26)+2=28%27=1->B, M(12)+3=15->P, E(4)+1=5->F
    std::wstring expected = L"NGHUBPF";
    CHECK(cipher.process(text, true) == expected);
}

// --- Тест расшифровки того же текста ---
TEST_CASE("decrypt - multi-digit key") { 
    std::wstring alphabet = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::vector<int> key = {4, 3, 2, 1};
    GronsfeldCipher cipher(key, alphabet);

    std::wstring ciphered = L"WHESIW";
    std::wstring expected = L"SECRET";
    CHECK(cipher.process(ciphered, false) == expected);
}

TEST_CASE("decrypt - with non-alphabet chars") { // символы вне алфавита не меняются
    std::wstring alphabet = L"ABCDE";
    std::vector<int> key = {2};
    GronsfeldCipher cipher(key, alphabet);

    std::wstring encrypted = L"C E B";
    std::wstring expected = L"A C E";
    CHECK(cipher.process(encrypted, false) == expected);
}

// // === Тест с ошибкой для encrypt ===
// TEST_CASE("encrypt - throws on empty key") { // ошибка: пустой ключ
//     std::wstring alphabet = L"ABCDE";
//     std::vector<int> key; // пустой ключ
//     CHECK_THROWS_AS(GronsfeldCipher cipher(key, alphabet), std::invalid_argument);
// }

// // === Тест с ошибкой для decrypt ===
// TEST_CASE("decrypt - throws on empty alphabet") { // ошибка: пустой алфавит
//     std::wstring alphabet = L""; // пустой алфавит
//     std::vector<int> key = {1,2};
//     CHECK_THROWS_AS(GronsfeldCipher cipher(key, alphabet), std::invalid_argument);
// }

} // END SUITE GronsfeldCipher

// ============================ 
// TESTS FOR AffineCipher
// ============================
TEST_SUITE("AffineCipher") {

// --- ENCRYPT TESTS ---

TEST_CASE("encrypt - typical usage") { // обычное шифрование
    std::wstring alphabet = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int a = 5, b = 8;
    AffineCipher cipher(a, b, alphabet);

    std::wstring text = L"HELLO";
    // Индексы: H=7, E=4, L=11, O=14
    // Формула: (a*x + b) % 26
    // H: (5*7+8)%26=43%26=17 -> R
    // E: (5*4+8)%26=28%26=2  -> C
    // L: (5*11+8)%26=63%26=11 -> L
    // O: (5*14+8)%26=78%26=0 -> A
    std::wstring expected = L"RCLLA";
    CHECK(cipher.encrypt(text) == expected);
}

TEST_CASE("encrypt - with spaces and unknown chars") { // шифрование с пробелами и неизвестными символами
    std::wstring alphabet = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int a = 7, b = 2;
    AffineCipher cipher(a, b, alphabet);

    std::wstring text = L"A B?Z";
    // A: (7*0+2)%26=2 -> C
    //  : пробел
    // B: (7*1+2)%26=9 -> J
    // ?: не в алфавите -> ?
    // Z: (7*25+2)%26=177%26=21 -> V
    std::wstring expected = L"C J?V";
    CHECK(cipher.encrypt(text) == expected);
}

// --- DECRYPT TESTS ---

TEST_CASE("decrypt - typical usage") { // обычная расшифровка
    std::wstring alphabet = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int a = 5, b = 8;
    AffineCipher cipher(a, b, alphabet);

    std::wstring cipher_text = L"RCLLA";
    std::wstring expected = L"HELLO";
    CHECK(cipher.decrypt(cipher_text) == expected);
}

TEST_CASE("decrypt - with spaces and unknown chars") { // расшифровка с пробелами и неизвестными символами
    std::wstring alphabet = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int a = 7, b = 2;
    AffineCipher cipher(a, b, alphabet);

    std::wstring cipher_text = L"C J?V";
    std::wstring expected = L"A B?Z";
    CHECK(cipher.decrypt(cipher_text) == expected);
}

// --- ERROR TESTS ---

// // === Тест с ошибкой для encrypt ===
// TEST_CASE("encrypt - throws if 'a' is not coprime with alphabet length") { // ошибка: a не взаимно просто с m
//     std::wstring alphabet = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     int a = 13231321, b = 5;
//     CHECK_THROWS_AS(AffineCipher(a, b, alphabet), std::invalid_argument);
// }

// // === Тест с ошибкой для decrypt ===
// TEST_CASE("decrypt - throws if 'a' is not coprime with alphabet length") { // ошибка: a не взаимно просто с m
//     std::wstring alphabet = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     int a = 123213, b = 5;
//     CHECK_THROWS_AS(AffineCipher(a, b, alphabet), std::invalid_argument);
// }

} // END SUITE AffineCipher

// ============================ 
// TESTS FOR VigenereCipher
// ============================
TEST_SUITE("VigenereCipher") {

// --- Тест обычного шифрования ---
TEST_CASE("encrypt - typical usage (latin)") { // обычное шифрование на латинице
    VigenereCipher cipher(L"KEY");
    std::wstring text = L"HELLO";
    std::wstring enc = cipher.zasifrovat(text);
    CHECK(enc == L"RIJVS");
}

// --- Тест шифрования с пробелами и спецсимволами ---
TEST_CASE("encrypt - with spaces and symbols") { // текст с пробелами и знаками препинания
    VigenereCipher cipher(L"KEY");
    std::wstring text = L"HI, HOW ARE YOU?";
    std::wstring enc = cipher.zasifrovat(text);
    // ',' и '?' не изменяются, пробелы остаются
    CHECK(enc.substr(0,2) == L"RM");
    CHECK(enc.size() == text.size());
}

// --- Тест обычной расшифровки ---
TEST_CASE("decrypt - typical usage (latin)") { // обычная расшифровка на латинице
    VigenereCipher cipher(L"KEY");
    std::wstring enc = L"RIJVS";
    std::wstring dec = cipher.rasshifrovat(enc);
    CHECK(dec == L"HELLO");
}

// --- Тест расшифровки с пробелами и символами ---
TEST_CASE("decrypt - with spaces and symbols") { // расшифровка с пробелами и знаками препинания
    VigenereCipher cipher(L"KEY");
    std::wstring enc = cipher.zasifrovat(L"HI, HOW ARE YOU?");
    std::wstring dec = cipher.rasshifrovat(enc);
    CHECK(dec == L"HI, HOW ARE YOU?");
}

// // === Тест с ошибкой: ключ содержит только пробелы ===
// TEST_CASE("encrypt - throws if key is only spaces") { // ошибка: ключ состоит только из пробелов
//     CHECK_THROWS_AS(VigenereCipher(L"     "), std::invalid_argument);
// }

// // === Тест с ошибкой: ключ слишком длинный, но содержит запрещенные символы ===
// TEST_CASE("encrypt") { // ошибка: длинный ключ с двумя пробелами между словами
//     CHECK_THROWS_AS(VigenereCipher(L"HELLO  WORLD"), std::invalid_argument);
// }

} // END SUITE VigenereCipher

// ============================ 
// TESTS FOR RailFenceCipher
// ============================
TEST_SUITE("RailFenceCipher") {

// Обычное шифрование
TEST_CASE("encrypt - typical usage") {
    RailFenceCipher cipher(3);
    std::wstring text = L"WEAREDISCOVEREDFLEEATONCE";
    std::wstring expected = L"WECRLTEERDSOEEFEAOCAIVDEN";
    CHECK(cipher.encrypt(text) == expected);
}

// Шифрование с 2 рельсами
TEST_CASE("encrypt - 2 rails") {
    RailFenceCipher cipher(2);
    std::wstring text = L"HELLOWORLD";
    std::wstring expected = L"HLOOLELWRD";
    CHECK(cipher.encrypt(text) == expected);
}

// Обычное дешифрование
TEST_CASE("decrypt - typical usage") {
    RailFenceCipher cipher(3);
    std::wstring encrypted = L"WECRLTEERDSOEEFEAOCAIVDEN";
    std::wstring expected = L"WEAREDISCOVEREDFLEEATONCE";
    CHECK(cipher.decrypt(encrypted) == expected);
}

// Дешифрование с одним рельсом (текст не меняется)
TEST_CASE("decrypt - 1 rail (no change)") {
    RailFenceCipher cipher(1);
    std::wstring encrypted = L"ANYTEXT";
    CHECK(cipher.decrypt(encrypted) == encrypted);
}

// // === Тест с ошибкой для encrypt: отрицательное количество рельс ===
// TEST_CASE("encrypt - typical usage") {
//     RailFenceCipher cipher(-3);
//     std::wstring text = L"WEAREDISCOVEREDFLEEATONCE";
//     std::wstring expected = L"WECRLTEERDSOEEFEAOCAIVDEN";
//     CHECK(cipher.encrypt(text) == expected);
// }

// // === Тест с ошибкой для encrypt: отрицательное количество рельс ===
// TEST_CASE("decrypt - typical usage") {
//     RailFenceCipher cipher(-3);
//     std::wstring encrypted = L"WECRLTEERDSOEEFEAOCAIVDEN";
//     std::wstring expected = L"WEAREDISCOVEREDFLEEATONCE";
//     CHECK(cipher.decrypt(encrypted) == expected);
// }

} // END SUITE RailFenceCipher

// ============================ 
// TESTS FOR TurnGridCipher
// ============================
TEST_SUITE("TurnGridCipher") {

TEST_CASE("encrypt - typical usage") { // обычное шифрование
    TurnGridCipher cipher(4);
    std::wstring text = L"ABCD";
    std::wstring encrypted = cipher.process(text, true);
    // Просто проверяем, что шифруется и длина не меньше входной строки
    CHECK(encrypted.size() >= text.size());
}

TEST_CASE("encrypt - short text") { // короткий текст (меньше отверстий)
    TurnGridCipher cipher(4);
    std::wstring text = L"X";
    std::wstring encrypted = cipher.process(text, true);
    CHECK(encrypted.size() >= 1);
    CHECK(encrypted.find(L'X') != std::wstring::npos);
}

TEST_CASE("decrypt - empty input") { // пустой вход
    TurnGridCipher cipher(4);
    std::wstring decrypted = cipher.process(L"", false);
    CHECK(decrypted == L"");
}

// // ==== Тесты с ошибкой для encrypt ====
// TEST_CASE("encrypt - throws on grid size 0") { // ошибка: размер 0
//     CHECK_THROWS_AS(TurnGridCipher(0), std::invalid_argument);
// }

// // ==== Тесты с ошибкой для decrypt ====
// TEST_CASE("decrypt - throws on grid size negative") { // ошибка: отрицательный размер
//     CHECK_THROWS_AS(TurnGridCipher(-2), std::invalid_argument);
// }

} // END SUITE TurnGridCipher
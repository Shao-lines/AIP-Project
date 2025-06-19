# AIP-Project
#  MultiCipher C++ Project

**MultiCipher** — это учебный криптопроект на C++ с реализацией и сравнением нескольких классических методов шифрования:
- XOR Cipher
- Gronsfeld Cipher
- Vigenere Cipher
- Affine Cipher
- Rail Fence Cipher
- Turning Grille Cipher
- Reverser Cipher
- Polybius Cipher
- Pi Cipher

Проект поддерживает **Unicode** (русский и английский алфавит), тестирование с помощью **Doctest**, гибкие пользовательские настройки и консольное меню.

---

1) Сборка проекта

mkdir build
cd build
cmake ..
cmake --build .

./all_ciphers.exe

2) Запуск тестов
# Запуск тестов из каталога сборки
ctest


3) Структура проекта
AIP/ # Корневая папка проекта
├── build/ # Каталог сборки (создаётся CMake)
├── docs/html/ # Автоматически сгенерированная Doxygen-документация
├── src/ # Исходный код программы и тестов
│ ├── affine_cipher.cpp # Affine Cipher: реализация
│ ├── affine_cipher.h # Affine Cipher: заголовок
│ ├── gronsfeld_cipher.cpp # Gronsfeld Cipher: реализация
│ ├── gronsfeld_cipher.h # Gronsfeld Cipher: заголовок
│ ├── pi_cipher.cpp # Pi Cipher: реализация
│ ├── pi_cipher.h # Pi Cipher: заголовок
│ ├── polybius_cipher.cpp # Polybius Cipher: реализация
│ ├── polybius_cipher.h # Polybius Cipher: заголовок
│ ├── rail_fence_cipher.cpp # Rail Fence Cipher: реализация
│ ├── rail_fence_cipher.h # Rail Fence Cipher: заголовок
│ ├── reverser_cipher.cpp # Reverser Cipher: реализация
│ ├── reverser_cipher.h # Reverser Cipher: заголовок
│ ├── turn_grid_cipher.cpp # Turning Grille Cipher: реализация
│ ├── turn_grid_cipher.h # Turning Grille Cipher: заголовок
│ ├── vigenere_cipher.cpp # Vigenere Cipher: реализация
│ ├── vigenere_cipher.h # Vigenere Cipher: заголовок
│ ├── xor_cipher.cpp # XOR Cipher: реализация
│ ├── xor_cipher.h # XOR Cipher: заголовок
│ ├── main.cpp # Точка входа: консольный интерфейс
│ ├── main.exe # Скомпилированный исполняемый файл (Windows)
│ ├── doctest.cpp # Тесты проекта
│ ├── doctest.h # Заголовочный файл doctest
│ ├── doctest.exe # Скомпилированный тестовый exe
├── CMakeLists.txt # CMake build configuration
├── Doxyfile # Конфигурация для генерации документации Doxygen
├── README.md # Описание проекта (этот файл)

**Примечание:**  
- Все `.cpp` и `.h` файлы расположены в папке `src/` для удобства сборки и генерации Doxygen-документации.  
- Файл `CMakeLists.txt` управляет сборкой всех шифров и тестов.
- `Doxyfile` нужен для автогенерации HTML-документации.
- `build/` и `docs/` не должны храниться в репозитории — их можно добавить в `.gitignore`.

5) Функционал
Выбор алфавита (EN / RU)
Интерактивный CLI
Поддержка HEX в XOR-шифре
Поддержка ошибок и проверок корректности
Кроссплатформенность (Windows / Linux)

6) Описание реализованных шифров:
XOR Cipher: 	один из простейших симметричных шифров. Каждый символ текста XOR-ится с символом ключа. Поддерживает HEX-режим.
Gronsfeld Cipher: вариант шифра Виженера. Использует цифровой ключ для циклического сдвига символов алфавита. Числовой ключ задается пользователем.
Affine Cipher:  шифр на основе линейного преобразования: каждый символ кодируется по формуле y = (a * x + b) mod m, где a и b — ключи, m — размер алфавита.
Vigenere Cipher: классический многоалфавитный шифр. Каждый символ текста сдвигается на значение буквы ключа по алфавиту.
Rail Fence Cipher (Рельсовая погоня):cимволы текста записываются по диагонали на «рельсах», затем читаются по строкам. Простой перестановочный шифр.
Turning Grille Cipher (Поворотная решётка): cимволы записываются в ячейки решётки с отверстиями. После каждого поворота решётки заполняются новые позиции.
Reverser Cipher: делит текст на блоки и реверсирует каждый блок. Можно задать размер блока и включить уменьшение размера блоков.
Polybius Cipher (Шахматная доска): 	классический квадрат Полибия (здесь — 8×8 доска). Каждый символ кодируется координатами строки и столбца.
Pi Cipher: шифр на основе цифр числа Пи: для каждой буквы выбирается последовательность Пи и сопоставляется свой код.

7) Как использовать каждый шифр
Каждый шифр доступен из общего CLI меню.
Поддержка русского и английского алфавита.
Пользователь выбирает режим работы: шифрование или дешифрование.
Все шифры работают с Unicode.

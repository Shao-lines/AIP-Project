cmake_minimum_required(VERSION 3.15)

# Название твоего проекта
project(AllCiphersProject LANGUAGES CXX)

# Настройки C++ стандарта
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Если используешь Unicode API Windows
if (WIN32)
    add_definitions(-DUNICODE)
endif()

# Добавляем исполняемый файл
add_executable(all_ciphers
    src/main.cpp

    src/xor_cipher.cpp
    src/gronsfeld_cipher.cpp
    src/vigenere_cipher.cpp
    src/affine_cipher.cpp
    src/rail_fence_cipher.cpp
    src/turn_grid_cipher.cpp
    src/reverser_cipher.cpp
    src/polybius_cipher.cpp
    src/pi_cipher.cpp
)

add_executable(doctest
    src/doctest.cpp       # только тут doctest.cpp!

    src/xor_cipher.cpp
    src/gronsfeld_cipher.cpp
    src/vigenere_cipher.cpp
    src/affine_cipher.cpp
    src/rail_fence_cipher.cpp
    src/turn_grid_cipher.cpp
    src/reverser_cipher.cpp
    src/polybius_cipher.cpp
    src/pi_cipher.cpp
)

# Если есть заголовки в папке include, можно так:
# target_include_directories(all_ciphers PRIVATE ${CMAKE_SOURCE_DIR}/include)
enable_testing()
add_test(NAME run_doctest COMMAND doctest)
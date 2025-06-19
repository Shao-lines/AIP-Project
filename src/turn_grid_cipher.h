#ifndef TURN_GRID_CIPHER_H
#define TURN_GRID_CIPHER_H

#include <string>
#include <vector>

/**
 * @class TurnGridCipher
 * @brief Класс для шифрования и дешифрования текста методом поворотной решётки (Turning Grille Cipher).
 *
 * Решётка формируется с отверстиями и поворачивается по часовой стрелке.
 * Работает с Unicode и поддерживает визуализацию состояния решётки и сетки.
 */
class TurnGridCipher {
public:
    /**
     * @brief Конструктор.
     * @param size Размер решётки (чётный).
     * @throw std::invalid_argument Если размер нечётный.
     */
    explicit TurnGridCipher(int size);

    /**
     * @brief Шифрует или дешифрует текст.
     * @param text Исходный текст.
     * @param encrypt true — шифровать, false — дешифровать.
     * @return Результат.
     */
    std::wstring process(const std::wstring& text, bool encrypt);

private:
    int size_;

    std::vector<std::vector<bool>> createGrille() const;
    void rotateGrille(std::vector<std::vector<bool>>& grille) const;
    void validateGrilleHoles(const std::vector<std::vector<bool>>& grille) const;
    void printGrille(const std::vector<std::vector<bool>>& grille) const;
    void printGrid(const std::vector<std::vector<wchar_t>>& grid) const;
};

#endif // TURN_GRID_CIPHER_H

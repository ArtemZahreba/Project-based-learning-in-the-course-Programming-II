#ifndef TWODIMARRAY_H
#define TWODIMARRAY_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TwoDimArray {
private:
    int rows;
    int cols;
    vector<vector<int>> data;

public:
    // Конструктор за замовчуванням
    TwoDimArray();

    // Деструктор
    ~TwoDimArray();

    // Конструктор з параметрами
    TwoDimArray(int rows, int cols);

    // Конструктор копіювання
    TwoDimArray(const TwoDimArray& other);

    // Перевантажена операція присвоєння
    TwoDimArray& operator=(const TwoDimArray& other);

    // Перевантажена операція виведення
    friend ostream& operator<<(ostream& out, const TwoDimArray& arr);

    // Метод для завантаження даних із файлу
    void loadFromFile(const string& filename);

    // Метод для збереження даних у файл
    void saveToFile(const string& filename) const;

    // Метод для заповнення випадковими числами
    void fillRandom(int minValue, int maxValue);

    // Метод для отримання кількості рядків без нульових елементів
    int countNonZeroRows() const;

    // Метод для пошуку максимального числа, що повторюється
    int findMaxRepeatedNumber() const;
};

#endif

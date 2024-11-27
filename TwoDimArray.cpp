#include "TwoDimArray.hpp"
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

// Конструктор за замовчуванням
TwoDimArray::TwoDimArray() : rows(0), cols(0) {}

// Деструктор
TwoDimArray::~TwoDimArray() {}

// Конструктор з параметрами
TwoDimArray::TwoDimArray(int r, int c) : rows(r), cols(c), data(r, vector<int>(c)) {}

// Конструктор копіювання
TwoDimArray::TwoDimArray(const TwoDimArray& other) : rows(other.rows), cols(other.cols), data(other.data) {}

// Перевантажена операція присвоєння
TwoDimArray& TwoDimArray::operator=(const TwoDimArray& other) {
    if (this == &other) return *this;
    rows = other.rows;
    cols = other.cols;
    data = other.data;
    return *this;
}

// Перевантажена операція виведення
ostream& operator<<(ostream& out, const TwoDimArray& arr) {
    for (const auto& row : arr.data) {
        for (int val : row) {
            out << val << " ";
        }
        out << endl;
    }
    return out;
}

// Метод для завантаження даних із файлу
void TwoDimArray::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Помилка відкриття файлу: " << filename << endl;
        return;
    }
    inFile >> rows >> cols;
    data.resize(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inFile >> data[i][j];
        }
    }
}

// Метод для збереження даних у файл
void TwoDimArray::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Помилка запису у файл: " << filename << endl;
        return;
    }
    outFile << rows << " " << cols << endl;
    for (const auto& row : data) {
        for (int val : row) {
            outFile << val << " ";
        }
        outFile << endl;
    }
}

// Метод для заповнення випадковими числами
void TwoDimArray::fillRandom(int minValue, int maxValue) {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = rand() % (maxValue - minValue + 1) + minValue;
        }
    }
}

// Метод для отримання кількості рядків без нульових елементів
int TwoDimArray::countNonZeroRows() const {
    int count = 0;
    for (const auto& row : data) {
        if (all_of(row.begin(), row.end(), [](int val) { return val != 0; })) {
            ++count;
        }
    }
    return count;
}

// Метод для пошуку максимального числа, що повторюється
int TwoDimArray::findMaxRepeatedNumber() const {
    unordered_map<int, int> frequency;
    for (const auto& row : data) {
        for (int val : row) {
            ++frequency[val];
        }
    }

    int maxRepeated = INT_MIN;
    for (const auto& [key, value] : frequency) {
        if (value > 1 && key > maxRepeated) {
            maxRepeated = key;
        }
    }
    return (maxRepeated == INT_MIN) ? -1 : maxRepeated;
}

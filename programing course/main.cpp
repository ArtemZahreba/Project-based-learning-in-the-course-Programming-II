#include "TwoDimArray.hpp"

int main() {
    int rows, cols;

    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> cols;

    TwoDimArray array(rows, cols);

    // Заповнення масиву випадковими числами
    array.fillRandom(-10, 10);
    cout << "Двовимірний масив:\n" << array;

    // Розрахунок кількості рядків без нульових елементів
    int nonZeroRows = array.countNonZeroRows();
    cout << "Кількість рядків без нульових елементів: " << nonZeroRows << endl;

    // Пошук максимального числа, що повторюється
    int maxRepeated = array.findMaxRepeatedNumber();
    if (maxRepeated != -1) {
        cout << "Максимальне число, що повторюється: " << maxRepeated << endl;
    } else {
        cout << "У масиві немає чисел, що повторюються." << endl;
    }

    // Збереження масиву у файл
    array.saveToFile("array.txt");
    cout << "Масив збережено у файл array.txt." << endl;

    return 0;
}


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

int main() {
    int matrix[ROWS][COLS];

    // заповнюємо масив випадковими числами
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    // виводимо матрицю на екран
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // знаходимо елементи на головній діагоналі
    cout << "Елементи на головній діагоналі: ";
    for (int i = 0; i < ROWS; i++) {
        cout << *((int*)(&matrix[i]) + i) << " ";
    }
    cout << endl;

    // знаходимо елементи на побічній діагоналі
    cout << "Елементи на побічній діагоналі: ";
    for (int i = 0; i < ROWS; i++) {
        cout << *((int*)(&matrix[i]) + (COLS - i - 1)) << " ";
    }
    cout << endl;

    // знаходимо кількість парних та непарних елементів масиву
    int count_even = 0, count_odd = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] % 2 == 0) {
                count_even++;
            } else {
                count_odd++;
            }
        }
    }
    cout << "Кількість парних елементів: " << count_even << endl;
    cout << "Кількість непарних елементів: " << count_odd << endl;

    return 0;
}

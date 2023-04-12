#include <iostream>
using namespace std;

int main() {
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
    int n = sizeof(vector) / sizeof(vector[0]);

    int* max_ptr = vector; // вказівник на перший елемент масиву
    for (int* p = vector + 1; p < vector + n; p++) { // проходимо по масиву вказівниками
        if (*p > *max_ptr) { // порівнюємо значення, на які вказують вказівники
            max_ptr = p; // оновлюємо вказівник на максимальний елемент
        }
    }

    cout << "Найбільший елемент масиву: " << *max_ptr << endl;

    return 0;
}

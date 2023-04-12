#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int N = 14; // можна змінити на бажану кількість елементів
    float* arr = new float[N]; // створюємо масив
    int count_pos = 0, count_neg = 0; // кількість додатніх та від'ємних чисел

    // заповнюємо масив випадковими значеннями
    srand(time(0)); // ініціалізуємо генератор випадкових чисел
    for (int i = 0; i < N; i++) {
        arr[i] = -2.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (4.0))); // генеруємо випадкове число з діапазону (-2, 2)
    }

    // знаходимо кількість додатніх та від'ємних чисел
    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) {
            count_pos++;
        } else if (arr[i] < 0) {
            count_neg++;
        }
    }

    // виводимо результати
    std::cout << "Кількість додатніх чисел: " << count_pos << std::endl;
    std::cout << "Кількість від'ємних чисел: " << count_neg << std::endl;

    delete[] arr; // звільняємо пам'ять, виділену для масиву
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if(num < 2) // якщо число менше за 2, то воно не є простим
        return false;
    for(int i = 2; i <= sqrt(num); i++) { // перевіряємо подільність нашого числа на всі числа від 2 до його квадратного кореня
        if(num % i == 0)
            return false; // якщо знайшли дільник, то число не є простим
    }
    return true; // якщо не знайшли жодного дільника, то число є простим
}

int main(void) {
    for(int i = 0; i <= 21; i++) {
        if(isPrime(i))
            cout << i << " ";
    }
    cout << endl;
    return 0;
}

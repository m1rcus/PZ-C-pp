#include <iostream>
using namespace std;

bool isLeap(int year) {
    bool isLeap(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

   
}

int monthLength(int year, int month) {
    int days;
    switch (month) {
        case 2:
            days = isLeap(year) ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 31;
            break;
    }
    return days;
}

int main(void) {
    for(int yr = 2000; yr < 2002; yr++) {
        for(int mo = 1; mo <= 12; mo++)
            cout << monthLength(yr,mo) << " ";
        cout << endl;
    }
    return 0;
}

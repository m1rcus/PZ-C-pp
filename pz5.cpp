#include <iostream>
#include <ctime>

using namespace std;

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int monthLength(int year, int month) {
    int daysInMonth[] = {31, 28 + isLeap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return daysInMonth[month - 1];
}

struct Date {
    int year;
    int month;
    int day;
};

Date today(void) {
    time_t t = time(NULL);
    tm tl = *localtime(&t);
    Date d = {tl.tm_year + 1900, tl.tm_mon + 1, tl.tm_mday};
    return d;
}

int daysBetween(Date d1, Date d2) {
    int days = 0;
    if (d1.year == d2.year && d1.month == d2.month) {
        return d2.day - d1.day;
    }
    // count days from d1's day to the end of that month
    days += monthLength(d1.year, d1.month) - d1.day + 1;
    // count days for whole months between d1 and d2
    for (int m = d1.month + 1; m <= 12; m++) {
        days += monthLength(d1.year, m);
    }
    for (int y = d1.year + 1; y < d2.year; y++) {
        days += isLeap(y) ? 366 : 365;
    }
    for (int m = 1; m < d2.month; m++) {
        days += monthLength(d2.year, m);
    }
    // count days from the start of d2's month to d2's day
    days += d2.day - 1;
    return days;
}

int main() {
    Date d1 = {2003, 12, 30};
    Date d2 = today();
    int days = daysBetween(d1, d2);
    cout << "Days between " << d1.year << "-" << d1.month << "-" << d1.day
         << " and " << d2.year << "-" << d2.month << "-" << d2.day << " is " << days << endl;
    return 0;
}

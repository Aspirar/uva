#include <iostream>
#include <ctime>
using namespace std;

bool isLeap(int year) {
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

int main() {
    while(true) {
        int days, day, month, year;
        cin >> days >> day >> month >> year;
        if (days == 0 && day == 0 && month == 0 && year == 0) break;

        struct tm date = { 0, 0, 12 };
        date.tm_year = year - 1900;
        date.tm_mon = month - 1;
        date.tm_mday = day;
        time_t oneday = 24 * 60 * 60;
        time_t seconds = mktime(&date) + (days * oneday);
        date = *localtime(&seconds);

        cout << date.tm_mday << " " << date.tm_mon + 1 << " " << date.tm_year + 1900 << endl;
    }
}

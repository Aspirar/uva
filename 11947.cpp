#include <iostream>
#include <ctime>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int T = 1; T <= t; T++) {
        int num;
        cin >> num;

        int year = num % 10000;
        num = num / 10000;
        int day = num % 100;
        num = num / 100;
        int month = num;

        struct tm date = { 0, 0, 12 };
        date.tm_year = year - 1900;
        date.tm_mon = month - 1;
        date.tm_mday = day;
        time_t fortyweeks = 40 * 7 * 24 * 60 * 60;
        time_t seconds = mktime(&date) + (fortyweeks);
        date = *localtime(&seconds);

        year = date.tm_year + 1900;
        month = date.tm_mon + 1;
        day = date.tm_mday;

        string sign;
        if ((month == 1 && day >= 21) || (month == 2 && day <= 19)) sign = "aquarius";
        if ((month == 2 && day >= 20) || (month == 3 && day <= 20)) sign = "pisces";
        if ((month == 3 && day >= 21) || (month == 4 && day <= 20)) sign = "aries";
        if ((month == 4 && day >= 21) || (month == 5 && day <= 21)) sign = "taurus";
        if ((month == 5 && day >= 22) || (month == 6 && day <= 21)) sign = "gemini";
        if ((month == 6 && day >= 22) || (month == 7 && day <= 22)) sign = "cancer";
        if ((month == 7 && day >= 23) || (month == 8 && day <= 21)) sign = "leo";
        if ((month == 8 && day >= 22) || (month == 9 && day <= 23)) sign = "virgo";
        if ((month == 9 && day >= 24) || (month == 10 && day <= 23)) sign = "libra";
        if ((month == 10 && day >= 24) || (month == 11 && day <= 22)) sign = "scorpio";
        if ((month == 11 && day >= 23) || (month == 12 && day <= 22)) sign = "sagittarius";
        if ((month == 12 && day >= 23) || (month == 1 && day <= 20)) sign = "capricorn";

        cout << T << " ";
        printf("%02d/%02d/%04d", month, day, year);
        cout << " " << sign << endl;
    }
}

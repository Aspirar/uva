#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        int duration, records;
        double down, amount;
        cin >> duration >> down >> amount >> records;
        if (duration < 0) break;

        double rates[120];
        fill_n(rates, 120, -1);
        for (int i = 0; i < records; i++) {
            int month;
            double rate;
            cin >> month >> rate;
            rates[month] = rate;
        }
        for (int i = 1; i <= duration; i++) {
            if (rates[i] == -1) rates[i] = rates[i-1];
        }

        double carValue = (down + amount) * (1 - rates[0]);
        double payment = amount / duration;

        if (carValue > amount) {
            cout << "0 months" << endl;
            continue;
        }

        for (int i = 1; i <= duration; i++) {
            carValue *= (1- rates[i]);
            amount -= payment;
            if (carValue > amount) {
                if (i == 1) {
                    cout << "1 month" << endl;
                } else {
                    cout << i << " months" << endl;
                }
                break;
            }
        }
    }
}

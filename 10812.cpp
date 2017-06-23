#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int sum, diff;
        cin >> sum >> diff;

        int a = (sum + diff) /  2;
        if (2 * a != (sum + diff)) {
            cout << "impossible" << endl;
            continue;
        }

        int b = sum - a;
        if (b < 0) {
            cout << "impossible" << endl;
        }
        else {
            if (a < b) {
                int temp = a;
                a = b;
                b = temp;
            }
            cout << a << " " << b << endl;
        }
    }
}

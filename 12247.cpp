#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        if (a == 0 && b == 0 && c == 0 && x == 0 && y == 0) break;

        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }


        int arr[] = { a, b, c };
        sort(arr, arr + 3);

        int losses = 0;

        if (y < arr[0]) {
            arr[0] = 100000000;
            losses++;
        } else if (y < arr[1]) {
            arr[1] = 100000000;
            losses++;
        } else if (y < arr[2]) {
            arr[2] = 100000000;
            losses++;
        }

        if (losses == 0) {
            arr[0] = 100000000;
        }

        sort(arr, arr + 3);

        if (x < arr[0]) {
            arr[0] = 100000000;
            losses++;
        } else if (x < arr[1]) {
            arr[1] = 100000000;
            losses++;
        } else {
            arr[0] = 100000000;
        }
        sort(arr, arr + 3);

        if (losses == 2) {
            cout << -1 << endl;
        } else if (losses == 0) {
            int ans = 1;
            while (ans == a || ans == b || ans == c || ans == x || ans == y) {
                ans++;
            }
            if (ans <= 52) cout << ans << endl;
            else cout << -1 << endl;
        } else {
            int ans = arr[0] + 1;
            while (ans == a || ans == b || ans == c || ans == x || ans == y) {
                ans++;
            }
            if (ans <= 52) cout << ans << endl;
            else cout << -1 << endl;
        }
    }
}

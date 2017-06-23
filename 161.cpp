#include <iostream>
#include <vector>
using namespace std;

char getLightState(int light, int time) {
    int ratio = time / light;
    if (ratio % 2 != 0) return 'R';
    int orangeTime = light * (ratio + 1) - 5;
    if (time < orangeTime) return 'G';
    return 'O';
}

int main() {
    while (true) {
        vector< int > lights(3);
        cin >> lights[0] >> lights[1] >> lights[2];
        if (lights[0] == 0 && lights[1] == 0 && lights[2] == 0) break;

        bool more = true;
        if (lights[2] == 0) {
            more = false;
            lights.pop_back();
        } 

        if (more) {
            while (true) {
                int a;
                cin >> a;
                if (a == 0) break;
                lights.push_back(a);
            }
        }

        int minTime = 100000000;
        for (int i = 0; i < lights.size(); i++) {
            if (lights[i] < minTime) minTime = lights[i];
        }
        minTime -= 5;

        bool found = false;
        int time;
        for (time = minTime; time <= 5 * 60 * 60; time++) {
            bool allgreen = true;
            for (int i = 0; i < lights.size(); i++) {
                if (getLightState(lights[i], time) != 'G') {
                    allgreen = false;
                    break;
                }
            }
            if (allgreen) {
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Signals fail to synchronise in 5 hours" << endl;
            continue;
        }

        int seconds = time % 60;
        int minutes = time / 60;
        int hours = minutes / 60;
        minutes = minutes % 60;

        if (hours == 0) cout << "00";
        else if (hours <= 9) cout << "0" << hours;
        else cout << hours;
        cout << ":";
        if (minutes == 0) cout << "00";
        else if (minutes <= 9) cout << "0" << minutes;
        else cout << minutes;
        cout << ":";
        if (seconds == 0) cout << "00";
        else if (seconds <= 9) cout << "0" << seconds;
        else cout << seconds;
        cout << endl;
    }
}

#include <iostream>
#include <string>
using namespace std;

int main() {
    while (true) {
        int round;
        cin >> round;
        if (round == -1) break;

        string answer;
        cin >> answer;

        int ans[200] = { };
        for (int i = 0; i < answer.size(); i++) {
            char ch = answer[i];
            ans[ch] = 1;
        }

        string guesses;
        cin >> guesses;

        int wrong = 0;
        for (int i = 0; i < guesses.size(); i++) {
            char ch = guesses[i];
            if (!ans[ch]) wrong++;
            else ans[ch] = 2;
            if (wrong >= 7) break;
        }

        bool right = true;
        for (int i = 0; i < answer.size(); i++) {
            char ch = answer[i];
            if (ans[ch] != 2) {
                right = false;
                break;
            }
        }

        cout << "Round " << round << endl;
        if (right == true) {
            cout << "You win." << endl;
        } else if (wrong >= 7) {
            cout << "You lose." << endl;
        } else {
            cout << "You chickened out." << endl;
        }
    }
}

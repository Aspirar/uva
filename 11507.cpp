#include <iostream>
#include <string>
using namespace std;

string map(string current, string bend) {
    if (current == "+x") {
        return bend;
    }
    if (current == "-x") {
        if (bend[0] == '+') bend[0] = '-';
        else bend[0] = '+';
        return bend;
    }
    if (current == "+y") {
        if (bend == "+y") return "-x";
        if (bend == "-y") return "+x";
        return "+y";
    }
    if (current == "-y") {
        if (bend == "+y") return "+x";
        if (bend == "-y") return "-x";
        return "-y";
    }
    if (current == "+z") {
        if (bend == "+z") return "-x";
        if (bend == "-z") return "+x";
        return "+z";
    }
    if (bend == "+z") return "+x";
    if (bend == "-z") return "-x";
    return "-z";
}

int main() {
    while (true) {
        int l;
        cin >> l;
        if (l == 0) break;

        string current = "+x";
        for (int i = 0; i < l-1; i++) {
            string bend;
            cin >> bend;
            if (bend != "No") current = map(current, bend);
        }
        cout << current << endl;
    }
}

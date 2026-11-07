#include <iostream>
// #include <vector>
using namespace std;

int main() {
    string jam;
    string AMPM;
    cin >> jam >> AMPM;

    // vector<int> jamCount(24, 0);

    // for (int i = 0; i < 3; i++) {
    //     jamCount[jam[i]]++;
    // }

    int jamMiliter;
    if (AMPM == "PM") {
         jamMiliter = stoi(jam) + 12;
         if (jamMiliter == 24) {
            cout << "00";
        }else {
            cout << jamMiliter;
        }

        for (int i = 2; i < jam.length(); i++) {
            cout << jam[i];
        }
    }else {
        cout << jam;
    }

    return 0;
    }

    
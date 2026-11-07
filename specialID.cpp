#include <iostream>
#include <vector>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    vector<pair<int, int>> queries(Q);
    int maxR = 0;

    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        queries[i] = {L, R};

        if (R > maxR) {
            maxR = R;
        }
    }

    vector<bool> prima(maxR + 1, true);

    prima[0] = false;
    if (maxR >= 1) {
        prima[1] = false;
    }

    for (int i = 2; i * i <= maxR; i++) {
        if (prima[i]) {
            for (int j = i * i; j <= maxR; j += i) {
                prima[j] = false;
            }
        }
    }

    vector<int> prefix(maxR + 1, 0);

    for (int i = 1; i <= maxR; i++) {
        prefix[i] = prefix[i - 1];

        if (prima[i]) {
            prefix[i]++;
        }
    }

    for (int i = 0; i < Q; i++) {
        int L = queries[i].first;
        int R = queries[i].second;

        cout << prefix[R] - prefix[L - 1] << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int s, i, e;
        cin >> s >> i >> e;
        cout << (e == 0 ? 1 : min((s + e - i) / 2 + (s + e - i) % 2, e)) << endl;
    }
    return 0;
}
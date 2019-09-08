#include <bits/stdc++.h>
using namespace std;
int main () {
    int t; cin >> t;
    while(t--) {
        int s, i, e; cin >> s >> i >> e;
        cout << min((s + e - i) / 2 + ((s + e - i) % 2 == 1), e + 1) << endl;
    }
    return 0;
}
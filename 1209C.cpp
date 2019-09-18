#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        int i = 1;
        for(; i < s.size() && s[i] >= s[i - 1]; i++);
        if(i == s.size()) {
            cout << string(n, '1') << endl;
            continue;
        }

        auto it = upper_bound(s.begin(), s.begin() + i, s[i]);
        char mid = *it;

        int e1 = s[i - 1], e2 = s[i];
        bool ok = true;
        string result(n, '1');
        for(int j = it - s.begin(); j < i; j++) result[j] = '2';
        for(i = i + 1; i < s.size() && ok; i++) {
            if(s[i] >= mid && s[i] >= e1) {
                e1 = s[i];
                result[i] = '2';
            }
            else if(s[i] <= mid && s[i] >= e2) {
                e2 = s[i];
            }
            else {
                ok = false;
            }
        }

        cout << (ok ? result : "-") << endl;
    }
    return 0;
}
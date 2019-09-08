#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, t; cin >> s >> t;
    vector<int> a(t.size(), 0), b(t.size(), 0);
    for(int i = 0, j = 0; i < s.size(); i++) {
        if(s[i] == t[j]) {
            a[j++] = i;
        }
    }
    for(int i = s.size() - 1, j = t.size() - 1; i >= 0; i--) {
        if(s[i] == t[j]) {
            b[j--] = i;
        }
    }

    int ans = 0;
    a.insert(a.begin(), -1); b.insert(b.begin(), -1); a.push_back(s.size()); b.push_back(s.size());
    for(int i = 0; i < a.size() - 1; i++) {
        ans = max(ans, b[i + 1] - a[i] - 1);
    }

    cout << ans << endl;
}
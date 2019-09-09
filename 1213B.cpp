#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        set<int> s;
        int ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(!s.empty() && *s.begin() > v[i]) ans++;
            s.insert(v[i]);
        }

        cout << ans << endl;
    }
}
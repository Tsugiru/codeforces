#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    unordered_set<int> s;
    int pre = 0;
    for(; pre < n && !s.count(v[pre]); pre++) {
        s.insert(v[pre]);
    }

    pre--;
    int ans = n - pre - 1;
    for(int i = n - 1; i > pre && pre >= 0; i--) {
        while(s.count(v[i]) && pre >= 0 && v[pre] != v[i]) {
            s.erase(v[pre--]);
        }
        if(s.count(v[i]) && pre >= 0) s.erase(v[pre--]);
        ans = min(ans, i - pre - 1);
        s.insert(v[i]);
    }

    s.clear();
    for(int i = n - 1; i >= 0 && !s.count(v[i]); i--) {
        s.insert(v[i]);
        ans = min(ans, i);
    }

    cout << ans << endl;
    return 0;
}
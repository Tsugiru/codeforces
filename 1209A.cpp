#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++) {
        int k; cin >> k; s.insert(k);
    }

    int ans = 0;
    while(s.size() != 0) {
        ans++;
        int cur = *s.begin(); s.erase(s.begin());
        for(int i = 2; cur*i <= 100; i++) {
            auto it = s.find(cur*i);
            if(it != s.end()) s.erase(it);
        }
    }

    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r; cin >> n >> r;
    vector<pair<int, int>> pos;
    multimap<int, int> neg;
    for(int i = 0, a = 0, b = 0; i < n; i++) {
        cin >> a >> b;
        if(b <= 0) neg.insert({a, b});
        else pos.push_back({a, b});
    }
    sort(pos.begin(), pos.end());

    bool ok = true;
    for(int i = 0; i < pos.size(); i++) {
        if(r < pos[i].first) {
            ok = false;
            break;
        }
        r += pos[i].second;
    }

    while(neg.size()) {
        int cur = neg.rbegin()->first, t = neg.rbegin()->second;
        auto pos = neg.upper_bound(r + t);
        if(pos == neg.end()) {
            r += t;
            pos--;
            neg.erase(pos);
        }
        else {
            while(r >= cur && pos != neg.end()) {
                r += pos->second;
                pos = neg.erase(pos);
            }
            if(pos != neg.end()) {
                ok = false;
                break;
            }
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
}
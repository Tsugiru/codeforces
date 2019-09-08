#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> cnt;
    for(int i = 0, t = 0; i < n; i++) {
        cin >> t;
        cnt[t]++;
    }

    vector<int> v(150010, 0);
    for(auto & elem : cnt) {
        if(elem.second >= 3) {
            v[elem.first - 1] = v[elem.first] = v[elem.first + 1] = 1;
        }
        else if(elem.second == 2) {
            v[elem.first] = 1;
            if(v[elem.first - 1] != 1 && elem.first != 1) v[elem.first - 1] = 1;
            else v[elem.first + 1] = 1;
        }
        else {
            if(v[elem.first - 1] != 1 && elem.first != 1) v[elem.first - 1] = 1;
            else if(v[elem.first] != 1) v[elem.first] = 1;
            else v[elem.first + 1] = 1;
        }
    }

    int ans = accumulate(v.begin() + 1, v.end(), 0);
    cout << ans << endl;
}
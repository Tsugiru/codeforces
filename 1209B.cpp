#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    vector<pair<int, int>> v(n, {0, 0});
    vector<int> next(v.size(), 0);
    for(int i = 0 ; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        next[i] = v[i].second;
    }

    int ans = count(s.begin(), s.end(), '1');
    for(int i = 0; i < 1000; i++) {
        for(int q = 0; q < v.size(); q++) {
            if(i == next[q]) {
                s[q] = s[q] == '1' ? '0' : '1';
                next[q] += v[q].first;
            }
        }
        ans = max(ans, (int)count(s.begin(), s.end(), '1'));
    }

    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<int> s(m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int j = 0; j < m; j++) {
        cin >> s[j];
    }

    int ans = 0;
    for(int j = 0; j < m; j++) {
        vector<int> cnt(5, 0);
        for(int i = 0; i < n; i++) {
            cnt[a[i][j] - 'A']++;
        }
        ans += *max_element(cnt.begin(), cnt.end()) * s[j];
    }

    cout << ans << endl;
    return 0;
}

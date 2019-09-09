#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    vector<pair<int, int>> ans;
    vector<vector<int>> B(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n && j + 1 < m && A[i][j] && A[i + 1][j] && A[i][j + 1] && A[i + 1][j + 1]) {
                ans.push_back({i, j});
                B[i][j] = B[i + 1][j] = B[i][j + 1] = B[i + 1][j + 1] = 1;
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j]) {
                ok = false;
                break;
            }
        }
    }

    if (!ok)
        cout << -1 << endl;
    else {
        cout << ans.size() << endl;
        for (auto& elem : ans) {
            cout << elem.first + 1 << " " << elem.second + 1 << endl;
        }
    }
    return 0;
}
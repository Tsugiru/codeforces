#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    for(int i = 0; i < n; i++) {
        bool ok = true;
        for(int j = max(0, i - x); j <= min(n - 1, i + y) && ok; j++) {
            if(i != j && A[j] <= A[i]) {
                ok = false;
            }
        }
        if(ok) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}
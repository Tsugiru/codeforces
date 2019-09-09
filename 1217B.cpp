#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        int m = 0, best = 0;
        for(int i = 0, a = 0, b = 0; i < n; i++) {
            cin >> a >> b;
            m = max(m, a);
            best = max(best, a - b);
        }
        if(best == 0 && m < x) cout << -1 << endl;
        else if(best == 0 && m >= x) cout << 1 << endl;
        else cout << max(0, x - m) / best + (max(0, x - m) % best != 0) + 1 << endl;
    }
}
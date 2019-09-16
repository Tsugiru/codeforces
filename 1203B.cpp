#include<bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        vector<int> v(4*n);
        for(int i = 0; i < v.size(); i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        bool ok = true;
        for(int i = 0, j = v.size() - 1, prod = v[0] * v.back(); i < j; i += 2, j -= 2) {
            if(v[i] * v[j] != prod || v[i + 1] != v[i] || v[j - 1] != v[j]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &v) {
    for(int i = 0; i < v.size() - 1; i++) {
        if(v[i] != v[i + 1] - 1 && v[i + 1] != 1) return false;
    }
    return true;
}

int main() {
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        vector<int> rv(v.rbegin(), v.rend());
        if(check(v) || check(rv)) cout << "YES" <<endl;
        else cout << "NO" << endl;
    }
}
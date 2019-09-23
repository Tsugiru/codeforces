#include <bits/stdc++.h>
using namespace std;

vector<long long> divisors(long long x) {
    vector<long long> res;
    for(long long i = 1; i <= sqrt(x); i++) {
        if(x % i == 0) {
            res.push_back(i);
            if(x / i != i) res.push_back(x/i);
        }
    }
    return res;
}

int main() {
    long long n; cin >> n;
    vector<long long> v(n, 0);
    for(long long i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long mx = *max_element(v.begin(), v.end());
    auto it = find_if(v.begin(), v.end(), [&mx](long long elem){ return elem != mx; });

    if (it == v.end()) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }

    long long k = mx - *it;
    vector<long long> ds = divisors(k);
    sort(ds.rbegin(), ds.rend());
    long long y = 0, z = 0;
    for(long long d : ds) {
        bool ok = true; 
        long long ty = 0;
        for(long long x : v) {
            if((mx - x) % d != 0) {
                ok = false;
                break;
            }
            ty += (mx - x) / d;
        }
        if(ok) {
            y = ty;
            z = d;
            break;
        }
    }

    cout << y << " " << z << endl;
}
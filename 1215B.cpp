#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, neg = 0, pos = 0; cin >> n;
    for(ll i = 0, cur = 0, odd = 0, even = 0, count = 0; i < n; i++) {
        cin >> cur;
        if(cur < 0) count++;
        odd += count & 1 ? 1 : 0;
        even += count & 1 ? 0 : 1;
        neg += (count & 1) ? even + 1 : odd;
        pos += (count & 1) ? odd - 1: even;
    }

    cout << neg << " " << pos << endl;
    return 0;
}
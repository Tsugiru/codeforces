#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n = 0, zeros = 0, neg = 0, ans = 0;
    cin >> n;
    for(int i = 0, x = 0; i < n; i++) {
        cin >> x;
        if(x > 0) ans += (x - 1);
        else if(x < 0) {
            ans += (-x - 1);
            neg ^= 1;
        }
        else {
            ans++;
            zeros |= 1;
        }
    }
    cout << ans + (neg && !zeros ? 2 : 0) << endl;
}

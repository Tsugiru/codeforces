#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int b, p, f, h, c; cin >> b >> p >> f >> h >> c;
        int ans = 0;
        if(c > h) {
            swap(h, c);
            swap(p, f);
        }
        ans += h * min(b/2, p);
        b -= 2*p;
        if(b > 0) {
            ans += c * min(b/2, f);
        }
        cout << ans << endl;
    } 
    return 0;
}
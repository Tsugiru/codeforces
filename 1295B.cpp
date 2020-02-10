#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        vector<int> pre(n + 1, 0);
        int mn = 0, mx = 0;
        for(int i = 0; i < n; i++) {
            char c; cin >> c;
            pre[i + 1] = pre[i] + (c == '1' ? -1 : 1);
            mn = min(mn, pre[i + 1]);
            mx = max(mx, pre[i + 1]);
        }

        if(pre[n] == 0) {
            cout << (x <= mx && x >= mn ? -1 : 0) << endl;
            continue;
        }

        int ans = 0; 
        for(int i = 1; i < n + 1; i++) {
            if((x - pre[i] == 0 || (x - pre[i] > 0) == (pre[n] > 0)) && (x - pre[i]) % pre[n] == 0)
                ans++;
        } 
        
        cout << ans + !x << endl;
    }
}
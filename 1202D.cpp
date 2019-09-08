#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    vector<ll> v(100000, 0);
    for(ll i = 0; i < v.size(); i++) v[i] = i * (i - 1) / 2;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int ones = 1, sevens = 1, threes = 2;
        if(*lower_bound(v.begin(), v.end(), n) != n) {
            auto it = upper_bound(v.begin(), v.end(), n / 2); it--;
            while(it != v.begin() && n % *it != 0) it--;
            int rem = it == v.begin() ? n : n / *it; threes = it - v.begin();
            for(int i = sqrt(rem); i >= 2; i--) {
                if(rem % i == 0) {
                    ones = rem / i;
                    sevens = i;
                }
            }
        }
        else {
            threes = lower_bound(v.begin(), v.end(), n) - v.begin();            
        }
        string s = "";
        for(int i = 0; i < ones; i++) s += '1';
        for(int i = 0; i < threes; i++) s += '3';
        for(int i = 0; i < sevens; i++) s += '7';
        cout << s << endl;
    }
    return 0;
}
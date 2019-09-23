#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    string s; cin >> s; 
    int ans = 0;
    for(int i = 0, j = 0, a = 0, b = 0; i < s.size(); i++) {
        a += s[i] == 'a' ? 1 : 0;
        b += s[i] == 'b' ? 1 : 0;
        while(!((i+1)&1) && j <= i) {
            if(s[j] == 'a' && a > b) ans++, a--, b++, s[j] = 'b';
            else if(s[j] == 'b' && a < b) ans++, a++, b--, s[j] = 'a';
            j++;
        }
    }
    cout << ans << endl;
    cout << s << endl;
}
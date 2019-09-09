#include <bits/stdc++.h>
using namespace std;
int main() {
    long long T; cin >> T;
    while(T--) {
        long long n, a, b; cin >> n >> a >> b;
        string s; cin >> s;

        vector<long long> next_one(n, 0);
        for(int i = s.find_first_of('1'), j = 0; i != string::npos; j = i, i = s.find_first_of('1', i + 1))
                next_one[j] = i;

        if(next_one.front() == 0) {
            cout << n*a + (n + 1)*b << endl;
            continue;
        } 

        long long ans = (next_one.front() + 2) * a + (next_one.front() + 2) * b;
        long long i = 0;
        for(i = next_one.front(); next_one[i] != 0; i = next_one[i]) {
            long long diff = next_one[i] - i;
            ans += min(diff*a + diff*2*b, (diff+2)*a + (diff+2)*b);
        }
        ans += (n - i) * a + (n - i + 1) * b;

        cout << ans << endl;
    }
    return 0;
}
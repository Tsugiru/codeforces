#include <bits/stdc++.h>
using namespace std;
int main() {
    long long q; cin >> q;
    while(q--) {
        long long n, m; cin >> n >> m;
        long long sum = 0;
        for(long long i = m; i <= m*10; i += m) {
            sum += i % 10;
        }

        long long rest = n % (m * 10);
        long long sum2 = 0;
        for(long long i = m; i <= rest; i += m) {
            sum2 += i % 10;
        }

        cout << sum * (n / (m*10)) + sum2 << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, e; cin >> n >> d >> e;
    int result = n;
    if(n < d && n < 5*e) {
        cout << n << endl;
        return 0;
    }
    for(int k = n / (5 *e), r = (n - k * 5 * e) / d; k >= 0; k--, r = (n - k * 5 * e) / d) {
        result = min(result, n % (k * 5 * e + r * d));
    }
    cout << result << endl;
    return 0;
}
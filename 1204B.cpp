#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l ,r; cin >> n >> l >> r;
    long long top = 0, down = 0, k1 = 1;
    for(int i = 0; i < r; i++, k1 *= 2) top += k1;
    for(int i = 0, k2 = 1; i < l; i++, k2 *= 2) down += k2;
    down += (n - l);
    top += (n - r) * k1 / 2;
    cout << down  << " " << top << endl;
    return 0;
}

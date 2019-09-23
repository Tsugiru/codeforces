#include <bits/stdc++.h>
using namespace std;
int main() {
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    if(k1 < k2) swap(k1, k2), swap(a1, a2);

    int x = 0, y = 0, temp = n;
    x += min(a2, n/k2);
    n = max(n - a2*k2, 0);
    x += min(a1, n/k1);

    n = temp; 
    n = max(n - a1*(k1 - 1) - a2*(k2 - 1), 0);
    if(n > 0) y = min(a1 + a2, n);

    cout << y << " " << x << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    int b, g, n; cin >> b >> g >> n;
    if(b < n && g < n) {
        cout << g - (n - b) + 1 << endl;
    }
    else {
        cout << min(n, min(g, b)) + 1 << endl;
    }
    return 0;
}
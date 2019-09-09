#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; cin >> T;
    while(T--) {
        int a, b, n; cin >> a >> b >> n;
        cout << (n % 3 == 0 ? a : (n - 1) % 3 == 0 ? b : (n - 2) % 3 == 0 ? a ^ b : -1) << endl; 
    }
}
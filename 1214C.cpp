#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    char c;
    int count = 0;
    for(int i = 0; i < n; i++) {
        cin >> c;
        count += c == '(' ? 1 : -1;
        if(count < -1) {
            cout << "No" << endl;
            return 0;
        }
    }
    if(count != 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
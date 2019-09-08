#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        string x, y; cin >> x >> y;
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        int ypos = y.find_first_of('1', 0);
        if(ypos >= x.size()) cout << 0 << endl;
        else cout << x.find_first_of('1', ypos) - ypos << endl;
    }
    return 0;
}
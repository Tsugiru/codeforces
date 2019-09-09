#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int result = 0;
        for(int i = s.find_first_of('1'), prev = -1; i != string::npos; prev = i, i = s.find_first_of('1', i + 1)) {
            int count = 0;
            for(int j = i; count <= j - prev && j < s.size() && j <= i + 20; j++) {
                count <<= 1;
                if(s[j] == '1') count += 1;
                if(count <= j - prev) result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}

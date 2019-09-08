#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int x = (s.size() - 1) & 1;
    cout << (s.size() + 1) / 2 - (((s.size() - 1) & 1) == 0 && s.find_first_of('1', 1) == string::npos ? 1 : 0) << endl;
    return 0;
}
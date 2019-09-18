#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;

void f(string &s, string &t, vpii &result, char first, char second) {
    for(int i = 0, prev = -1; i < s.size(); i++) {
        if(s[i] == first && t[i] == second) {
            if(prev == -1) prev = i;
            else {
                swap(t[prev], s[i]);
                result.push_back({prev, i});
                prev = -1;
            }
        }
    }


}

int main() { 
    int n; cin >> n;
    string s, t; cin >> s >> t;

    vpii result;
    f(s, t, result, 'a', 'b');
    f(s, t, result, 'b', 'a');

    auto it1 = find_if(s.begin(), s.end(), [&, i = 0](char c)mutable{ return c != t[i++]; });
    auto it2 = find_if(it1 + 1, s.end(), [&, i = it1 - s.begin() + 1](char c)mutable{ return c != t[i++]; });

    if(it1 != s.end() && it2 == s.end()) {
        cout << -1 << endl;
    }
    else {
        cout << result.size() + (it1 != s.end() ? 2 : 0) << endl;
        for(auto &p : result)
            cout << p.first + 1 << " " << p.second + 1 << endl;

        if(it1 != s.end()) {
            cout << it1 - s.begin() + 1 << " " << it1 - s.begin() + 1 << endl;
            cout << it2 - s.begin() + 1 << " " << it1 - s.begin() + 1 << endl;
        }
    }
}
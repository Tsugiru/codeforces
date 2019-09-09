#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int M = 998244353;

bool sorted(vector<pii> &v) {
    for(int i = 1; i < v.size(); i++) {
        if(v[i].second < v[i - 1].second) return false;
    }
    return true;
}

long long factorial(int n) {
    int prod = 1;
    for(int i = 1; i <= n; i++) {
        prod *= i;
        prod %= M;
    }
    return prod;
}

int main() {
    int n; cin >> n;
    vector<pii> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), [](pii &a, pii &b) { return a.first < b.first; });
    long long ans = 0;
    unordered_map<int, int> cnt1, cnt2;
    for(int i = 1, prev = 0; i < v.size(); i++) {
        cnt1[v[i].first]++;
        if(v[i].first != v[i - 1].first) {
            sort(v.begin() + prev, v.begin() + i, [](pii &a, pii &b) { return a.second < b.second; });
        }
    }
    for(auto &p : v) cnt2[p.second]++;
    for(auto &p : cnt1) {
        ans = (factorial(p.second) - 1 + ans) % M;
    }
    for(auto &p : cnt2) {
        ans = (factorial(p.second) - 1 + ans) % M;
    }

    if(sorted(v)) {
        
    }
    else {
        cout << ans << endl;
    }
    return 0;
}
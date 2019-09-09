#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    unordered_map<int, int> cost, cnt;
    int cur = INT_MAX;
    for(int i = 0; i < v.size(); i++) {
        int op = 0;
        while(true) {
            cost[v[i]] += op++;
            cnt[v[i]]++;
            if(cnt[v[i]] == k && cost[v[i]] < cur) {
                cur = cost[v[i]];
            }
            if(v[i] == 0) break;
            v[i] /= 2;
        }
    }

   cout << cur << endl;
    return 0;
}
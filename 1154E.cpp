#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

struct int_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct pair_hash {
    size_t operator()(pair<int, int> x) const {
        return int_hash{}(x.first) ^ (int_hash{}(x.second) << 16);
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const int inf = 1e7;
const int MX = 100001; //check the limits, dummy


class Solution {
private:
    int check(vector<vector<int>> &workers, vector<vector<int>> &bikes) {
        int result = 0;
        for(int i = 0; i < workers.size(); i++) {
            if(!workers[i].empty()) {
                result += abs(workers[i][0] - bikes[i][0]) + abs(workers[i][1] - bikes[i][1]);
            }
        }
        return result;
    }
    
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        while(workers.size() < bikes.size()) workers.push_back({});
        sort(begin(workers), end(workers));
        int result = numeric_limits<int>::max();
        do {
            result = min(result, check(workers, bikes));
        } while(next_permutation(begin(workers), end(workers)));
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; cin >> n >> k;
    map<int, int> mp1;
    map<int, int> mp2;
    for(int i = 0; i < n; i++) {
        int in; cin >> in;
        mp1[i] = in;
        mp2[in] = i;
    }

    vector<int> result(n, 0);
    int turn = 1;
    while(!mp2.empty()) {
        pair<int, int> current = *mp2.rbegin();
        int val = current.first, pos = current.second;
        mp2.erase(val);

        auto it = mp1.find(pos);
        auto l = it;

        int cnt = 0;
        while(l != begin(mp1) && cnt != k) {
            l--;
            cnt++;
            mp2.erase(l->second);
            result[l->first] = turn;
        }

        it = mp1.erase(l, it);
        auto r = it; 
        r++;
        cnt = 0;
        while(r != end(mp1) && cnt != k) {
            mp2.erase(r->second);
            cnt++;
            result[r->first] = turn;
            r++;
        }

        mp1.erase(it, r);

        result[pos] = turn;
        turn = turn == 2 ? 1 : 2;
    }

    for(int &i : result) cout << i;
    cout << '\n';
}
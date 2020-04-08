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

bool isPalindrome(const string &str) {
    for(int i = 0, j = str.size() - 1; i < j; i++, j--)
        if(str[i] != str[j]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n >> m;
    unordered_set<string> s;
    vector<string> good;
    string mid = "";
    int count = 0;
    for(int i = 0; i < n; i++) {
        string str; cin >> str; 
        string rev = str;
        reverse(begin(rev), end(rev));
        if(s.count(rev)) {
            good.push_back(str);
            count += 2*m;
        }
        else s.insert(str);

        if(mid.empty() && isPalindrome(str)) {
            mid = str;
            count += m;
        }
    }

    string result(count, '$');
    for(int i = 0; i < good.size(); i++) {
        string rev = good[i];
        reverse(begin(rev), end(rev));
        copy(begin(good[i]), end(good[i]), begin(result) + i * m);
        copy(begin(rev), end(rev), end(result) - (i + 1) * m);
    }

    if(!mid.empty()) copy(begin(mid), end(mid), begin(result) + good.size() * m);

    cout << count << endl;
    cout << result << endl;
}
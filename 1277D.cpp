#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

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
    size_t operator()(pii x) const {
        return int_hash{}(x.first) ^ (int_hash{}(x.second) << 16);
    }
};

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<cd> vcd;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
typedef vector<vvi> vvvi;
typedef unordered_map<int, int, int_hash> umii;
typedef unordered_map<ll, ll, int_hash> umll;
typedef unordered_set<int, int_hash> usi;
typedef unordered_set<ll, int_hash> usll;
typedef unordered_set<pii, pair_hash> uspii;
typedef queue<int> qi;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const int inf = numeric_limits<int>::max();
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        unordered_map<pair<int, int>, vector<int>, pair_hash> mp;
        unordered_set<string> st;
        vector<string> v(n);

        for(int i = 0; i < n; i++) {
            cin >> v[i];
            pair<int, int> key = {v[i][0] - '0', v[i][v[i].size() - 1] - '0'};
            mp[key].push_back(i);
            st.insert(v[i]);
        }

        if(!mp[{1, 1}].empty() && !mp[{0, 0}].empty() 
            && mp[{0, 1}].empty() && mp[{1, 0}].empty()) {
            cout << -1 << endl;
            continue;
        }

        pair<int, int> p1 = {0, 1};
        if(mp[{0, 1}].size() < mp[{1, 0}].size()) 
            swap(p1.first, p1.second);

        vector<int> result;
        int s1 = mp[p1].size(), s2 = mp[{p1.second, p1.first}].size();
        for(int i = 0; s1 > s2 + 1 && i < mp[p1].size(); i++) {
            string cur = v[mp[p1][i]];
            reverse(begin(cur), end(cur));
            if(!st.count(cur)) {
                s1--;
                s2++;
                result.push_back(mp[p1][i]);
            }
        }

        if(s1 > s2 + 1) {
            cout << -1 << endl;
        }
        else {
            cout << result.size() << endl;
            for(int i : result) cout << i + 1 << " ";
            cout << endl;
        }
    }
}
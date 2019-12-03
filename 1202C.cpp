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
typedef vector<vector<ll>> vvl;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
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
        string s; cin >> s;
        ll minx = 0, miny = 0, maxx = 0, maxy = 0;
        ll x = 0, y = 0;
        unordered_map<char, pii> dir{ {'W', {-1, 0}}, {'A', {0, -1}}, {'S', {1, 0}}, {'D', {0, 1}}};
        for(char c : s) {
            pii cur = dir[c];
            x += cur.f;
            y += cur.s;

            minx = min(x, minx);
            miny = min(y, miny);
            maxx = max(x, maxx);
            maxy = max(y, maxy);
        }

        pii iminx {-1, -1}, imaxx {-1, -1}, 
            iminy {-1, -1}, imaxy {-1, -1};
        x = y = 0;
        for(int i = 0; i < sz(s); i++) {
            char c = s[i];
            pii cur = dir[c];
            x += cur.f;
            y += cur.s;

            if(x == minx) {
                iminx.s = i;
                if(iminx.f == -1) iminx.f = i;
            }
            if(x == maxx) {
                imaxx.s = i;
                if(imaxx.f == -1) imaxx.f = i;
            }
            if(y == miny) {
                iminy.s = i;
                if(iminy.f == -1) iminy.f = i;
            }
            if(y == maxy) {
                imaxy.s = i;
                if(imaxy.f == -1) imaxy.f = i;
            }
        }

        ll diffx = maxx - minx + 1;
        ll diffy = maxy - miny + 1;
        bool canx = max(iminx.f, imaxx.f) > min(iminx.s, imaxx.s) && diffx > 2;
        bool cany = max(iminy.f, imaxy.f) > min(iminy.s, imaxy.s) && diffy > 2;

        cout << diffx * diffy - (canx && cany ? max(diffx, diffy) : canx ? diffy : cany ? diffx : 0) << endl;
    }
}
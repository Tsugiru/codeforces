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

class Solution {
public:
    pair<int, int> num_to_ind(int num, int n) {
        int row = n - num / n - 1;
        int col = (num / n) & 1 ? n - (num % n) - 1 : (num % n);
        return { row, col };
    }
    
    int solve(int pos, vector<int> &vis, vector<int> &cache, const vector<vector<int>> &board) {
        int n = board.size();
        if(pos == n * n) {
            return 0;
        }
        if(vis[pos]) return -1;
        if(cache[pos] != -2) return cache[pos];
        
        vis[pos] = 1;
        int best = -1;
        for(int i = 1; i <= 6 && i + pos <= n * n; i++) {
            pair<int, int> inds = num_to_ind(pos + i - 1, n);
            int x = inds.first, y = inds.second;
            int next_pos = board[x][y] == -1 ? pos + i : board[x][y];
            int ret = solve(next_pos, vis, cache, board);
            if(ret != -1) {
                best = best == -1
                    ? 1 + ret
                    : min(best, 1 + ret);    
            }
        }
        vis[pos] = 0;
        return cache[pos] = best;
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> cache(board.size() * board.size(), -2);
        vector<int> vis(board.size() * board.size(), 0);
        return solve(1, vis, cache, board);
    }
};

// [[-1,83,-1,46,-1,-1,-1,-1,40,-1],
//  [-1,29,-1,-1,-1,51,-1,18,-1,-1],
//  [-1,35,31,51,-1,6,-1,40,-1,-1],
//  [-1,-1,-1,28,-1,36,-1,-1,-1,-1],
//  [-1,-1,-1,-1,44,-1,-1,84,-1,-1],
//  [-1,-1,-1,31,-1,98,27,94,74,-1],
//  [4,-1,-1,46,3,14,7,-1,84,67],
//  [-1,-1,-1,-1,2,72,-1,-1,86,-1],
//  [-1,32,-1,-1,-1,-1,-1,-1,-1,19],
//  [-1,-1,-1,-1,-1,72,46,-1,92,6]]

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution s;
    vector<vector<int>> board
    {
 {-1,83,-1,46,-1,-1,-1,-1,40,-1},
 {-1,29,-1,-1,-1,51,-1,18,-1,-1},
 {-1,35,31,51,-1,6,-1,40,-1,-1},
 {-1,-1,-1,28,-1,36,-1,-1,-1,-1},
 {-1,-1,-1,-1,44,-1,-1,84,-1,-1},
 {-1,-1,-1,31,-1,98,27,94,74,-1},
 {4,-1,-1,46,3,14,7,-1,84,67},
 {-1,-1,-1,-1,2,72,-1,-1,86,-1},
 {-1,32,-1,-1,-1,-1,-1,-1,-1,19},
 {-1,-1,-1,-1,-1,72,46,-1,92,6}
    };
    s.snakesAndLadders(board);
// [[-1,83,-1,46,-1,-1,-1,-1,40,-1],
//  [-1,29,-1,-1,-1,51,-1,18,-1,-1],
//  [-1,35,31,51,-1,6,-1,40,-1,-1],
//  [-1,-1,-1,28,-1,36,-1,-1,-1,-1],
//  [-1,-1,-1,-1,44,-1,-1,84,-1,-1],
//  [-1,-1,-1,31,-1,98,27,94,74,-1],
//  [4,-1,-1,46,3,14,7,-1,84,67],
//  [-1,-1,-1,-1,2,72,-1,-1,86,-1],
//  [-1,32,-1,-1,-1,-1,-1,-1,-1,19],
//  [-1,-1,-1,-1,-1,72,46,-1,92,6]]
}
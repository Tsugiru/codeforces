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

int bfs(const vector<vector<int>> &friends, int source) {
    queue<int> q;
    q.push(source);
    vector<int> visited(friends.size(), 0);
    int result = 0, level_size = 1;
    while(!q.empty()) {
        while(level_size-- > 0) {
            int current = q.front(); q.pop();
            for(int next : friends[current]) {
                if(!visited[next]) {
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }
        level_size = q.size();
        result++;
    }
    return result - 1;
}

int compute_center(const vector<vector<int>> &friends) {
    vector<int> deg(friends.size());
    queue<int> q;
    for(int i = 0; i < friends.size(); i++) {
        deg[i] = friends[i].size();
        if(deg[i] == 1) q.push(i); // if current node is a leaf, push it
    }
    for(int i = 0; i < friends.size() - 1; i++) {
        int current = q.front(); q.pop();
        for(int next : friends[current]) {
            if(--deg[next] == 1) q.push(next);
        }
    }
    return friends.size() == 1 ? 0 : q.front();
}

int solution(const vector<vector<int>> &friends) {
    int best_score = numeric_limits<int>::max(), result = 0;
    for(int i = 0; i < friends.size(); i++) {
        if(int current_score = bfs(friends, i); best_score > current_score) {
            best_score = current_score;
            result = i;
        }
    }
    return result;
}

struct Zone {

};

int computeZoneDensity(Zone &z) {

}

int dp(const vector<int> &a, const vector<int> &b, int i, int flip, vector<vector<int>> &cache) {
    if(i == a.size()) return 0;
    if(cache[i][flip] != -2) return cache[i][flip];

    int pa = i > 0 ? a[i - 1] : -1, pb = i > 0 ?  b[i - 1] : -1;
    if(flip) swap(pa, pb);

    int res = -1;
    bool good = a[i] > pa && b[i] > pb, good_swapped = a[i] > pb && b[i] > pa;

    if(good) {
        res = dp(a, b, i + 1, 0, cache);
    }
    if(good_swapped) {
        int next = dp(a, b, i + 1, 1, cache);
        if(next != -1) res = res == -1 ? 1 + next : min(res, 1 + next);
    }

    return cache[i][flip] = res;
}

int relativelySorted(const vector<int> &a, const vector<int> &b) {
    vector<vector<int>> cache(a.size(), vector<int>(2, -2));
    return dp(a, b, 0, 0,cache);
}

int maxNonOverlapSubarraySum(int k, const vector<int> &v) {
    int res = 0;
    for(int i = 0, j = 0, sum = 0; i < v.size(); i++) {
        sum += v[i];
        while(sum > k) {
            sum -= v[j++];
        }
        if(sum == k) {
            res++;
            j = i + 1;
            sum = 0;
        }
    }
    return res;
}

class Solution {
public:
    struct TrieNode {
        unordered_map<char, TrieNode *> next;
        bool is_word = false;
    };
    
    struct Trie {
        TrieNode *root;
        
        Trie() {
            root = new TrieNode();
        }
        
        void insert(const string &s) {
            TrieNode *iter = root;
            for(char c : s) {
                if(!iter->next.count(c)) {
                    iter->next[c] = new TrieNode();
                }
                iter = iter->next[c];
            }
            iter->is_word = true;
        }
        
        bool contains(const string &s) {
            TrieNode *iter = root;
            for(char c : s) {
                if(!iter->next.count(c)) {
                    return false;
                }
                iter = iter->next[c];
            }
            return iter->is_word;
        }
    };
    
    Trie t;
    
    void dfs(TrieNode *cur, vector<int> &dp, string &str, vector<string> &res) {
        for(int i = 0; i < str.size(); i++) {
            if(t.contains(str.substr(i))) {
                dp[str.size()] = max(dp[i] + 1, dp[str.size()]);
            }
        }
        
        if(dp[str.size()] > 1 && cur->is_word) {
            res.push_back(str);
        }
    
        for(auto [c, node] : cur->next) {
            str += c;
            dfs(node, dp, str, res);
            str.pop_back();
        }
        
        dp[str.size()] = 0;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int maxlen = 0;
        
        for(const string &word : words) {
            if(!word.empty()) {
                t.insert(word);
            }
            maxlen = max(maxlen, (int)word.size());
        }
        
        vector<int> dp(maxlen + 1, 0);
        vector<string> res;
        string str = "";
        dfs(t.root, dp, str, res);
        sort(begin(res), end(res));
        return res;        
    }
};

class SolutionSlow {
public:
    bool solve(unordered_set<string> &st, const string &s) {
        vector<int> dp(s.size() + 1, 0);
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(st.count(s.substr(j, i - j))) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp.back() > 1;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> st(begin(words), end(words));
        st.erase("");
        for(const auto &word : words) {
            if(solve(st, word)) {
                res.push_back(word);
            }
        }

        sort(begin(res), end(res));
        return res;
    }
};

struct A {
    char x;
};

struct B {
    int x;
    int y;
    int z;
    int v;
    int arr[100] = {0};
};

int main() {
    Solution s;
    SolutionSlow ss;
    mt19937 rng;
    vector<string> in;

    A* a = new A();
    B* b = (B*)a;

    cout << b->arr[99] << endl;
}
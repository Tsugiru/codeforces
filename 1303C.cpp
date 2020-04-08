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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        vector<int> next(26, -1), prev(26, -1);

        if(s.size() == 1) {
            string res = "";
            for(char c = 'a'; c <= 'z'; c++) res.push_back(c);
            cout << "YES" << endl;
            cout << res << endl;
        }
        else {
            next[s[0] - 'a'] = s[1] - 'a';
            prev[s[1] - 'a'] = s[0] - 'a';
            int cur = s[1] - 'a';

            bool ok = true;
            unordered_set<char> st;
            st.insert(s[0] - 'a'); st.insert(s[1] - 'a');
            for(int i = 2; i < s.size() && ok; i++) {
                if(next[cur] == s[i] - 'a') cur = next[cur];
                else if(prev[cur] == s[i] - 'a') cur = prev[cur];
                else if(next[cur] == -1 && !st.count(s[i] - 'a')) {
                    prev[s[i] - 'a'] = cur;
                    next[cur] = s[i] - 'a';
                    cur = next[cur];
                    st.insert(s[i] - 'a');
                }
                else if(prev[cur] == -1 && !st.count(s[i] - 'a')) {
                    next[s[i] - 'a'] = cur;
                    prev[cur] = s[i] - 'a';
                    cur = prev[cur];
                    st.insert(s[i] - 'a');
                }
                else ok = false;
            }

            if(ok) {
                while(prev[cur] != -1) cur = prev[cur];
                string s = "";
                while(cur != -1) {
                    s += (cur + 'a');
                    cur = next[cur];
                }
                for(char c = 'a'; c <= 'z'; c++)
                    if(!st.count(c - 'a')) s += c;

                cout << "YES" << endl;
                cout << s << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
}
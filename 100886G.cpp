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

ll dp[20][2][2][2];
ll num[20][2][2][2];

ll p10(ll p) {
    ll res = 1;
    while(p--) res *= 10;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll a, b; cin >> a >> b;
    fill_n(&dp[0][0][0][0], 20*2*2*2, 0);
    fill_n(&num[0][0][0][0], 20*2*2*2, 0);
 
    dp[0][0][0][1] = dp[0][1][0][1] = dp[0][0][1][1] = dp[0][1][1][1] = 1;
    int d = 1;
    while(a | b) {
        int cura = a % 10;
        int curb = b % 10;

        for(int i = 0; i < 2; i++)     
            for(int j = 0; j < 2; j++)
                for(int q = 0; q < 2; q++)
                    for(int k = (i ? 0 : cura); k <= (j ? 9 : curb); k++) {
                        int pd = d - 1;
                        int pi = (i | k > cura);
                        int pj = (j | k < curb);
                        int pq = (q | k > 0);

                        ll mul = pq ? k : 1LL;
                        if(mul * dp[pd][pi][pj][pq] >= dp[d][i][j][q]) {
                            dp[d][i][j][q] = mul * dp[pd][pi][pj][pq];
                            num[d][i][j][q] = k * p10(d - 1) + num[pd][pi][pj][pq];
                        }
                    }
 
        a /= 10;
        b /= 10;
        d++;
    }
 
    cout << num[d - 1][0][0][0] << endl;
}

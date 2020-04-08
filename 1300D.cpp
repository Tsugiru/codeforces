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
const int inf = 1e7;
const int MX = 100001; //check the limits, dummy

double INF = 1e100;
double EPS = 1e-12;

struct PT { 
  ll x, y; 
  PT() {}
  PT(ll x, ll y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (ll c)     const { return PT(x*c,   y*c  ); }
  PT operator / (ll c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<PT> v(n);
    for(auto &pt : v) cin >> pt.x >> pt.y;

    if(v.size() & 1) cout << "NO" << endl;
    else {
        bool ok = true;
        for(int i = n/2; i < n; i++) {
            if(dist2(v[i], v[(i + 1)%n]) != dist2(v[i - n/2], v[i - n/2 + 1]) 
                || !LinesParallel(v[i], v[(i + 1)%n], v[i - n/2], v[i - n/2 + 1])) {
                ok = false;
                break;
            }
        }

        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
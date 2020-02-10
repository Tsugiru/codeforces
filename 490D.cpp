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

void extract3(ll &num, unordered_map<int, int> &fact, int &diff) {
    while(num % 3 == 0 && diff) {
        num /= 3;
        num *= 2;
        fact[2]++;
        diff--;
    }
}

void extract2(ll &num, int &diff) {
    while(num % 2 == 0 && diff) {
        num /= 2;
        diff--;
    }
}

int main() {
    ll a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;
    ll x = a1 * b1, y = a2 * b2;
    unordered_map<int, int> fact1, fact2;
    for(int i = 2; i <= 3; i++) {
        while(x % i == 0) { fact1[i]++; x /= i; }
        while(y % i == 0) { fact2[i]++; y /= i; }
    }

    if(x != y) cout << -1 << endl;
    else {
        int ops = abs(fact1[3] - fact2[3]);
        while(fact1[3] > fact2[3] && a1 % 3 == 0) { a1 = a1 * 2 / 3; fact1[2]++; fact1[3]--; }
        while(fact1[3] > fact2[3] && b1 % 3 == 0) { b1 = b1 * 2 / 3; fact1[2]++; fact1[3]--; }
        while(fact1[3] < fact2[3] && a2 % 3 == 0) { a2 = a2 * 2 / 3; fact2[2]++; fact2[3]--; }
        while(fact1[3] < fact2[3] && b2 % 3 == 0) { b2 = b2 * 2 / 3; fact2[2]++; fact2[3]--; }

        ops += abs(fact1[2] - fact2[2]);
        while(fact1[2] > fact2[2] && a1 % 2 == 0) { a1 /= 2; fact1[2]--; }
        while(fact1[2] > fact2[2] && b1 % 2 == 0) { b1 /= 2; fact1[2]--; }
        while(fact1[2] < fact2[2] && a2 % 2 == 0) { a2 /= 2; fact2[2]--; }
        while(fact1[2] < fact2[2] && b2 % 2 == 0) { b2 /= 2; fact2[2]--; }

        cout << ops << endl;
        cout << a1 << " " << b1 << endl;
        cout << a2 << " " << b2 << endl;
    }
}
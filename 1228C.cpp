vl sieve(ll x) {
    vl p(sqrt(x) + 1, 0), res;
    p[0] = p[1] = 1;
    F0R(i, sz(p)) {
        if (p[i]) continue;
        for (ll j = i * i; j < sz(p); j += i) p[j] = 1;
        if (x % i == 0) res.pb(i);
    }
    if (sz(res) == 1) res.pb(x / res[0]);
    if (sz(res) == 0) res.pb(x);
    return res;
}

ll fstpow(ll x, ll y) {
    ll res = 1, cur = x;
    while (y) {
        if (y & 1) res = (res * cur) % MOD;
        cur = (cur * cur) % MOD;
        y >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll x;
    ll n;
    cin >> x >> n;
    vl primes = sieve(x);

    ll ans = 1;
    for (ll p : primes) {
        ll y = 0, cur = p;
        while (cur <= n && ()) {
            y += n / cur;
            cur *= p;
        }
        ans = (ans * fstpow(p, y)) % MOD;
    }

    cout << ans << endl;
}
// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
  
#define inf 0x3f3f3f3f
  
#define PI acos(-1)
#define eps 1e-9
//#define inf 100000000
#define MOD 1000000007
  
#define mem(a,b) memset(a, b, sizeof(a) )
  
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
//int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
//int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};
  
int biton(int N, int pos) {return N = N | (1 << pos);}
int bitoff(int N, int pos) {return N = N & ~(1 << pos);}
bool check(int N, int pos) {return (bool)(N & (1 << pos));}
  
#define ll long long int
#define ff first
#define ss second
#define sc(a)           scanf("%d", &a)
#define sc2(a, b)       scanf("%d%d", &a, &b)
#define sc3(a, b, c)    scanf("%d%d%d", &a, &b, &c)
#define SS(a) scanf("%lli", &a)
#define P(a) printf("%i", a)
#define PP(a) printf("%lli", a)
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define REP(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
ll a, b, mx;
string x, y;
vector < int > v1, v2;
 
ll dp[100][2][2][2];
 
ll call(int pos, int ch, int br, int flag){
    if(pos == mx){
        if(flag) return 1LL;
        else return 0LL;
    }
 
    ll &ret = dp[pos][ch][br][flag];
    if(ret != -1) return ret;
 
    ll ans = 0LL;
     
    int mx = ch ? 9 : v2[pos];
    int mn = br ? 0 : v1[pos];
 
    for(int i = mn; i<= mx; i++){
        ll mul = 1LL;
        int ff = flag or (i > 0);
        if(ff) mul = i;
        ans = max(ans, 1LL * mul * call(pos + 1, ch or i < mx, br or i > mn, ff) );
    }
    return ret = ans;
}
 
ll backtrack(int pos, int ch, int br, int flag){
    if(pos == mx) {
        if(flag) return 1LL;
        else return 0LL;
    }
    ll &ret = dp[pos][ch][br][flag];
 
    int mx = ch ? 9 : v2[pos];
    int mn = br ? 0 : v1[pos];
 
    for(int i = mn; i <= mx; i++){
        ll mul = 1LL;
        int ff = flag or (i > 0);
        if(ff) mul = i;
        if(ret == mul * call(pos + 1, ch or i < mx, br or i > mn, ff)){
            if(ff) printf("%i", i);
            backtrack(pos + 1, ch or i < mx, br or i > mn, ff);
            break;
        }
    }
    return ret;
}
 
int main(){
     
    cin >> x >> y;
    mx = max(x.size(), y.size());
    if(x.size() != mx) x.insert(0, (mx - x.size()), '0');
    else y.insert(0, (mx - y.size()), '0');
    for(int i = 0; i < mx; i++){
        v1.push_back(x[i] - '0');
        v2.push_back(y[i] - '0');
    }
     
    mem(dp, -1);
    ll ans = call(0, 0, 0, 0); // pos, restrict 
    backtrack(0, 0, 0, 0);
    //fprintf(stderr, "Time: %d ms\n", (int)(clock()*1000.0/CLOCKS_PER_SEC));
    return 0;
}
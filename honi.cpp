#include<bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef tuple<int,int,int> iii;

#define pb push_back
#define eb emplace_back
#define ctz __builtin_ctz
#define pct __builtin_popcount
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);++i)

vector<vll> dp;
vll a, b;
const ll mod = 1e9 + 7;
int n;

ll f(int i, int used_prev) {
    if(i == n)
        return 1;
    if(dp[i][used_prev] != -1)
        return dp[i][used_prev];
    ll ans = 0;
    // use top
    ll carry = i == 0 ? 0 : max(b[i - 1] - used_prev, 0LL);
    ans += (carry + a[i]) * f(i + 1, 0);
    // use bottom
    if(i != n-1)
        ans += b[i] * f(i + 1, 1);
    ans %= mod;
    return dp[i][used_prev] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a.resize(n);
    b.resize(n - 1);
    rep(i, n) cin >> a[i];
    rep(i, n - 1) cin >> b[i];
    dp.resize(n, vll(2, -1));
    cout << f(0, 0) << endl;
}

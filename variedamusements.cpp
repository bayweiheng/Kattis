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

ll dp[55][55][55][4][55];
ll mod = 1e9 + 7;

ll solve(int a, int b, int c, int t, int m) {
    if(m==0)
        return 1;
    if(dp[a][b][c][t][m] != -1)
        return dp[a][b][c][t][m];
    ll ans = 0;
    ll x = solve(a, b, c, 0, m - 1) * a;
    ll y = solve(a, b, c, 1, m - 1) * b;
    ll z = solve(a, b, c, 2, m - 1) * c;
    if(t == 0)
        ans = y + z;
    else if(t == 1)
        ans = x + z;
    else
        ans = x + y;
    ans %= mod;
    return dp[a][b][c][t][m] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    rep(i,55) rep(j,55) rep(k,55) rep(l,4) rep(m, 55) {
        dp[i][j][k][l][m] = -1;
    }
    int a, b, c, n;
    cin >> n >> a >> b >> c;
    ll ans = solve(a, b, c, 0, n-1) * a + solve(a, b, c, 1, n-1) * b + solve(a, b, c, 2, n-1) * c;
    ans %= mod;
    cout << ans << endl;
}

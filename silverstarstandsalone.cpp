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

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = false;
    rep(i, n + 1)
    {
        if(is_prime[i]) {
            for (int j = i; j * i <= n; ++j)
                is_prime[i * j] = false;
        }
    }
    vll dp(n + 1, 0);
    dp[2] = 1;
    rep(i, n + 1)
    {
        if(is_prime[i]) {
            //db2(i, dp[i]);
            rep(j, 14)
            {
                int k = i + j + 1;
                if(k <= n)
                    dp[k] += dp[i];
            }
        }
    }
    cout << dp[n] << endl;
}

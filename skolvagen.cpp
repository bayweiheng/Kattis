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
    string s;
    cin >> s;
    int n = s.size();
    int dp[n + 1][2];
    dp[n][0] = 0;
    dp[n][1] = 1;
    for (int i = n - 1; i >= 0; --i) {
        if(s[i] == 'B') {
            dp[i][0] = min(dp[i + 1][0] + 1, dp[i + 1][1] + 2);
            dp[i][1] = min(dp[i + 1][0] + 2, dp[i + 1][1] + 1);
        }
        else if (s[i] == 'N') {
            dp[i][0] = min(dp[i + 1][0] + 1, dp[i + 1][1] + 1);
            dp[i][1] = min(dp[i + 1][0] + 1, dp[i + 1][1]);
        } else {
            assert(s[i] == 'S');
            dp[i][0] = min(dp[i + 1][0], dp[i + 1][1] + 1);
            dp[i][1] = min(dp[i + 1][0] + 1, dp[i + 1][1] + 1);
        }
    }
    cout << dp[0][0] << endl;
}

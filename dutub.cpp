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

unordered_map<char, int> m;

int getidx(char c) {
    if(m.count(c))
        return m[c];
    int i = m.size();
    //db(i);
    return m[c] = i;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vii videos;
    string s;
    int t;
    rep(i, n)
    {
        cin >> t >> s;
        int id = 0;
        for(char c:s) {
            id |= (1 << getidx(c));
        }
        //db2(t, id);
        videos.pb(ii(t, id));
    }
    int target = (1<<m.size()) - 1;
    //db(target);
    vvi dp(n, vi(target+1, 99999999));
    rep(i, n)
    {
        int id;
        tie(t, id) = videos[i];
        if (i == 0)
        {
            dp[0][0] = 0;
            dp[0][id] = t;
        } else {
            rep(j, target+1) {
                dp[i][j | id] = min(dp[i][j | id], dp[i - 1][j] + t);
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
        }
        //rep(j, target+1) {
        //    db3(i, j, dp[i][j]);
        //}
    }
    cout << dp[n - 1][target] << endl;
}

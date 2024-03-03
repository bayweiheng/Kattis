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
    int n, m;
    cin >> n;
    int cnt = 0, max_cnt = 0;
    vi ans(n + 1, 0);
    vector<ii> endpoints;
    int s, t;
    rep(i, n)
    {
        cin >> m;
        rep(j,m) {
            cin >> s >> t;
            endpoints.pb(ii(s, 1));
            endpoints.pb(ii(t+1, -1));
        }
    }
    sort(all(endpoints));
    int mod, cur_t = 0;
    for (ii &p : endpoints)
    {
        tie(t, mod) = p;
        ans[cnt] += t - cur_t;
        cur_t = t;
        cnt += mod;
        max_cnt = max(max_cnt, cnt);
    }
    cout << max_cnt << endl;
    cout << ans[max_cnt] << endl;
}

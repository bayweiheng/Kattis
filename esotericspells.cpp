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

typedef pair<ll, int> lli;

void solve() {
    int n;
    cin>>n;
    ll a[n];
    vector<lli> v;
    rep(i, n)
    {
        cin >> a[i];
        v.pb(lli(a[i], i));
    }
    sort(all(v), greater<lli>());
    ll ans = 0;
    ll final[n];
    for (auto p : v)
    {
        ll c = p.first;
        ll use = 0;
        for (int i = 62; i >= 0; --i)
        {
            ll t = 1LL << i;
            if(t <= c && ((t ^ ans) > ans)) {
                c -= t;
                ans ^= t;
                use += t;
                //db(ans);
            }
        }
        final[p.second] = use;
    }
    cout << ans << endl;
    rep(i, n)
    {
        cout << final[i] << (i == n - 1 ? "\n" : " ");
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    rep(i,n) {
        solve();
    }
}


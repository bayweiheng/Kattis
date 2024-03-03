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
    ll a[n];
    rep(i, n) cin >> a[i];
    if(n==1) {
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    rep(i,n) {
        for (int j = i + 1; j < n; ++j)
        {
            ll f = a[i];
            ll s = a[j];
            ll tgt = f + s;
            int l = 2;
            for (int k = j + 1; k < n; ++k)
            {
                //if(i==3 && j==4)
                    //db3(k, a[k], tgt);
                if (a[k] != tgt)
                    continue;
                ++l;
                f = s;
                s = tgt;
                tgt = f + s;
            }
            //db3(i, j, l);
            ans = max(ans, l);
        }
    }
    cout << ans << endl;
}

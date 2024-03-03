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
    int a[n];
    rep(i, n) cin >> a[i];
    vi ans;
    for (int i = 2; i <= n; ++i)
    {
        if(n%i != 0)
            continue;
        int num = n / i; // per section
        vi mn(i, n + 1), mx(i, 0);
        rep(j, i)
        {
            for (int k = j * num; k < (j+1) * num; ++k) {
                mn[j] = min(mn[j], a[k]);
                mx[j] = max(mx[j], a[k]);
            }
        }
        bool can = 1;
        rep(j, i-1) {
            //db3(j, mx[j], mn[j + 1]);
            if (mx[j] >= mn[j + 1])
            {
                can = 0;
                break;
            }
        }
        if(can)
            ans.pb(i);
    }
    if(ans.size() == 0) {
        cout << -1 << endl;
    } else {
        for(int i:ans)
            cout << i << endl;
    }
}

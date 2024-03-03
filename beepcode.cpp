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
    // 0101 -> 0 -> 1 : % 2 
    // 0011 -> 1 -> 2 : / 2 % 2
    // 00001 -> 3 -> 4
    vi v;
    for (int w = 0; (1 << w) < n; ++w)
    {
        int nx = 1 << w;
        int pv = nx - 1;
        int t = a[nx] - a[pv]; // -1 -> A, 1 -> B
        v.pb(t);
        if(t == 1) {
            rep(i,n) {
                a[i] -= (i / nx) % 2;
            }
        } else if(t==-1) {
            rep(i,n) {
                a[i] -= ((i / nx) % 2 == 0) ? 1 : 0;
            }
        }
    }
    vs ans;
    for(int i:v) {
        if(i==1)
            ans.pb("B");
        else if(i==-1)
            ans.pb("A");
        else
            ans.pb("x");
    }
    if(a[0] + ans.size() == 20) {
        while(ans.size() < 20)
            ans.pb("A");
    } else {
        while(ans.size() < 20)
            ans.pb("?");
    }
    rep(i,20) {
        cout << ans[i] << (i == 19 ? "\n" : " ");
    }
}

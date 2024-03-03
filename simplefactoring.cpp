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

vll slow_factors(int a) {
    vll ans;
    for (int i = 1; i * i <= a; ++i)
    {
        if(a%i==0) {
            ans.pb(i);
            ans.pb(a / i);
        }
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q, a, b, c;
    cin >> q;
    rep(i, q)
    {
        cin >> a >> b >> c;
        // want to find d,e,f,g such that df = a, eg = c, dg + ef = b
        bool can = 0;
        vll l = slow_factors(a), r = slow_factors(c);
        for(ll d: l) {
            for(ll e: r) {
                if(d * (c / e) + e * (a / d) == b)
                    can = 1;
            }
        }
        cout << (can ? "YES" : "NO") << endl;
    }
}


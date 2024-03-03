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
    int a[n], t[n], p[n];
    ll sum = 0;
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> p[i];
    int fst = p[0] - 1;
    if(a[fst] * 2 >= sum) {
        // got to compete for the first one
        cout << (n==2 ? 0.25 : 0.5) << endl;
        cout << p[0];
        rep(i, n - 2) cout << " " << p[i + 2];
        if(n >= 2)
            cout << " " << p[1];
        cout << endl;
    }
    else
    {
        cout << 1 << endl;
        rep(i, n - 1) cout << p[i + 1] << " ";
        cout << p[0] << endl;
    }
}

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

const ll inf = LLONG_MAX;

struct solution {
    vll p, a, maxi, mini;
    int n;
    solution() {}
    void read() {
        cin >> n;
        p.resize(n);
        a.resize(n);
        rep(i, n) cin >> p[i];
        rep(i, n) cin >> a[i];
        mini.resize(n, inf);
        maxi.resize(n, inf);
        maxmini.resize(n);
        minmaxi.resize(n);
    }
    // see below for e.g. maxmini[i][j];
    vector<unordered_map<int, ll>> maxmini, minmaxi;
    // call this with i+j, j
    ll f(int i, int j) {
        if(i >= n)
            return 0;
        if(maxmini[i].count(j))
            return maxmini[i][j];
        return maxmini[i][j] = max(mini[i], f(i + j, j));
    }
    ll g(int i, int j) {
        if(i >= n)
            return 0;
        if(minmaxi[i].count(j))
            return minmaxi[i][j];
        return minmaxi[i][j] = min(maxi[i], g(i + j, j));
    }
    void solve()
    {
        // maxi[i] = a[i] + max(mini[j] for j = i + mult * p[i], 0)
        // mini[i] = a[i] + min(maxi[j] for j = i + mult * p[i], 0)
        for (int i = n - 1; i >= 0; --i) {
            maxi[i] = a[i] + f(i + p[i], p[i]);
            mini[i] = a[i] + g(i + p[i], p[i]);
            //db3(i, maxi[i], mini[i]);
            //db2(a[i], p[i]);
            //db2(f(i + p[i], p[i]), g(i + p[i], p[i]));
        }
        rep(i, n) {
            cout << maxi[i] << (i == n - 1 ? "\n" : " ");
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c;
    cin >> c;
    rep(i,c) {
        solution sol;
        sol.read();
        sol.solve();
    }
    cout.flush();
}

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

void printv(vi &v, int l) {
    for (int i = 100; i < l + 100; ++i) {
        cout << v[i];
    }
    cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, r;
    string s, t;
    cin >> n >> l >> r >> s;
    int a[8];
    rep(i,8) {
        a[i] = ((1<<i) & n) ? 1 : 0;
    }
    vi v(l+205), w(l+205);
    rep(i, l) {
        v[i+100] = (s[i] == '1') ? 1 : 0;
    }
    rep(j, r) {
        rep(i, l + 205) {
            int p4 = i == 0 ? 0 : v[i - 1];
            int p2 = v[i];
            int p1 = i == l + 205 - 1 ? 0 : v[i + 1];
            int ans = p4 * 4 + p2 * 2 + p1;
            w[i] = a[ans];
        }
        printv(w, l);
        v = w;
    }
}

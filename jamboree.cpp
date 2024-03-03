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
    cin >> n >> m;
    int a[n];
    rep(i, n) cin >> a[i];
    sort(a, a + n, greater<int>());
    if(m >= n) {
        cout << a[0] << endl;
        return 0;
    }
    // n-m scouts will have to carry two items
    // 2m-n scouts will carry one item
    int ans = 0;
    rep(i, 2*m-n) {
        ans = max(ans, a[i]);
    }
    for (int i = 2 * m - n; i < n; ++i) {
        int j = n - 1 - i + (2 * m - n);
        if(j < i)
            break;
        ans = max(ans, a[i] + a[j]);
    }
    cout << ans << endl;
}

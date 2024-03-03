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
    int a[n][n];
    rep(i,n) {
        rep(j,n) {
            int x, y, z;
            cin >> x >> y >> z;
            a[x][y] = z;
        }
    }
    // check associativity
    bool assoc = 1;
    rep(i,n) rep(j,n) rep(k,n) {
        if(a[a[i][j]][k] != a[i][a[j][k]]) {
            assoc = 0;
        }
    }
    if(!assoc) {
        cout << "magma" << endl;
        return 0;
    }
    // check identity
    int id = -1;
    rep(i, n)
    {
        bool can = 1;
        rep(j,n) {
            if(a[i][j] != j || a[j][i] != j) {
                can = 0;
                break;
            }
        }
        if(can) {
            id = i;
            break;
        }
    }
    if(id == -1) {
        cout << "semigroup" << endl;
        return 0;
    }
    // check inverses
    bool inv = 1;
    rep(i, n)
    {
        bool has = 0;
        rep(j, n) {
            if(a[i][j] == id && a[j][i] == id) {
                has = 1;
                break;
            }
        }
        if(!has) {
            inv = 0;
            break;
        }
    }
    cout << (inv ? "group" : "monoid") << endl;
}

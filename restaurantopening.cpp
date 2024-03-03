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
    int n,m;
    cin>>n>>m;
    int a[n][m];
    vi row(n,0), col(m,0);
    rep(i,n) rep(j,m) {
        cin>>a[i][j];
        row[i] += a[i][j];
        col[j] += a[i][j];
    }
    int rowans = 2e9, colans = 2e9;
    rep(i,n) {
        int tmp = 0;
        rep(j,n) tmp += abs(j-i) * row[j];
        rowans = min(rowans, tmp);
    }
    rep(i,m) {
        int tmp = 0;
        rep(j,m) tmp += abs(j-i) * col[j];
        colans = min(colans, tmp);
    }
    cout<<rowans+colans<<endl;


}


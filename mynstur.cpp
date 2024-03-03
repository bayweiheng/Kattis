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

int calc(char c) {
    if(c=='.')
        return 20;
    if(c=='O' || c=='0')
        return 10;
    if(c=='\\' || c=='/') return 25;
    if(c=='A')
        return 35;
    if(c=='^')
        return 5;
    if(c=='v')
        return 22;
    assert(false);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0, r, c;
    cin >> r >> c;
    rep(i,r) {
        string s;
        cin >> s;
        rep(j,c) {
            ans += calc(s[j]);
        }
    }
    cout << ans << endl;
}

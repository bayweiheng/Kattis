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

int vis[1024];

int f(int x) {
    rep(i,1024) {
        if(!vis[i] && __builtin_popcount(x ^ i) % 2 == 0)
            return i;
    }
}

string g(int x) {
    string s;
    rep(i,10) {
        s.pb((x % 2) + '0');
        x /= 2;
    }
    reverse(all(s));
    return s;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[505];
    a[0] = 0;
    vis[0] = 1;
    rep(i, 500) {
        a[i + 1] = f(a[i]);
        vis[a[i + 1]] = 1;
    }
    int q, c;
    cin >> q;
    rep(i,q) {
        cin >> c;
        cout << g(a[c]) << endl;
    }
}

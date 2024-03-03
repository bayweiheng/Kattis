#include<bits/stdc++.h>

using namespace std;

#define int long long
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

vs split(string &s) {
    string tok;
    vs ans;
    for(char c:s) {
        if(c=='"') {
            ans.pb(tok);
            tok = "";
        } else
            tok.pb(c);
    }
    ans.pb(tok);
    return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, j, k;
    cin >> n >> m >> j >> ws;
    string s;
    vii rec;
    ll sum = 0;
    rep(i, n)
    {
        getline(cin, s);
        vs v = split(s);
        s = v[1];
        k = stoi(v[2]);
        if(s > "Jane Eyre")
            continue;
        sum += k;
    }
    int t;
    rep(i, m)
    {
        getline(cin, s);
        vs v = split(s);
        t = stoi(v[0]);
        s = v[1];
        k = stoi(v[2]);
        //db(s);
        if(s > "Jane Eyre")
            continue;
        rec.pb(ii(t, k));
    }
    sort(all(rec));
    for (ii &p : rec)
    {
        tie(t, k) = p;
        if(t <= sum)
            sum += k;
    }
    cout << (sum + j) << endl;
}

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

unordered_map<string, int> m;
int idx = 0;
int get_idx(string &s) {
    if(!m.count(s)) {
        m[s] = idx;
        ++idx;
    }
    return m[s];
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s, t, u;
    vi adj(2 * n + 5, -1);
    rep(i, n)
    {
        cin >> s >> t >> u;
        int a = get_idx(t), b = get_idx(u);
        adj[a] = b;
    }
    int ans = 0;
    int k = m.size();
    vi vis(k, 0);
    rep(i,k) {
        int orig = i, cur = adj[i], hops = 1;
        while(cur != orig && cur != -1) {
            hops++;
            cur = adj[cur];
        }
        if(cur == orig)
            ans = max(ans, hops);
    }
    if (ans == 0)
    {
        cout << "No trades possible" << endl;
    }
    else
    {
        cout << ans << endl;
    }
}

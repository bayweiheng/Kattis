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
    int n, b, m;
    cin >> n >> b >> m;
    int u, v;
    vi adj[n], vis(n, 0);
    queue<int> q;
    rep(i, b)
    {
        cin >> u;
        --u;
        q.push(u);
        vis[u] = 1;
    }
    rep(i,m) {
        cin >> u >> v;
        --u;
        --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = 0, idx = 0;
    while(!q.empty() || idx != n) {
        while(!q.empty()) {
            u = q.front();
            q.pop();
            for(int v: adj[u]) {
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        if(idx == n)
            continue;
        if (!vis[idx])
        {
            vis[idx] = 1;
            q.push(idx);
            ++ans;
        }
        ++idx;
    }
    cout << ans << endl;
}

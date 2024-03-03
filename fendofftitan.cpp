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
typedef tuple<int,int,ll> iii;

#define pb push_back
#define eb emplace_back
#define ctz __builtin_ctz
#define pct __builtin_popcount
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);++i)

struct w {
    int t = 0, s = 0, i;
    ll d;
    w(ll d, int c, int i) : d(d), i(i)
    {
        if(c==1)
            ++s;
        if(c==2)
            ++t;
    }

    w add(w other) {
        w tmp(0, 0, 0);
        tmp.t = t + other.t;
        tmp.s = s + other.s;
        tmp.d = d + other.d;
        tmp.i = other.i;
        return tmp;
    }
};

struct Compare
{
    bool operator()(const w &l, const w &r) const
    {
        return iii(l.t, l.s, l.d) >= iii(r.t, r.s, r.d);
    }
};

typedef pair<int, w> edge;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    priority_queue<w, vector<w>, Compare> pq;
    vector<w> adj[n+1];
    int u, v, d, c;
    rep(i, m)
    {
        cin >> u >> v >> d >> c;
        adj[u].pb(w(d, c, v));
        adj[v].pb(w(d, c, u));
    }
    Compare comp;
    w inf(0, 0, 0);
    inf.t = 1e6;
    vector<w> mind(n + 1, inf);
    w zero(0, 0, x);
    mind[x] = zero;
    pq.push(zero);
    while(!pq.empty()) {
        w cur = pq.top();
        pq.pop();
        if(!comp(mind[cur.i], cur))
            continue;
        //db2(cur.t, cur.s);
        //db2(cur.d, cur.i);
        if (cur.i == y)
            break;
        for (w e : adj[cur.i])
        {
            int j = e.i;
            w tmp = cur.add(e);
            if(!comp(tmp, mind[j])) {
                mind[j] = tmp;
                pq.push(tmp);
            }
        }
    }
    w ans = mind[y];
    if(ans.t == inf.t) {
        cout << "IMPOSSIBLE" << endl;
    } else cout << ans.d << " " << ans.s << " " << ans.t << endl;
}

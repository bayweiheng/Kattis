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

unordered_map<int, int> m;

int get_idx(int i) {
    if(m.count(i))
        return m[i];
    int id = m.size();
    return m[i] = id;
}

vi adj[500];

void parse_segment(string t) {
    vi nums;
    string token;
    for(char c:t) {
        if(c == ',' || c == ')') {
            //db(token);
            if(token=="")
                continue;
            nums.pb(stoi(token));
            token = "";
        } else if(c >= '0' && c <= '9') {
            token.pb(c);
        }
    }
    int p1 = 100 * nums[0] + nums[1];
    int p2 = 100 * nums[2] + nums[3];
    int u = get_idx(p1), v = get_idx(p2);
    adj[u].pb(v);
    adj[v].pb(u);
}

void parse_string(string t) {
    string token;
    for(char c:t) {
        if(c == ' ')
            continue;
        else if (c == ';') {
            parse_segment(token);
            token = "";
        } else
            token.pb(c);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    while (getline(cin, s))
    {
        t.append(s);
    }
    parse_string(t);
    int n = m.size();
    vi vis(n, 0);
    int figs = 0, polys = 0;
    rep(i, n)
    {
        if(vis[i])
            continue;
        ++figs;
        vis[i] = 1;
        queue<int> q;
        bool cycle = true;
        q.push(i);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(adj[u].size() != 2)
                cycle = false;
            for(int v: adj[u]) {
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        if(cycle)
            ++polys;
    }
    cout << figs << " " << polys << endl;
}

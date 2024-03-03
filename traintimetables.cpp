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

int conv(string time) {
    string s = time.substr(0, 2), t = time.substr(3, 2);
    return stoi(s) * 60 + stoi(t);
}

void solve(int i) {
    int turn;
    cin >> turn;
    int a, b;
    string l, r;
    cin >> a >> b;
    vector<iii> v;
    int st, en, idx;
    rep(i, a + b)
    {
        cin >> l >> r;
        int st = conv(l), en = conv(r);
        v.pb(iii(st, en, i < a ? 0 : 1));
    }
    sort(all(v));
    vi ans(2, 0);
    priority_queue<int, vi, greater<int>> pq[2];
    for(iii &t: v) {
        tie(st, en, idx) = t;
        if(!pq[idx].empty() && pq[idx].top() + turn <= st) {
            pq[idx].pop();
        } else {
            ans[idx]++;
        }
        pq[1 - idx].push(en);
    }
    cout << "Case #" << i << ": " << ans[0] << " " << ans[1] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    rep(i, tc) {
        solve(i + 1);
    }
}

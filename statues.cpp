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

int get_ans(vvi a, int n, int m, function<int(int,int)> f) {
    unordered_map<int, set<int>> mp;
    vector<iii> order;
    int ans = 0;
    rep(i, n) rep(j, m)
    {
        order.pb(iii(f(i, j), i, j));
    }
    sort(all(order));
    int idx = 0;
    for (iii t : order)
    {
        int val, i, j;
        tie(val, i, j) = t;
        if(a[i][j] != -1) {
            mp[val].insert(idx);
            ++idx;
        }
    }
    rep(i,n) rep(j,m) {
        if(a[i][j] != -1 && !mp[f(i,j)].count(a[i][j]))
            ++ans;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m, 0));
    // (0,0) (0,m-1)
    // (n-1,0) (n-1,m-1)
    vi nums;
    rep(i, n) rep(j, m)
    {
        cin >> a[i][j];
        if(a[i][j] != -1) {
            nums.pb(a[i][j]);
        }
    }
    sort(all(nums));
    unordered_map<int, int> mp;
    rep(i,nums.size()) {
        mp[nums[i]] = i;
    }
    rep(i,n) rep(j,m) {
        if(a[i][j]!=-1)
            a[i][j] = mp[a[i][j]];
    }
    int ans = n * m;
    ans = min(ans, get_ans(a, n, m, [](int x, int y)
                           { return x + y; }));
    ans = min(ans, get_ans(a, n, m, [](int x, int y)
                           { return x - y; }));
    ans = min(ans, get_ans(a, n, m, [](int x, int y)
                           { return y - x; }));
    ans = min(ans, get_ans(a, n, m, [](int x, int y)
                           { return -x - y; }));
    cout << ans << endl;
}

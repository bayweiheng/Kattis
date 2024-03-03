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

int a[256];

string k = "IVXLCDM";
vi v = {1, 5, 10, 50, 100, 500, 1000};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    rep(i, k.size()) a[k[i]] = v[i];
    int q;
    cin >> q;
    string s;
    rep(i,q) {
        cin >> s;
        int n = s.size();
        int ans = 0, mx = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int d = a[s[i]];
            if(d < mx)
                ans -= d;
            else
                ans += d;
            mx = max(mx, d);
        }
        cout << ans << endl;
    }
}

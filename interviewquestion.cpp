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
    int c, d;
    string s;
    cin >> c >> d;
    vi f, b;
    for (int cur = c; cur <= d; ++cur)
    {
        cin >> s;
        if(s == "Fizz")
            f.pb(cur);
        else if(s == "Buzz")
            b.pb(cur);
        else if(s == "FizzBuzz") {
            f.pb(cur);
            b.pb(cur);
        }
    }
    int def = d == 1e6 ? c - 1 : d + 1;
    int ans_a, ans_b;
    if(f.size() == 0)
        ans_a = def;
    else if(f.size() == 1)
        ans_a = f[0];
    else
        ans_a = f[1] - f[0];
    if(b.size() == 0)
        ans_b = def;
    else if(b.size() == 1)
        ans_b = b[0];
    else
        ans_b = b[1] - b[0];
    cout << ans_a << " " << ans_b << endl;
}

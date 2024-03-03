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
    string s;
    cin >> s;
    vi v;
    rep(i, s.size())
    {
        int k = i + 1;
        int a = 0, b = 0;
        int aw = 0, bw = 0;
        for (char c : s)
        {
            if(c=='A')
                ++a;
            else
                ++b;
            if(a==k) {
                a = b = 0;
                aw++;
            }
            if(b==k) {
                a = b = 0;
                bw++;
            }
        }
        if(aw > bw)
            v.pb(k);
    }
    cout << v.size() << endl;
    if(v.size()) {
        rep(i, v.size()) cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
    }
}

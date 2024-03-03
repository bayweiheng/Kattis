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
    string s, t;
    getline(cin, s);
    getline(cin, t);
    string a, b, u, v;
    bool found_s = 0, found_t = 0;
    for(char c:s) {
        if(c=='|')
            found_s = 1;
        else {
            if(found_s)
                u.pb(c);
            else
                a.pb(c);
        }
    }
    for(char c:t) {
        if(c=='|')
            found_t = 1;
        else {
            if(found_t)
                v.pb(c);
            else
                b.pb(c);
        }
    }
    string ans;
    ans.append(a);
    ans.append(b);
    ans.pb(' ');
    ans.append(u);
    ans.append(v);
    cout << ans << endl;
}

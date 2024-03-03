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

bool check(int i,int j) {
    string s = to_string(i), t = to_string(j), u = to_string(i * j);
    if(s.size() + t.size() != u.size())
        return false;
    unordered_map<char, int> m;
    for(char c:s)
        m[c]++;
    for(char c:t)
        m[c]++;
    for(char c:u) {
        if(m[c]==0)
            return false;
        --m[c];
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    vii pairs;
    for (int i = a; i * i <= b; ++i)
    {
        for (int j = i; i * j <= b; ++j) {
            if(check(i,j))
                pairs.pb(ii(i, j));
        }
    }
    cout << pairs.size() << " digit-preserving pair(s)" << endl;
    for(auto p: pairs) {
        cout << "x = " << p.first << ", y = " << p.second << ", xy = " << p.first * p.second << endl;
    }
}

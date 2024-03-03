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

vi combo(int x, int y) {
    vi ans;
    ans.pb(x + y);
    ans.pb(x - y);
    ans.pb(x * y);
    if(x%y==0) {
        ans.pb(x / y);
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y, z;
    cin >> x >> y >> z;
    vi ans;
    for(int i: combo(x,y)) {
        for(int j: combo(i,z)) {
            //db2(i, j);
            ans.pb(j);
        }
    }
    int a=1e9;
    for(int i:ans) {
        if(i>=0 && i<a)
            a = i;
    }
    cout << a << endl;
}

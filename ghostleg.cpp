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

void print(vi v) {
    rep(i,v.size()) {
        cout<<v[i]<<endl;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m;
    vi v(n,0),rev(n+1,0);
    rep(i,n) {
        v[i]=i+1;
        rev[i]=i-1;
    }
    rev[n]=n-1;
    rep(i,m) {
        cin>>k;
        int a=rev[k],b=rev[k+1];
        rev[k+1]=a;
        rev[k]=b;
        v[a]=k+1;
        v[b]=k;
    }
    //print(v);
    rep(i,n) cout<<rev[i+1]+1<<endl;
}


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
    int n, m, k;
    cin >> n >> m >> k;
    queue<ii> q;
    int st;
    rep(i, k)
    {
        cin >> st;
        q.push(ii(0, st));
    }
    string a[n];
    rep(i, n) cin >> a[i];
    int i, j;
    while (!q.empty())
    {
        tie(i, j) = q.front();
        //db2(i, j);
        q.pop();
        if(a[i][j] != 'O')
            continue;
        a[i][j] = '~';
        if(i+1 >= n)
            continue;
        if(a[i+1][j] == 'O')
            q.push(ii(i + 1, j));
        else if(a[i+1][j] != '~') {
            if(j>0 && a[i][j-1] == 'O')
                q.push(ii(i, j - 1));
            if(j<m-1 && a[i][j+1] == 'O') {
                q.push(ii(i, j + 1));
            }
        }
    }
    //db(123);
    rep(i, n) cout << a[i] << endl;
    cout.flush();
}

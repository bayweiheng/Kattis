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
    int a[3][6];
    rep(i,3) {
        rep(j, 6) {
            cin >> a[i][j];
        }
    }
    int can[3][3];
    rep(i, 3)
    {
        rep(j, 3) {
            if(i == j) {
                can[i][j] = 0;
               continue;
            }
            int l = 0, r = 0;
            rep(x, 6) {
                rep(y, 6) {
                    if(a[i][x] > a[j][y])
                        ++l;
                    else if(a[i][x] < a[j][y])
                        ++r;
                }
            }
            if(l >= r && l != 0)
                can[i][j] = 1;
            else
                can[i][j] = 0;
        }
    }
    rep(i, 3) {
        if(can[i][0] + can[i][1] + can[i][2] >= 2) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << "No dice" << endl;
}


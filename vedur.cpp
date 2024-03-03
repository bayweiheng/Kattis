#include <bits/stdc++.h>

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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef tuple<int, int, int> iii;

#define pb push_back
#define eb emplace_back
#define ctz __builtin_ctz
#define pct __builtin_popcount
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double x;
    cin >> x;
    string ans;
    if (x >= 32.7)
        ans = "Farvidri";
    else if (x >= 28.5)
        ans = "Ofsavedur";
    else if (x >= 24.5)
        ans = "Rok";
    else if (x >= 20.8)
        ans = "Stormur";
    else if (x >= 17.2)
        ans = "Hvassvidri";
    else if (x >= 13.9)
        ans = "Allhvass vindur";
    else if (x >= 10.8)
        ans = "Stinningskaldi";
    else if (x >= 8.0)
        ans = "Kaldi";
    else if (x >= 5.5)
        ans = "Stinningsgola";
    else if (x >= 3.4)
        ans = "Gola";
    else if (x >= 1.6)
        ans = "Kul";
    else if (x >= 0.3)
        ans = "Andvari";
    else
        ans = "Logn";
    cout << ans << endl;
}

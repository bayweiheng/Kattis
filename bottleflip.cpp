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

double h, r, da, dw;

double f(double x) {
    double d = dw - da;
    double w1 = h * da, w2 = 2 * x * d;
    return h - (h / 2 * w1 + x * w2) / (w1 + w2);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> r >> da >> dw;
    // cg of air filled bottle is h/2 and mass of air is proportional to h * da
    // add height 2x of "water-air" with density (dw-da)
    // cg of resultant is (h/2 * h * da + x * 2x * d) / (h * da + 2x * d)
    double lo = 0, hi = h / 2;
    while((hi-lo) > 1e-8) {
        double m1 = lo + (hi - lo) / 3, m2 = lo + (hi - lo) * 2 / 3;
        double a = f(lo), b = f(m1), c = f(m2), d = f(hi);
        if(b<a)
            hi = m1;
        else if(b>c)
            hi = m2;
        else
            lo = m1;
    }
    printf("%.8lf\n", hi * 2);
}

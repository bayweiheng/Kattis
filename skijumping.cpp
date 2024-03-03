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

double j, p, h, l, v;
const double g = 9.81;

double f(double x) {
    return -g / 2 * (x / v) * (x / v) + h + p;
}

double hill(double x)
{
    if(x < l/2) {
        return h * (1 - 2 * (x / l) * (x / l));
    } else if(x < l) {
        return 2 * h * (x / l - 1) * (x / l - 1);
    } else {
        return 0;
    }
}

double eval(double x) {
    return f(x) - hill(x);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    
    rep(i, q)
    {
        cin >> j >> p >> h >> l;
        // m * v * v / 2 = m * g * h;
        v = sqrt(2 * g * j);
        double lo = 0, hi = sqrt(2 * (h + p) / g) * v;
        while(hi-lo > 1e-8) {
            double mid = (hi + lo) / 2;
            if(eval(mid) < 0)
                hi = mid;
            else
                lo = mid;
        }
        double land_h = f(hi);
        double delta_h = j + h + p - land_h;
        double ans_v = sqrt(2 * g * delta_h);
        double v_x = v, v_y = -sqrt(ans_v * ans_v - v_x * v_x);
        double eps = 1e-6;
        double w_x = eps, w_y = hill(hi + w_x) - hill(hi);
        double inner = v_x * w_x + v_y * w_y;
        double inter = inner / sqrt(w_x * w_x + w_y * w_y);
        double cosa = inter / ans_v;
        //db3(inner, ans_v, sqrt(w_x * w_x + w_y * w_y));
        //db2(inter, cosa);
        
        printf("%.8lf %.8lf %.8lf\n", hi, ans_v, acos(cosa) / acos(-1) * 180);
    }
}

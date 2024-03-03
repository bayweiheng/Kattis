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

struct asteroid {
    double x, y, r;
    asteroid(double x, double y, double r) : x(x), y(y), r(r) {}
};

vector<asteroid> asteroids;

int w,h;

bool between(double a, double b, double c) {
    return a <= b && b <= c;
}

double eps = 1e-12;
bool contain(asteroid &a, double x, double y)
{
    if ((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y) <= a.r * a.r + eps)
        return true;
    return false;
}

bool intersect(double x, double y, asteroid &a) {
    if(between(x, a.x, x+w) && between(y, a.y, y+h))
        return true;
    if(contain(a, x, y) || contain(a, x, y+h) || contain(a, x+w, y) || contain(a, x+w, y+h))
        return true;
    if(between(x, a.x, x+w)) {
        double d = min(abs(a.y - y), abs(a.y - (y + h)));
        if(d <= a.r + eps)
            return true;
        else
            return false;
    }
    if(between(y, a.y, y+h)) {
        double d = min(abs(a.x - x), abs(a.x - (x + w)));
        if(d <= a.r + eps)
            return true;
        else
            return false;
    }
    return false;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> w >> h;
    int n, m;
    cin >> n >> m;
    double x, y, r;
    rep(i,n) {
        cin >> x >> y >> r;
        asteroids.pb(asteroid(x, y, r));
    }
    rep(i,m) {
        cin >> x >> y;
        bool can = 1;
        for (asteroid &a : asteroids)
        {
            if(intersect(x,y,a)) {
                can = 0;
                break;
            }
        }
        string ans = string("DOOMSLUG ") + (can ? "GO" : "STOP") + "!";
        cout << ans << endl;
    }
}

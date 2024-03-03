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
typedef pair<int, string> is;

#define pb push_back
#define eb emplace_back
#define ctz __builtin_ctz
#define pct __builtin_popcount
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);++i)

// males have -1 one of the first two slots, 1 is dominant, 0 is recessive
// OOBBDD
string get_color(vi v) {
    int b = v[2] + v[3], d = v[4] + v[5];
    if ((v[0] == 1 && v[1] == 1) || (v[0] == -1 && v[1] == 1) || (v[0] == 1 && v[1] == -1))
    {
        // red
        if(d)
            return "Red";
        else
            return "Cream";
    }
    else if ((v[0] == 1 && v[1] == 0) || (v[0] == 0 && v[1] == 1))
    {
        // tortie
        if(b && d)
            return "Black-Red Tortie";
        else if(b)
            return "Blue-Cream Tortie";
        else if(d)
            return "Chocolate-Red Tortie";
        else
            return "Lilac-Cream Tortie";
    } else {
        if(b && d)
            return "Black";
        else if(b)
            return "Blue";
        else if(d)
            return "Chocolate";
        else
            return "Lilac";
    }
}

unordered_set<string> dilution = {"Black", "Chocolate", "Red", "Black-Red Tortie", "Chocolate-Red Tortie"};
unordered_set<string> black = {"Black", "Blue", "Black-Red Tortie", "Blue-Cream Tortie"};

bool pass(vi v, string s)
{
    //if(v[2] == 0 || v[3] == 0)
    //    return false;
    if (v[2] == 0 && v[3] == 1 && black.count(s))
        return false;
    if(v[4] == 0 && v[5] == 1 && dilution.count(s))
        return false;
    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    getline(cin, s); // female
    getline(cin, t);
    unordered_map<string, vvi> males, females;
    rep(i, 32) {
        vi v(6, 0);
        v[0] = -1;
        rep(j, 5)
        {
            v[j + 1] = (i & (1 << j)) ? 1 : 0;
        }
        males[get_color(v)].pb(v);
    }
    rep(i, 64) {
        vi v(6, 0);
        rep(j, 6) {
            v[j] = (i & (1 << j)) ? 1 : 0;
        }
        females[get_color(v)].pb(v);
    }
    unordered_map<string, int> babes;
    int m = 0, f = 0;
    for (auto v : males[t])
    {
        if (!pass(v, t))
            continue;
        ++m;
        //db2(v[4], v[5]);
        for (auto w : females[s])
        {
            if(!pass(w, s))
                continue;
            ++f;
            //db2(v[4], v[5]);
            //db2(w[4], w[5]);
            int ans = 0, nans = 0;
            vi x(6, 0);
            rep(a,2) {
                x[0] = w[a];
                rep(b,2) {
                    x[1] = v[b];
                    rep(c,2) {
                        x[2] = w[c + 2];
                        rep(d,2) {
                            x[3] = v[d + 2];
                            rep(e,2) {
                                x[4] = w[e + 4];
                                rep(f,2) {
                                    x[5] = v[f + 4];
                                    //db2(x[4], x[5]);
                                    string color = get_color(x);
                                    babes[color]++;
                                    //if(color=="Red")
                                    //    ans++;
                                    //else
                                    //    nans++;
                                }
                            }
                        }
                    }
                }
            }
            //db2(ans, nans);
        }
    }
    vector<is> ans;
    int total = 0;
    for (auto p : babes)
    {
        total += p.second;
        ans.pb(is(-p.second, p.first));
    }
    sort(all(ans));
    for(auto p: ans) {
        double cnt = -p.first;
        cnt /= total;
        cout << p.second << " " << setprecision(10) << cnt << endl;
    }
}

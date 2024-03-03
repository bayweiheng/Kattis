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

unordered_map<string, int> power = {
    {"Shadow", 6},
    {"Gale", 5},
    {"Ranger", 4},
    {"Anvil", 7},
    {"Vexia", 3},
    {"Guardian", 8},
    {"Frostwhisper", 2},
    {"Voidclaw", 3},
    {"Ironwood", 3},
};

int score(int i) {
    //db(i);
    int n, score = 0, late = 0;
    cin >> n;
    string s;
    int doubles = 0;
    rep(i,n) {
        cin >> s;
        if(s == "Thunderheart") {
            // assert(false);
            score += 6;
            if(n==4)
                late += 6;
            // doubles++;
        }
        else if (s == "Zenith") {
            score += 4;
            if(i == 1)
                late += 5;
        }
        else if(s == "Seraphina") {
            score += 1;
            late += n - 1;
        }
        else
            score += power[s];
    }
    return score * pow(2, doubles) + late;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int sa = 0, sb = 0;
    int pa = 0, pb = 0;
    rep(i, 3)
    {
        int a = score(i), b = score(i);
        sa += a;
        sb += b;
        if(a>b)
            ++pa;
        else if(b>a)
            ++pb;
    }
    string res;
    if (pa == pb)
    {
        if(sa==sb)
            res = "Tie";
        else if(sa>sb)
            res = "Player 1";
        else {
            assert(pa == pb && sa < sb);
            res = "Player 2";
        }
        } else if(pa>pb)
        res = "Player 1";
    else {
        assert(pa < pb);
        res = "Player 2";
    }
    cout << res << endl;
}

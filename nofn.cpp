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

bool has_space(string &s) {
    for(char c:s) {
        if(c==' ')
            return true;
    }
    return false;
}

pair<string,string> split(string s) {
    string l, r;
    bool found = 0;
    for (char c :s) {
        if(c==' ')
            found = 1;
        else if(found)
            r.pb(c);
        else
            l.pb(c);
    }
    return pair<string, string>(l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> ws;
    string s;
    unordered_set<string> st;
    unordered_map<string, string> mp;
    rep(i, n)
    {
        getline(cin, s);
        if(!has_space(s))
            st.insert(s);
        else {
            string fst, snd;
            tie(fst, snd) = split(s);
            mp[fst] = s;
        }
    }
    cin >> m;
    vs ans;
    rep(i, m)
    {
        cin >> s;
        if(st.count(s))
            ans.pb("Jebb");
        else if(mp.count(s)) {
            ans.pb("Neibb en " + mp[s] + " er heima");
        } else
            ans.pb("Neibb");
    }
    for(string s:ans)
        cout << s << endl;
}

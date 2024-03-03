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
    string s, t;
    cin >> s >> t;
    if(t.size() > s.size()) {
        cout << 2 << endl;
    } else if(s.size() > t.size()) {
        cout << 1 << endl;
    } else {
        reverse(all(s));
        reverse(all(t));
        rep(i,s.size()) {
            if(s[i] == '2')
                s[i] = '5';
            else if(s[i] == '5')
                s[i] = '2';
            if(t[i] == '2')
                t[i] = '5';
            else if(t[i] == '5')
                t[i] = '2';
        }
        int a = stoi(s), b = stoi(t);
        cout << (a > b ? 1 : 2) << endl;
    }
}

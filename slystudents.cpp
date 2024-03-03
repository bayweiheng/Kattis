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

int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

string tern(int a) {
    string rev;
    while(a) {
        rev.pb((a % 3 + '0'));
        a /= 3;
    }
    reverse(all(rev));
    return rev;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while(cin >> s) {
        int d = s[0];
        for(char c:s)
            d = gcd(d, c);
        cout << d << endl;
        for(char c:s) {
            cout << tern(c / d) << " ";
        }
        cout << endl;
    }

}

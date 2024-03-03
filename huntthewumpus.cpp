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
    int s;
    cin >> s >> ws;
    set<int> w;
    while(w.size() < 4) {
        s = s + (s / 13) + 15;
        w.insert(s % 100);
        // db(s);
    }
    string x;
    int moves = 0;
    while (cin >> x)
    {
        ++moves;
        int a = stoi(x);
        if(w.count(a)) {
            cout << "You hit a wumpus!" << endl;
            w.erase(w.find(a));
        }
        if(w.size() == 0)
            break;
        int mind = 25;
        for(int b: w) {
            mind = min(mind, abs(a / 10 - b / 10) + abs(a % 10 - b % 10));
        }
        cout << mind << endl;
    }
    cout << "Your score is " << moves << " moves." << endl;
}

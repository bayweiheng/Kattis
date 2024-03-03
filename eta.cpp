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
    string s;
    cin >> s;
    int idx = s.find('/');
    int a = stoi(s.substr(0, idx)), b = stoi(s.substr(idx + 1, s.size() - idx - 1));
    // fix n vertices, then min time is (n-1) / n, max time is [0+1+...+(n-1)] / n = (n-1) / 2
    int i = 2;
    while(i<=1e6) {
        bool can = 1;
        if (i % b != 0)
            can = 0;
        int required_sum = i * a / b;
        int lower = i - 1, upper = i * (i - 1) / 2;
        if(required_sum < lower || required_sum > upper)
            can = 0;
        if (can)
        {
            break;
        }
        else
        {
            ++i;
        }
    }
    if(i>1e6) {
        cout << "impossible" << endl;
    } else {
        int n = i, sum = i * a / b;
        // if we have a k, we have to have a k-1
        // 0 + 1 + 2 + ... + k + (1 + 1 + 1 + ... + 1) + remainder
        vi parent(n, 0);
        sum -= (n - 1);
        int maxk = 1; // this is equal to the current last i in the chain
        while(sum >= maxk) {
            parent[maxk + 1] = maxk;
            sum -= (maxk + 1) - 1;
            ++maxk;
        }
        if(sum != 0) {
            parent[n - 1] = sum;
        }
        cout << n << " " << (n - 1) << endl;
        rep(i,n) {
            if(i==0)
                continue;
            cout << i + 1 << " " << parent[i] + 1 << endl;
        }
    }
}

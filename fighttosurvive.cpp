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
    int s, m, h, e;
    cin >> s >> m;
    priority_queue<ii> pq;
    rep(i,s) {
        cin >> h;
        pq.push(ii(h, h));
    }
    cin >> e;
    vii recuperate[e + 2];
    priority_queue<int> ward;
    string event;
    int zombie;
    queue<int> zombies;
    rep(i, e)
    {
        if(i % m == m-1) {
            if(!ward.empty()) {
                int h = ward.top();
                ward.pop();
                pq.push(ii(h / 2, h));
            }
        }
        for(ii p: recuperate[i]) {
            pq.push(p);
        }
        cin >> event;
        if(event == "APPROACH") {
            cin >> zombie;
            zombies.push(zombie);
        } else {
            zombie = zombies.front();
            zombies.pop();
            while(zombie > 0) {
                if(pq.empty()) {
                    cout << "overrun" << endl;
                    return 0;
                }
                ii p = pq.top();
                pq.pop();
                if(p.first > zombie) {
                    ii left = ii(p.first - zombie, p.second);
                    recuperate[i + 2].pb(left);
                    zombie = 0;
                }
                else
                {
                    zombie -= p.first;
                    ward.push(p.second);
                }
            }
        }
    }
    cout << "success" << endl;
}

#include<bits/stdc++.h>

#define PB push_back
#define PF push_front
#define QTOP front
#define STOP top
#define PQTOP top

#define PQ priority_queue

#define MP make_pair
#define F first
#define S second

#define X first
#define Y second.first
#define Z second.second

#define MOD7 1000000007
#define MOD9 1000000009
#define MOD 998244353

#define N6 1000006
#define N5 100005
#define N4 10004
#define N3 1003
#define PI 3.1415926535897932384626

#define fill(x, v) memset(x, v, sizeof(x))
#define all(x) x.begin(),x.end()
#define R(i, n) for(ll i = 0; i < ll(n) ; i++)

#define FER(i,a,b) for(ll i=ll(a); i< ll(b); ++i)
#define REF(i,a,b) for(ll i=ll(a); i>=ll(b); --i )

#define len(x) ((int)(x).size())
#define elif else if


#define sqr(x) 1LL * (x) * (x)
#define INF (ll) 1e15

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii > tri;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define N N5

ll n, m, t = 1, ans;

ll dis[ N6 ];
bool v[ N6 ];
bool vis[ N6 ];

ll dfs( int i ){
	if( dis[ i ] > 0 ) return dis[ i ];
	if( vis[ i ] ) return -INF;
	if( !v[ i ] ) return dis[ i ] = 0;
	vis[ i ] = 1;
	return dis[ i ] = 1 + dfs((i + m)%n);
}

ll solve(){
	cin >> n >> m;

	R(i, n) {dis[ i ] = -1; vis[ i ] = false;}
	R(i, n) cin >> v[ i ];
	ll val;
	ans = -1;
	R(i, n){
		if( vis[ i ] ) continue;
		dfs( i );
		if( dis[ i ] < 0 ){
			return -1;
		}
	}

	R(i, n){
		ans = max(ans, dis[ i ]);
	}
	
    return ans;
}

int main(){
	fastio;
    cin >> t;
    while(t--) cout << solve() << endl;
    //while(t--) solve();
}

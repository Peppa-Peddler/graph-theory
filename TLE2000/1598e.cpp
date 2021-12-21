#include<bits/stdc++.h>

#define EP emplace
#define EB emplace_back
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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define same(x) x.erase(unique(all(x)), x.end())
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
typedef vector<vi> graph;
typedef vector<vii> edges;
typedef tuple<int, int, int , int> Node;

ll nxt() { ll x; cin >> x; return x; }

#define N N3

ll n, m, T = 1, ans, pts;

bool A[ N ][ N ];

Node border( int i , int j , int x , int y ){
	if( i + x < 0 )
		return {i , j, y, x};
	if( j + y < 0 )
		return {i , j, y, x};
	return border( i + x , j + y , y , x );
}

ll dfs( int i, int j, int x, int y, ll count ){
	ll sum = count * ( count - 1 ) / 2;
	if( i >= n or j >= m or i < 0 or j < 0 )
		return sum;
	if( A[ i ][ j ] )
		return sum + dfs( i + x , j + y , y , x , 0 );
	return dfs( i + x , j + y , y , x , count + 1 );
}

ll solve(){
	n = nxt();
	m = nxt();

	ll q = nxt();
	ll x, y, si, sj, sx, sy;


	pts = n * m;

	R(i, n){
		ans += dfs( i , 0 , 1 , 0 , 0 );
	}

	R(i, m){
		ans += dfs( 0 , i , 0 , 1 , 0 );
	}

	R(i, q){
		cin >> x >> y;
		x--, y--;

		tie( si , sj , sx , sy ) = border( x , y , -1 , 0 );

		ans -= dfs( si , sj , -sx , -sy , 0 );

		A[ x ][ y ] ^= 1;
		ans += dfs( si , sj , -sx , -sy , 0 );

		A[ x ][ y ] ^= 1;

		tie( si , sj , sx , sy ) = border( x , y , 0 , -1 );
		ans -= dfs( si , sj , -sx , -sy , 0 );

		A[ x ][ y ] ^= 1;
		ans += dfs( si , sj , -sx , -sy , 0 );

		if( A[ x ][ y ] )
			pts --;
		else
			pts ++;

		cout << ans + pts << endl;

	}

	return 0;
}

int main(){
	fastio;
	//T = nxt();
	//while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}

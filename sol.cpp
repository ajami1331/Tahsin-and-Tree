#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int sz = 1e5 + 10;
const int MAXNODE = 1e5;
const int MAXQUERY = 1e5;
int ar[sz], vis[sz], st[sz], en[sz], br[sz * 3], tim, vis_cnt;
vector < int > G[sz];

void dfs( int u ) {
    vis_cnt++;
    vis[u] = 1;
    st[u] = ++tim;
//    br[tim] = ar[u];
    for( int v: G[u] ) {
        if( !vis[v] ) {
            dfs( v );
        }
    }
    en[u] = ++tim;
}

int main() {
    #ifdef CLown1331
//        freopen( "input03.txt","r",stdin );
//        freopen( "output03.txt","w+",stdout );
    #endif /// CLown1331
    int t, n, m;
    cin >> t;
    assert( 1 <=t && t <= 5 );
    for( int cs=1; cs<=t; cs++ ) {
        cin >> n >> m;
        assert( n <= MAXNODE && m <= MAXQUERY );
        int a_size = 0;
        for( int i=1; i<=n; i++ ) {
            cin >> ar[i];
            assert( 0 <= ar[i] && ar[i] <= 1 );
            a_size++;
        }
        assert( a_size == n );
        for( int i=0; i<=n; i++ ) {
            G[i].clear();
            vis[i] = 0;
        }
        memset( br, 0, sizeof br );
        for( int i=1; i<n; i++) {
            int x, y;
            cin >> x >> y;
            assert( x != y );
            assert( 1 <= x && x <= n );
            assert( 1 <= y && y <= n );
            G[x].push_back( y );
            G[y].push_back( x );
        }
        vis_cnt = 0;
        tim = 0;
        dfs( 1 );
        assert( vis_cnt == n );
//        for( int i=1; i<=n; i++ ) {
//            cerr << br[ st[i] ] << " " << st[i] << " " << en[i] << "\n";
//        }
        for( int i=0; i<m; i++ ) {
            int x;
            cin >> x;
            assert( 1 <= x && x <= n );
            br[ st[x] ]++;
            br[ en[x] ]--;
        }
        for( int i=1; i<=tim; i++ ) {
            br[i] += br[i - 1];
        }
        printf( "Case %d:", cs );
        for( int i=1; i<=n; i++ ) {
            cout << " " << ( br[ st[i] ] + ar[i] ) % 2;
        }
        cout << "\n";
    }
    return 0;
}

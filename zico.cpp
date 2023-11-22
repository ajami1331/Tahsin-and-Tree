

#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#define INF 2e18
#define PI acos(-1.0)
#define pii pair <int, int>
#define pLL pair <LL, LL>
#define SQR(a) ((a)*(a))
#define all(a) a.begin(), a.end()
#define Unique(a) sort(all(a)), a.erase(unique(all(a)), a.end())
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define Iterator(a) __typeof__(a.begin())
#define For(I, A, B) for(int I = (A); I < (B); I++)
#define Rep(I, N) For(I, 0, N)
#define ff first
#define ss second
#define LL long long
#define ULL unsigned long long
#define vi vector <int>
#define pb push_back
#define mk make_pair

#define Sieve

#ifdef Sieve
const int pSz = 10000007;
int prime_size;
vi prime;
bool np[pSz + 10];
void sieve() {
    prime.pb(2);
    for(LL i = 4; i < pSz; i += 2) np[i] = 1;
    for(LL i = 3; i < pSz; i += 2) {
        if(!np[i]) {
            prime.pb(i);
            for(LL j = i * i; j < pSz; j += (i << 1)) np[j] = 1;
        }
    }
    prime_size = prime.size();
}
#endif

const LL MOD = 1000000000 + 7;

LL BigMod(LL B, LL P, LL M = MOD) {
    LL R = 1;
    while(P) {
        if(P & 1) R = (R * B) % M;
        B = B / 2;
    }
    return R;
}

const int N = 2000006;

int st[N], ed[N], vs[N], Time, n, m, res[N], cur[N], bit[N];
vi G[N];

void DFS(int x, int F) {
    st[x] = ++Time;
    for(int y : G[x]) if(y != F) DFS(y, x);
    ed[x] = ++Time;
}

int main()
{
    int t, qq = 1; scanf("%d", &t);
    while(t--) {
        Time = 0;
        memset(bit, 0, sizeof bit);
        scanf("%d %d", &n, &m);
        For(i, 1, n + 1) G[i].clear();
        For(i, 1, n + 1) scanf("%d", &cur[i]);
        For(i, 1, n) {
            int x, y; scanf("%d %d", &x, &y);
            G[x].pb(y);
            G[y].pb(x);
        }
        DFS(1, 0);
        while(m--) {
            int x; scanf("%d", &x);
            bit[ st[x] ]++;
            bit[ ed[x] ]--;
        }
        For(i, 1, Time + 1) bit[i] += bit[i - 1];
        For(i, 1, n + 1) res[i] = (bit[ st[i] ] + cur[i]) & 1;
        printf("Case %d:", qq++);
        For(i, 1, n + 1) printf(" %d", res[i]);
        printf("\n");
    }
    return 0;
}


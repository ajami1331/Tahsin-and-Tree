// A C++ Program to generate test cases for
// an unweighted tree
#include<bits/stdc++.h>
using namespace std;

// Define the number of runs for the test data
// generated
#define RUN 5

// Define the maximum number of nodes of the tree
#define MAXNODE 100000
#define MAXQUERY 100000
vector < int > par, cnt, rnk;
int N;

void make_set() {
    for(int i=0; i<N; i++) {
        par[i] = i;
        cnt[i] = 1;
        rnk[i] = 0;
    }
}

void init( int n ) {
    N = n;
    par.resize( n );
    cnt.resize( n );
    rnk.resize( n );
    make_set();
}

int find_rep( int x ) {
    if(x != par[ x ]) {
        par[ x ] = find_rep( par[ x ] );
    }
    return par[ x ];
}

bool _union( int u, int v ) {
    if( ( u = find_rep( u ) ) != ( v = find_rep( v ) ) ) {
        if( rnk[ u ] < rnk[ v ] ) {
            cnt[ v ] += cnt[ u ];
            par[ u ] = par[ v ];
        } else {
            rnk[ u ] = max( rnk[ u ], rnk[ v ] + 1 );
            cnt[ u ] += cnt[ v ];
            par[ v ] = par[ u ];
        }
        return true;
    }
    return false;
}


int main()
{
    freopen( "input10.txt", "w+", stdout );
    set<pair<int, int>> container;
    set<pair<int, int>>::iterator it;

    // Uncomment the below line to store
    // the test data in a file
    // freopen ("Test_Cases_Unweighted_Tree.in", "w", stdout);

    //For random values every time
    srand(time(NULL));

    int NUM;    // Number of Vertices/Nodes
    int query;
    printf( "%d\n", RUN );
    for (int i=1; i<=RUN; i++)
    {
//        NUM = 1 + rand() % MAXNODE;
//        query = 1 + rand() % MAXQUERY;
        NUM = 1 + rand() % MAXNODE;
        query = 1 + rand() % MAXQUERY;
        // First print the number of vertices/nodes
        printf("%d %d\n", NUM, query);
        for( int i=0; i<NUM; i++ ) {
            printf( "%d ", rand() % 2 );
        }
        printf( "\n" );
        init( NUM );
        // Then print the edges of the form (a b)
        // where 'a' is parent of 'b'
        for (int j=1; j<=NUM-1; j++)
        {
            int a = j;
            int b = 0 + rand() % ( j );
            pair<int, int> p = make_pair(a, b);
            // Search for a random "new" edge everytime
            while( _union( a, b ) == false ) {
                a = j;
                b = 0 + rand() % ( j );
                p = make_pair( a, b );
            }
            container.insert(p);
//            if( container.size() % 10000 == 0 )
//                cerr << container.size() << "\n";
        }
        for (it=container.begin(); it!=container.end(); ++it)
            printf("%d %d\n", it->first + 1, it->second + 1);

        container.clear();
        for( int i=0; i<query; i++ ) {
            printf( "%d\n", 1 + rand() % NUM );
        }
        printf("\n");
        cerr << i << "done\n";
    }

    // Uncomment the below line to store
    // the test data in a file
    // fclose(stdout);
    return(0);
}

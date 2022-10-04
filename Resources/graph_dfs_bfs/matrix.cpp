#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define FileIn(file) freopen(file ".inp", "r", stdin)
#define FileOut(file) freopen(file ".out", "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1 << (n))
#define Last(i) (i & -i)
#define INF 1000000000
#define EPS 1e-7
#define maxN 10000

using namespace std;

#define endl "\n"

typedef vector<int> vi;       // vector if ints
typedef pair<int, int> ii;    // pair of ints
typedef pair<int, int> XYpos; // pair of ints
typedef vector<ii> vii;       // vector of pairs

// C = occurences
// N =  nodes
// E exit cell number
// T time limit
// M number of edges
int C = 0, N = 0, E = 0, T = 0, M = 0;
int u = 0, v = 0, w = 0;
int AdjMatrix[100][100]; 



int main() {

    cin >> C;

    while (C > 0) {

        cin >> N >> T >> E >> M;

        REP(i, N){
            REP(j, N){
                AdjMatrix[i][j] = INF;
            }
        }

        REP(i, N){
            REP(j, N){
                cin >> u >> v >> w;
                AdjMatrix[u][v] = w;
            }
        }
 
        --C;
    }
}
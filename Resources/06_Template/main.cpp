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

using namespace std;

#define FileIn(file) freopen(file ".inp", "r", stdin)
#define FileOut(file) freopen(file ".out", "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)       //less simple more refined
#define REP(i, n) for (int i = 0; i < n; i++)           // simple 0=>N for 
#define Fill(ar, val) memset(ar, val, sizeof(ar))       // old school memory manip, but it works
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back                                    // lazy
#define bit(n) (1 << (n))                               // left shift by 1 = multiply by 2        
#define Last(i) (i & -i)
#define INF 500000000                                   // infinity
#define EPS 1e-7                                        // tiny epsilon
#define maxN 10000                                      // chabge to fit problem
#define endl "\n"                                       // \n doesn't flush the buffer



int main(int argc,char **argv){

    int x = 2;
    int max = 10;
    int A[max];
    int i=0;
    vector<int> V(10,0);

    sort(all(V));

    Fill(A, i);

    REP(i,max){
        cout<<A[i]<<endl;
    }

    cout << bit(x) << endl;
    return 0;
}
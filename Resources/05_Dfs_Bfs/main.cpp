#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define endl "\n"

using namespace std;

typedef vector< int >    vi;   // vector if ints
typedef pair< int, int > ii;   // pair of ints
typedef vector< ii >     vii;  // vector of pairs
typedef vector< vi >     vvi;  // vector of vectors of int

vvi adj;       // graph represented as an adjacency list
int n;         // number of vertices
vi  color;     // vector of colors for graph coloring
vi  time_in;   //
vi  time_out;  //
int dfs_timer = 0;

void dfs(int v) {
    cout << "1" << endl;
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            dfs(u);
        }
    }
    cout << "2" << endl;
    color[v] = 2;
    time_out[v] = dfs_timer++;
}

void resetVectors(int v) {
    if (adj.size() > 0) {
        adj.clear();
        adj.resize(v);
        for (int i; i < v;i++) {
            adj[i].resize(v);
        }
        color.clear();
        color.resize(v);
        time_in.clear();
        time_in.resize(v);
        time_out.clear();
        time_out.resize(v);
    }
}

int main(int argc, char **argv) {
    int v, e;
    int s, t;

    // get node and edge counts
    cin >> v >> e;

    cout << v << "," << e << endl;

    resetVectors(v+1);

    // read in edges
    for (int i = 0; i < e; i++) {
        cin >> s >> t;
        cout << s << "," << t << endl;
        adj[s][t] = 1;
    }

    dfs(1);

    cout << "=====================" << endl;

    return 0;
}
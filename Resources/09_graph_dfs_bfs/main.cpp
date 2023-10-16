#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define endl "\n"

using namespace std;

typedef vector< int >    vi;   // vector if ints
typedef pair< int, int > ii;   // pair of ints
typedef vector< ii >     vii;  // vector of int pairs

const int VISITED = 1;
const int UNVISITED = -1;

// Globals are OK in the problem solving world.
vi            search_order;  // vector of ints
vector< vii > AdjList;       // uses a vector of pairs (u=>v) (from=>to)

void printVector(vi vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
    }
    cout << endl;
}

void print2dVector(vector< vii > AdjList) {
    // To print the edges stored in the adjacency list
    for (int i = 1; i <= AdjList.size(); i++) {
        for (int j = 0; j < (int)AdjList[i].size(); j++) {
            cout << "[u:" << i << " -> v:" << AdjList[i][j].first
                 << " w:" << AdjList[i][j].second << "]";
        }
        cout << endl;
    }
}

ostream &operator<<(ostream &os, const ii &node) {
    return os << "[" << node.first << "," << node.second << "]";
}

void printGraph(vector< vii > g) {
    // To print the edges stored in the adjacency list
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < (int)g[i].size(); j++) {
            cout << "[u:" << i << " -> v:" << g[i][j].first
                 << " c:" << g[i][j].second << "]";
        }
        cout << endl;
    }
}

/**
 * Description:
 *    dfs - Depth first search on adjacency list graph
 *    This is a recursive solution
 * Params:
 *    int u : the starting node id to begin searching from
 * Returns:
 *    void : However it could return vector<int> (the search order)
 */
void dfs(int u) {
    search_order[u] = VISITED;
    cout << u << " ";
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        // cout<<v.first<<" "<<v.second<<endl;
        if (search_order[v.first] == UNVISITED) {
            dfs(v.first);
        }
    }
}

/**
 * Description:
 *    bfs - Breadth first search on adjacency list graph
 *    This is an iterative solution
 * Params:
 *    int u : the starting node id to begin searching from
 * Returns:
 *    void : However it could return vector<int> (the search order)
 */
void bfs(int u) {
    queue< int > q;  // we use a queue in a BFS

    q.push(u);  // prime the queue with our first node

    while (!q.empty()) {  // ummm
        int s = q.front();
        search_order[s] = VISITED;
        q.pop();

        cout << s << " ";  // for testing purposes only

        for (int t = 0; t < (int)AdjList[s].size(); t++) {
            ii v = AdjList[s][t];
            // cout<<v.first<<" "<<v.second<<endl;
            if (search_order[v.first] == UNVISITED) {
                q.push(v.first);
                search_order[v.first] = VISITED;
            }
        }
    }

    cout << endl;
}

/**
 * Directed Graph list representation with BFS and DFS methods
 */
int main(int argc, char **argv) {
    int n, m;
    int u, v;

    // read in:
    //   n (number of nodes)
    //   m (number of edges)
    cin >> n >> m;

    // resize adj list to accomodate number of nodes
    AdjList.resize(n + 1);

    // nodes are numbered starting at 1
    // so we need n+1 spots since we use node
    // nums as index.
    search_order.resize(n + 1, UNVISITED);

    // read in edges
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        cout << u << " " << v << endl;

        /**
         *  Here u->v is the edge and pair second term can be used to store
         * weight in case of weighted graph. This implementation hard codes '10'
         * as the weight as an example.
         */
        AdjList[u].push_back(make_pair(v, 10));
    }

    dfs(1);
    search_order.clear();
    // search_order.resize(0, UNVISITED);
    search_order.resize(n + 1, UNVISITED);
    cout << endl;
    bfs(1);

    return 0;
}
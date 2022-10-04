#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define endl "\n"

using namespace std;

typedef vector<int> vi;    // vector if ints
typedef pair<int, int> ii; // pair of ints
typedef vector<ii> vii;    // vector of int pairs

const int WHITE = 0;
const int RED = 1;
const int BLUE = 2;

vector<vii> ColorGraph;
vi nodeColors;

void printColors(vi vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == 0) {
            cout << "W ";
        } else if (vec[i] == 1) {
            cout << "R ";
        } else {
            cout << "B ";
        }
    }
    cout << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << i << " ";
    }
    cout << endl;
}

ostream &operator<<(ostream &os, const ii &node) {
    return os << "[" << node.first << "," << node.second << "]";
}

void printGraph(vector<vii> g) {
    // To print the edges stored in the adjacency list
    for (int i = 0; i < g.size(); i++) {
        cout << "[" << i << "->";
        for (int j = 0; j < (int)g[i].size(); j++) {
            cout << g[i][j];
        }
        cout << "]" << endl;
    }
}

/**
 * Description:
 *    isBipartite - Modified bfs to determine bipartite graph
 *    This is an iterative solution
 * Params:
 *    vector<vii> g: the graph to search
 * Returns:
 *    void : However it could return vector<int> (the search order)
 */
bool isBipartite(vector<vii> g, int u = 0) {
    queue<int> q; // we use a queue in a BFS
    int s;

    q.push(u); // prime the queue with our first node

    nodeColors[u] = RED;

    while (!q.empty()) { // ummm
        s = q.front();
        q.pop();

        for (int t = 0; t < (int)g[s].size(); t++) {
            if (nodeColors[g[s][t].first] == WHITE) {

                // cout << "s: " << s << " first: " << g[s][t].first << " t " <<
                // t
                //      << " color: " << nodeColors[s] << endl;
                if (nodeColors[s] == RED) {
                    // cout << "setting " << t << " to blue" << endl;
                    nodeColors[g[s][t].first] = BLUE;
                } else {
                    nodeColors[g[s][t].first] = RED;
                }
                q.push(g[s][t].first);
                printColors(nodeColors);
                cout << "queue: " << q.size() << endl;
            } else {
                if (nodeColors[s] == nodeColors[g[s][t].first]) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

/**
 *
 */
int main(int argc, char **argv) {
    int n, m;
    int u, v;

    // read in:
    //   n (number of nodes)
    //   m (number of edges)
    cin >> n >> m;

    // resize adj list to accomodate number of nodes
    ColorGraph.resize(n);

    // set all nodes to white color
    nodeColors.resize(n, WHITE);

    // read in edges
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        // cout << u << " " << v << endl;

        /**
         * Here u->v is the edge and pair second term can be used to store
         * weight in case of weighted graph. This implementation sets the
         * initial color to WHITE (or 0)
         */
        ColorGraph[u].push_back(make_pair(v, WHITE));
        ColorGraph[v].push_back(make_pair(u, WHITE));
    }

    printGraph(ColorGraph);
    printColors(nodeColors);
    cout << endl << isBipartite(ColorGraph) << endl;
    printColors(nodeColors);

    return 0;
}
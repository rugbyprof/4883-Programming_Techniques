#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

typedef vector<int> vi;         // vector if ints
typedef pair<int, int> ii;      // pair of ints
typedef vector<ii> vii;         // vector of pairs

int n; // number of vertices

int main(int argc, char **argv) {
    int T;
    int v, e;
    int s, t;

    cin >> T;
    

    while(T){

        // get node and edge counts
        cin >> v >> e;


        // read in edges 
        for (int i = 0; i < e; i++) {
            cin >> s >> t;
            //cout << s << " " << t << endl;

        }
        
        
        
        cout << "=====================" << endl;
        --T;
    }

    return 0;
}
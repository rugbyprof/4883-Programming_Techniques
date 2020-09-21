// Partial heap solution to problem 122

#include <iostream> 
#include <queue> 
#include <string>
#include <map>

using namespace std; 

int value(string LR){
    map<string,int> m;

    m["L"] = 1;
    m["R"] = 2;

    float v = 1;
    string s;
    for(int i=0;i<LR.size();i++){
        s = LR[i];
        v += (v + m[s]);
        
    }
    //cout<<LR<<":"<<v<<endl;
    return v;
}

// (11,LL) (7,LLL) (8,R)
// (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
// (3,L) (4,R) ()

//https://www.geeksforgeeks.org/priority-queue-of-pairs-in-c-ordered-by-first/
//https://www.geeksforgeeks.org/priority-queue-of-pairs-in-c-with-ordering-by-first-and-second-element/

typedef pair<int, int> pd; 

struct myComp { 
    constexpr bool operator()( 
        pair<int, int> const& a, 
        pair<int, int> const& b) 
        const noexcept 
    { 
        return a.second > b.second; 
    } 
}; 
  

int main () 
{ 

    priority_queue<pd, vector<pd>, myComp> pq; 

    pq.push(make_pair(11,value("LL")));
    pq.push(make_pair(7,value("LLL")));
    pq.push(make_pair(8,value("R")));
    pq.push(make_pair(5,value("")));
    pq.push(make_pair(4,value("L")));
    pq.push(make_pair(13,value("RL"))); 
    pq.push(make_pair(2,value("LLR"))); 
    pq.push(make_pair(1,value("RRR")));
    pq.push(make_pair(4,value("RR"))); 

    while(pq.size() > 0){
        pair<int, float> top = pq.top();  pq.pop();
        cout << top.first <<" "; 
    }

	return 0; 
} 

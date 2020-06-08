//Interview question for determining the minimum number of additional routes an
// airline would need to add to allow travelers to access any point in the network.
// from the starting point.  Inputs involve airports, routes, and starting point.

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iomanip>  //for setw()

std::vector<std::string>  airports = {"BGI","CDG","DEL","DOH","DSM","EWR","EYW","HND","ICN",
    "JFK","LGA", "LHR", "ORD","SAN","SFO","SIN","TLV","BUD"};

// existing one-way routes from departure to arrival
std::vector<std::vector<std::string>>  routes = {
    {"DSM","ORD"},
    {"ORD","BGI"},
    {"BGI","LGA"},
    {"SIN","CDG"},
    {"CDG","SIN"},
    {"CDG","BUD"},
    {"DEL","DOH"},
    {"DEL","CDG"},
    {"TLV","DEL"},
    {"EWR","HND"},
    {"HND","ICN"},
    {"ICN","JFK"},
    {"EYW","LHR"},
    {"LHR","SFO"},
    {"SFO","SAN"},
    {"SFO","DSM"},
    {"SAN","EYW"}
};

std::string startingAirport = "LGA";

// Algorithm for solution
// # process input
// # got through list of airports, assign each string an id
// # map<string,int> mp
// # vector<int> adj{n];  adjacency list
// # go through the routes
// # find stronlgly connected components via 
// # Korasaju's algorithm O(n+m)
// # who(u) determines arbitrary node within a strongly connected component to represent the
// # the node.
// # compress the interconnected graph based on components
// # vector <int> adj2[n]:
// # calculate the degree[n] of each node
// # who[u] == u
// # for edge (u,v) if who[u]!=who[v] adj2[who[u]].push_back(who[v]):
// # for edge (u,v) if who[u]!=who[v]: ++deg(who[v]):

// #find number of ndegree=0 which are not S (start point) in compressed graph
// #count number of u such that who[u]==u and deg[u]==0 and u!=who[S]
 
const int mxN = 1e5;  // Arbitrary maximum number of airports
std::vector<int> adj[mxN], reverseAdj[mxN];  // Node adjacency lists
std::stack <int> st; 
int who[mxN], deg[mxN];
bool visited[mxN], vis2[mxN];

void dfs1(int u){ //Depth First Search 1
    visited[u] = true;
    std::cout << "Visit1: ["<< u <<"] at " << airports[u] << std::endl;
    for (int v : adj[u])
        if(!visited[v])
            dfs1(v);
    st.push(u);
}

void dfs2(int u, int rep){ //Depth First Search 2
    vis2[u] = true;
    who[u] = rep;
    std::cout << "Visit2: ["<< std::setw(2) << u << "] at " << airports[u] << " Rep by: [" << std::setw(2)<< rep << "]" <<  std::endl;
    for (int v : reverseAdj[u]){ // why using reverse wasn't clear but it's part of Korasaju's algo
       if(!vis2[v]){
            dfs2(v,rep);
       }
    }
}

 int solve (std::vector<std::string> airports, std::vector<std::vector<std::string>> routes, std::string startingAirport){
     int n=airports.size();
     std::cout << "Size of airports: " << n << std::endl;
     std::map<std::string,int> mp; //could be an unordered map for less complexity

    // Process to create map of airport strings tags associated with a node id
     for(int i=0; i<n; i++){
        mp[airports[i]]=i;
        std::cout << airports[i] << " idx: ["<< std::setw(2) << i << "]" << std::endl;
     }
    // Create a adjacency list of the graph node edges based upon the routes deciphered from
    // airport tags to respective node ids
     for(std::vector<std::string> edge: routes){
         adj[mp[edge[0]]].push_back(mp[edge[1]]);  //# store the id in the adjacency list
         std::cout << edge[0] << "(" << std::setw(2) << mp[edge[0]] << ") adj to > " << edge[1] << "(" << std::setw(2) << mp[edge[1]]<< ")" << std::endl;
     }

    // Swap i,j to get the reverse (transposed) direction of the adjacency list
    for(int i=0; i<n; i++){
        for(int j : adj[i]){
            reverseAdj[j].push_back(i);
            std::string dest = routes.at(i).at(1);
            std::string dep = routes.at(i).at(0);
            std::cout << "R " << dest << " from " << dep << std::endl;
        }
    }

    // First pass of depth first search as part of Korasaju's algo
    for(int i=0; i<n; i++){
        if(!visited[i])
            dfs1(i);
    }

    // Re-examine items from the stack, as part of Korasaju's algo
    // which creates a compressed graph
    while(st.size()>0){
        int u=st.top();
        st.pop();
        if(!vis2[u])
            dfs2(u,u);
    }
    // calculate the degree[n] of each node
    for(int i=0; i<n; i++)
        for (int j : adj[i]){
            if(who[i]!=who[j]){
                ++deg[who[j]];
                std::cout << "["<< who[j]<<"] has degree: "<< deg[who[j]] << std::endl;
            }
        }

    int ans=0;
    for(int i=0; i<n; i++){ //interating through original graph, but only want to iterate in compressed graph
        if(who[i]==i && deg[i]==0 && i!=who[mp[startingAirport]]){
            ans++;
            std::cout << "Zero degree at: [" << std::setw(2) << i << "] add route to [" << std::setw(2) << who[i] << "]" << std::endl;
        }
    }
    return ans;

 }

 int main(){
     int ans = solve(airports, routes, startingAirport);
     std::cout << "The number of additional routes needed to access all airports is: "<< ans << std::endl;
 }

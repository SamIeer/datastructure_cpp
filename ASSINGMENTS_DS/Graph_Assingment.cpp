// #include <iostream>
// #define I 32767  //INFINITY
// #define V 7 // # of vertices in graph
// #define E 9 // # of edges in graph

// using namespace std;

// void PrintMST(int T[][V-1], int A[][E]){
//     cout << "\nMinimum cost spanning Tree Edges\n" << endl;
//     for (int i {0}; i<V-1; i++){
//         cout << "[" << T[0][i] << "]----[" << T[1][i] << "]" << endl;
//     }
//     cout << endl;
// }

// //set operations: UNion and Find
// void Union(int u,int v,int s[]){
//     if (s[u] < s[v]){
//         s[u] += s[v];
//         s[v] = u;
//     }else {
//         s[v] += s[u];
//         s[u] = v;
//     }
// }

// int Find(int u, int s[]){
//     int x = u;
//     int v = 0;

//     while (s[x] > 0){
//         x = s[x];
//     }

//     while(u != x){
//         v = s[u];
//         s[u] = x;
//         u = v;
//     }
//     return x;
// }

// void KruskalsMCST(int A[3][9]){
//     int T[2][V-1];    //solution array
//     int track[E] {0}; //Track edges that are included in the solution
//     int set[V+1] = {-1,-1,-1,-1,-1,-1,-1,-1 }; // array for finding cycle

//     int i {0};
//     while (i < V-1){
//         int min =I;
//         int u {0};
//         int v {0};
//         int k {0};

//         //Find a minumum cost edge from full graph 
//         for (int j {0}; j<E; j++){
//             if (track[j] == 0 && A[2][j] < min){
//                 min = A[2][j];
//                 u = A[2][j];
//                 v = A[1][j];
//                 k = j;
//             }
//         }

//         //check if the selected min cost edge (u ,v) forming a cycle or not
//         if(Find(u , set) != Find(v, set)){
//             T[0][i] = u;
//             T[1][i] = v;
            
//             //perform union
//             Union(Find(u,set), Find(v, set), set);
//             i++;
//         }
//         track[k] = 1; //k edge is considered
//     }
//     PrintMST(T,A);
// }

// int main(){
//     int edges[3][9] = {
//           {1,1,2,2,3,4,4,5,5},
//           {2,6,3,7,4,5,7,6,7},
//           {25,5,12,10,8,16,14,20,18}
//     };
//     KruskalsMCST(edges);

//     return 0;
// }

// Answer 3:
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge
struct Edge {
    int dest;
    int weight;
};

// Function to find the shortest path from a source vertex to all other vertices using Dijkstra's algorithm
vector<int> dijkstra(vector<vector<Edge>>& graph, int source) {
    int V = graph.size(); // Number of vertices
    vector<int> distance(V, INT_MAX); // Initialize distances to infinity
    vector<bool> visited(V, false); // Initialize visited array

    // Priority queue to store vertices with their current shortest distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (distance, vertex)

    // Set distance of source vertex to 0
    distance[source] = 0;
    pq.push({0, source}); // Insert source vertex into priority queue

    // Dijkstra's algorithm
    while (!pq.empty()) {
        int u = pq.top().second; // Extract vertex with smallest distance
        pq.pop();

        // Mark vertex as visited
        visited[u] = true;

        // Relax all outgoing edges from vertex u
        for (Edge& edge : graph[u]) {
            int v = edge.dest;
            int weight = edge.weight;

            // If vertex v is not visited and new distance is shorter
            if (!visited[v] && distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                // Update distance of vertex v
                distance[v] = distance[u] + weight;
                // Insert vertex v into priority queue with updated distance
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

int main() {
    // Example graph representation (adjacency list)
    int V = 5; // Number of vertices
    vector<vector<Edge>> graph(V);

    // Add edges to the graph
    graph[0].push_back({1, 10});
    graph[0].push_back({2, 5});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 3});
    graph[2].push_back({3, 9});
    graph[2].push_back({4, 2});
    graph[3].push_back({4, 4});
    graph[4].push_back({3, 6});

    int source = 0; // Source vertex

    // Find the shortest path from the source vertex to all other vertices
    vector<int> shortestDistances = dijkstra(graph, source);

    // Output the shortest distances from the source vertex to all other vertices
    cout << "Shortest distances from source vertex " << source << " to all other vertices:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}

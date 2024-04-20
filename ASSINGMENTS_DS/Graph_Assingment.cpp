
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


//Answer 2:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};
// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};
// Comparator function to sort edges based on weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}
// Find operation of union-find (with path compression)
int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
// Union operation of union-find (with union by rank)
void Union(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
// Function to find the MST using Kruskal's algorithm
vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
    // Sort the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), compareEdges);
    // Allocate memory for subsets
    vector<Subset> subsets(V);
    // Initialize each subset with its parent and rank
    for (int i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    // Initialize variables
    vector<Edge> MST;
    int e = 0, i = 0;

    // Loop until we have (V-1) edges in the MST
    while (e < V - 1 && i < edges.size()) {
        // Get the next edge
        Edge next_edge = edges[i++];

        // Find the subsets of the source and destination vertices
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge doesn't cause a cycle, include it in MST
        if (x != y) {
            MST.push_back(next_edge);
            Union(subsets, x, y);
            e++;
        }
    }

    return MST;
}

int main() {
    // Example graph representation
    int V = 5; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}, {3, 4, 8}, {1, 4, 7}, {2, 4, 12}
    };

    // Find the minimum spanning tree
    vector<Edge> MST = kruskalMST(edges, V);

    // Output the edges of the minimum spanning tree
    cout << "Edges in the minimum spanning tree for the entire graph:" << endl;
    for (const Edge& edge : MST) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}

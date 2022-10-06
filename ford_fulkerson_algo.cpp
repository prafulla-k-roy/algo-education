// Ford-Fulkerson algorithm in C++

#include <limits.h>
#include <string.h>

#include <iostream>
#include <queue>
using namespace std;
// defining V=6 because
    // number of vertices is 6.
#define V 6
// Using BFS as a searching algorithm
// visited array will keep track
// of all the visited vertices.
bool bfs(int rGraph[V][V], int s, int t, int parent[]) {
  bool visited[V];
  // Making all vertices as non-visited.
  memset(visited, 0, sizeof(visited));
// Queue to keep vertices in Queue
// for doing BFS. 
  queue<int> q;
  // Add source in q and mark it visited. 
  q.push(s);
  visited[s] = true;
  // Make parent of source -1.
  parent[s] = -1;
// Standard BFS loop
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v = 0; v < V; v++) {
      if (visited[v] == false && rGraph[u][v] > 0) {
        q.push(v);
        parent[v] = u;
        // If we found a connection to sink 
                    // from any of the nodes. We will return
                    // true i.e. augmenting path exists. 
        visited[v] = true;
      }
    }
  }

  return (visited[t] == true);
}
// If we can't reach to sink node then
        // return false which will indicate
        // that there is no augmenting path left.

// Applying fordfulkerson algorithm
int fordFulkerson(int graph[V][V], int s, int t) {
  int u, v;
// Creating a residual graph with residual
        // capacity as the capacity of the original graph.
  int rGraph[V][V];
  // residual_g[i][j] indicates residual capacity
        // of edge from i to j. If residual_g[i][j]==0
        // it means no edge exists.
  
  for (u = 0; u < V; u++)
    for (v = 0; v < V; v++)
      rGraph[u][v] = graph[u][v];
// Parent array will store the augmenting
        // path found during the BFS. 
  int parent[V];
  // Initializing max flow as 0 i.e. there
        // is no flow initially.
  int max_flow = 0;
// Iterating in breadth-first manner till there
        // is augmenting path from source to sink.
  
  // Updating the residual values of edges
  while (bfs(rGraph, s, t, parent)) {
    int path_flow = INT_MAX;
    // Finding minimum residual capacity of the
            // edges in augmenting path i.e. maximum 
            // flow through that path.
    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      path_flow = min(path_flow, rGraph[u][v]);
    }

    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      rGraph[u][v] -= path_flow;
      rGraph[v][u] += path_flow;
    }
    // Adding maximum flow of this path
            // to the overall flow.
    max_flow += path_flow;
  }
// Returning our answer
        // i.e. Maximum flow through
        // the network. 
  return max_flow;
}

int main() {
  int graph[V][V] = {{0, 8, 0, 0, 3, 0},
             {0, 0, 9, 0, 0, 0},
             {0, 0, 0, 0, 7, 2},
             {0, 0, 0, 0, 0, 5},
             {0, 0, 7, 4, 0, 0},
             {0, 0, 0, 0, 0, 0}};

  cout << "Max Flow: " << fordFulkerson(graph, 0, 5) << endl;
}

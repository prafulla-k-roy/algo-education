/* 
Hello Readers, Here we will learn about breadth first search in depth ;)
Before Jumping to code, let's visualize BFS algo first with the help tree (its easier to explain with it)
      5
    /   \
   h     1  
  / \     \
 v   @     G
The BFS traversal of the given tree will look something like this: 5 h 1 v @ G
i.e. we are going floor to floor from the top.

You can traverse the same way in a Graph. A popular way to describe graph is using adjacency list. We will discuss the algorithm using an example.
*/

// Here in this function, we are provided with v -> no. of vertices, adj -> to describe which vertex is connected which vertex.
/* eg. 
v -> 6
adj -> 
  0 -> 1, 2
  1 -> 5
  2 -> 3, 4
in this case output would be: 0, 1, 2, 5, 3, 4
*/
void bfs(int vertices, vector<int> adj[]) {  
    // for utility, to check if a particular vertex is visited or not.
    vector<bool> visited(vertices, false);

    // visiting each vertex  
    for (int i = 0; i < vertices; ++i) {
        // checking if it is already visited, if not ..
        if (!vis[i]) {
            // .. then we use queue to store other connected vertex, then traverse them one by one 
            queue<int> q;
            // marking we have visited
            vis[i] = true;
            // later, we need to iterate for that vertex too..
            q.push(i);
             
            // +++ heart of bfs
            while (!q.empty()) {
                // we will visited current node and all immediate child nodes
                int node = q.front();
                q.pop();
                cout<<node<<" ";
                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        }
    }
}

// use pencil paper to really get the hang of it!
// Happy Hacktober

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//this method adds an edge with a node in the form SOURCE--->DESTINATION
void addedge(vector<int>adj[],int source,int destination)
{
    adj[source].push_back(destination);
}
//this method is used to manually enter the whole graph
void createGraph(vector<int>adj[],int v)
{
    int i,dest,numEdges,j;
    for(i=0;i<v;i++)
    {
        cout<<"Enter number of edges attached from vertex "<<i<<" - ";
        cin>>numEdges;
        cout<<"enter neighbouring nodes:"<<endl;
        for(j=0;j<numEdges;j++)
        {
            cin>>dest;
            addedge(adj,i,dest);           
        }

    }
}
//this method is used to print the graph in the form NODE--NEIGHBOURS
void printGraph(vector<int>adj[],int v)
{
    //the nodes along with its neighbours are printed
    for(int i=0;i<v;i++)
    {
        cout<<endl<<i<<" -> "<<endl;
        for(auto x:adj[i])
        cout<<x<<" ";
    }
}

//BREADTH FIRST SEARCH 
void bfs(vector<int>adj[],int v,int start)
{
    //vector 'visited' marks whether a node has already been visited or not
    vector<bool>visited(v);
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    //a queue is created to push the nodes visited during BFS
    queue<int> q;

    q.push(start);
    visited[start]=true;
    
    //once a node is pushed onto the queue, all of its neighbors are also pushed in q
    while(q.empty()!=true)
    {
        int f = q.front();
        q.pop();
        //the neighbors of the node are pushed
        for(auto x:adj[f])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x]=true;
            }
        }
        //the node is printed after being visited
        cout<<f<<" ";

    }
    
}
//DRIVER CODE
int main()
{
    int v;
    //cout<<"Enter number of vertices - ";
    //cin>>v;
    //manually enter value for 'v' if createGraph function is in use
    v=5;
    vector<int>adj[v];

    //BOTTOM FUNCTION CAN BE CALLED TO MANUALLY ENTER THE EDGES OF THE GRAPH

    //createGraph(adj,v);
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,0,3);
    addedge(adj,1,2);
    addedge(adj,2,3);
    addedge(adj,3,4);
    addedge(adj,2,4);
    
    cout<<endl<<"THE GRAPH IS:"<<endl;
    //this method will print the graph created
    printGraph(adj,v);
    cout<<"APPLYING BFS:"<<endl<<endl;

    //starting vertex is the vertex from where we start applying BFS
    cout<<"Enter starting vertex - ";
    int start;
    cin>>start;
    bfs(adj,v,start);
    
}

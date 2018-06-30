
#include<iostream>
#include <list>
using namespace std;

class Graph
{
    int V;   
    list<int> *adj; 

    void printAllPathsUtil(int , int , bool [], int [], int &,int mat[1000][1000] ,int               color[1000]);
   
 
public:
     int minWeight;
    Graph(int V);   
    void addEdge(int u, int v);
    void printAllPaths(int s, int d ,int mat[1000][1000], int color[1000]);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); 
}

void Graph::printAllPaths(int s, int d ,int mat[1000][1000],int color[1000] )
{
   
    bool *visited = new bool[V];
 
  
    int *path = new int[V];
    int path_index = 0; 
 
 
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
   
    printAllPathsUtil(s, d, visited, path, path_index , mat, color);
}

void Graph::printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index ,int mat[1000][1000],int color[1000])
{
    visited[u] = true;
    path[path_index] = u;
    path_index++;
 
    if (u == d)
    {
            int blackDist = 0;
            int sumWeight = 0;
            for (int i = 0; i < path_index; i++)
            {
                int val , u , v;
                // cout << path[i] << " ";
                if(i > 0)
                {
                    u = path[i-1];
                    v = path[i];
                    val = mat[u][v]; 
                }
                else
                {
                    u = path[i];
                    v= path[i];
                    val = 0;
                }
                blackDist += color[v];
                sumWeight += val;
            }
            if(blackDist <= 1 )
            {
                if(sumWeight < this -> minWeight)
                {
                    this -> minWeight = sumWeight;
                }
            }
            //cout << endl;
    }
    else 
    {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index , mat, color);
    }
    path_index--;
    visited[u] = false;
}

int main()
{
    
    int N ,M;
    int u , v, l;
    cin>>N>>M;
    Graph g(N);
    int mat[1000][1000];
    int color[1000];
    for(int i = 0; i < M ; i++)
    {
        cin>>u >>v>>l;
        mat[u-1][v-1] = l;
        g.addEdge(u-1, v-1);
    }
    for(int i = 0; i < N ; i++)
    {
        int c;
        cin>> c;
        if(c == 0)
            color[i] = -1;
        else
            color[i] = 1;    
    }
    g.minWeight = 1000000;
    int s = 0, d = N-1;
   
    g.printAllPaths(s, d , mat, color);
    if(g.minWeight == 1000000)
        cout<< -1;
    else    
        cout<< g.minWeight<<endl;
    return 0;
}

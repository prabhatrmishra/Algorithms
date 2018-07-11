#include<iostream>
#include <list>
#include<algorithm>
using namespace std;

class Graph
{
    int V;   
    list<int> *adj; 

public:
    Graph(int V);  
    void addEdge(int u, int v);
    int getMaxSum(int mat[9][9] , int X);
  
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

int Graph :: getMaxSum(int mat[9][9] , int X)
{ 
    int max_res;
    for(int i = 0; i < 9 ; i++)
    {
        list<int> neig = this->adj[i];
        list<int>::iterator it;
        for( it = neig.begin(); it != neig.end(); ++it)
        {
            
            int s = i + 1;
            int d = (*it) + 1;
            int w = mat[s-1][d-1];
            int t = X/w;
            getCost(s , d ,w ,t);
            int res = (t *( s + d)) + max(s ,d); 
            cout<<"S : "<< s<<" D : "<< d<< "RES "<< res<<endl;
            if(res >= max_res )
                max_res = res;
           // cout<<*it<<endl;
        }
    }
    return max_res;
}

int main()
{
    
    int X, u, v , w;
    Graph g(9);
    int mat[9][9];
    cin>>X;
    for(int i =0; i < 12; i++)
    {
        cin>> u >>v >>w;
        mat[u-1][v-1] = w;
        g.addEdge(u-1, v-1);
    }
   int val =  g.getMaxSum (mat , X);
    cout<<val<<endl;
    return 0;
}
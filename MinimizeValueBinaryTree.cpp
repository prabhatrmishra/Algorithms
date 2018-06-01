#include <iostream>
#include<vector>
#include<stdio.h>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int ll;

vector< struct Node *> nodeArray;
struct Node
{
    ll data;
    struct Node *left;
    struct Node *right;
    
};


struct Node* createNode(ll val)
{
    struct Node* node = new Node;
    node->data = val;
    node ->left = NULL;
    node ->right = NULL;
    return (node);
}

ll waveOp(struct Node * ptr){
    ll sum = 0;
    if(ptr== NULL)
        return 0;
   
    else
    {
        sum += ptr->data + waveOp(ptr->left) 
            + waveOp(ptr -> right);  
    } 
    ptr -> data = sum;
    return sum; 
}

ll minDistance(struct Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL || root->right == NULL)
        return 0;

    return 1 + min(minDistance(root->left),
                      minDistance(root->right));
}

ll findTreeSum(struct Node * root){
    ll sum = 0;
    if(root == NULL )
        return 0;
    else 
        sum += (root->data + findTreeSum(root ->left) +
                 findTreeSum(root ->right));
    return sum;
}
int main()
{
    ll N, X, val, u ,v,treeSum;
    cin>>N>>X;
    for(ll i =0; i < N ; i++)
    {
        cin>>val;
        struct Node * newNode = createNode(val);
        nodeArray.push_back(newNode);   
    }
    
    ll edges = N-1;
    while(edges --)
    {
        cin>>u >>v;
        if(v == (2 * u))
            nodeArray[u-1] ->left = nodeArray[v-1];   
        else if( u == (2 * v))
            nodeArray[v-1] ->left = nodeArray[u-1];
        else if(v = (2 * u + 1))
            nodeArray[u-1]-> right = nodeArray[v-1];
        else if(u = (2 * v + 1))
            nodeArray[v-1] ->right = nodeArray[u-1];
    }
   // for(int i = 0; i < N ; i++)
   //     cout<< nodeArray[i]->data<<"___"<<endl;
   waveOp(nodeArray[0]); 
    // waveOp(nodeArray[0]); 
    // for(int i = 0; i < N ; i++)
     //   cout<< nodeArray[i]->data<<"___"<<endl;
   ll dist = minDistance(nodeArray[0]);
  // cout<<"Dis : "<< dist<<endl;
    ll sum = findTreeSum(nodeArray[0]);
    //cout<<"Sum : "<< sum<<endl;
   treeSum = sum + ((dist+  2)* X);
   cout<<treeSum<<endl;
   return 0;
}
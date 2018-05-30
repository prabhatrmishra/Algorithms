#include<iostream>
#include<map>
#include<vector>
#include <algorithm>
using namespace std;
typedef long long  ll;
struct Node
{
    ll data;
    struct Node * parent;
    vector<struct Node *> child_list;
    // struct Node* left, *right;
};

 
vector< struct Node *> nodeArray;
vector<ll> sumArray;
map<struct Node * , ll> mp;
map<struct Node *, int>isVisited;
struct Node* newnode()
{
    struct Node* node = new Node;
    node->data = 0;
    node->parent = NULL;
    vector<struct Node *>child_list;
    node->child_list = child_list;
    return (node);
}

ll sumSubtreeUtil(struct Node *ptr,  int sum)
{
    ll cur_sum =0 ;
    if (ptr == NULL)
    {
        return 0;
    }
  
     vector<struct Node *> lst = ptr -> child_list;
     if(lst.size() == 0)
        {
         //  cout<<"Leaves Node"<<ptr->data<<endl;
            cur_sum += ptr->data;
            isVisited[ptr] = 1;
        }
    else{
             if(isVisited[ptr] == 0)
             {
                   cur_sum += (ptr->data) ;
                   isVisited[ptr] = 1;
             }
               
             for(ll i = 0; i < lst.size(); i++)
             {
                  struct Node * child = lst[i];
                  if(isVisited[child] == 0)
                    cur_sum  +=  sumSubtreeUtil(child, sum );
                //else
                    //return 0;
             }
       }
    mp[ptr] =  cur_sum;
    return cur_sum;
}
 
// Wrapper over sumSubtreeUtil()
void sumSubtree(struct Node *root, ll sum)
{
    // Initialize sum of subtree with root
    int cur_sum = 0;
    
    cur_sum =  sumSubtreeUtil(root,  sum);
    mp[root] = cur_sum;
    return;
}
 
void  getSum(){
    for(ll i = nodeArray.size()-1; i >= 0; i--)
    {
        struct Node * curr = nodeArray[i];
         ll sum = curr->data;
        vector<struct Node *> cl= curr->child_list;
        for(int j = 0; j < cl.size() ; j++)
        {
             struct Node * child = cl[j];
            
            sum += mp[child];
        }
        
        mp[curr] = sum; 
    }
    return;
}
void clearIsVisited(){
    for(int i =0 ; i < nodeArray.size(); i ++)
    {
        struct Node * temp = nodeArray[i];
        isVisited[temp]=  0;
    }
}
// driver program to run the case
int main()
{
    ll n,q, x, u, v,val;
    cin>>n>>q>>x;
    for(ll i = 0; i < n ; i++)
    {
         struct Node * newTemp= newnode(); 
         nodeArray.push_back(newTemp);
    }
   
    for(ll i =0; i < n-1; i++)
    {
          cin>>u >> v;
          struct Node * u_node = nodeArray[u-1];
          struct Node * v_node = nodeArray[v-1];
         v_node->parent = u_node;
        v_node->child_list.push_back(u_node);
        u_node->child_list.push_back(v_node); 
      //  u_node->parent = v_node;

    }
    for(ll i = 0; i < n; i++)
    {
        ll val;
        cin>>val;
        struct Node * curr  = nodeArray[i];
        curr->data = val; 
    }
    
     //for(int i = 0; i < n; i++)
      //   cout<<nodeArray[i]->data<<","<<endl;
       // sumSubtree(nodeArray[0],x);
        // getSum();
        while(q--)
        {
                clearIsVisited();
                ll a,d, val = 0;
                cin >>d>>a;
                struct Node * curr;
                curr = nodeArray[d-1];
                curr ->data += a;
               mp[curr] += a; 
            /*    struct Node * parent_node = curr->parent;
              while(parent_node != NULL)
                {
                      struct Node *  _parent = parent_node;
                      if(isVisited[parent_node] == false)
                      {
                            mp[parent_node] += a;
                            parent_node = _parent ->parent;
                      }
                       
                }*/
                sumSubtree(nodeArray[0],x); 
                for(ll i = 0; i < nodeArray.size(); i++ )
                {   
                    curr = nodeArray[i];
            //    cout<<"Sum at node "<< i+1 <<"  : "<<mp[curr]<<endl;
                    if(mp[curr] > x)
                        val++;
                }
               cout<<val<<endl;
             
    }
   return 0;
}

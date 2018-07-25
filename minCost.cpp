#include<iostream>
#include <math.h>
using namespace std;

typedef long long ll;

ll findCost(ll x ,ll n , ll a, ll b )
{
    ll c1 = a * pow(x, 2) + b * pow((n - x), 2);
    ll c2 = a * pow(x-1, 2) + b * pow((n-x +1 ), 2);
    ll c3 = a * pow(x+1, 2) + b * pow((n -x -1 ), 2);
  
    ll cost = c1;
    if(cost > c2 )
        cost = c2;
    if(cost > c3)
        cost = c3;
    //  cout<<c1 <<" : "<<c2<<" : "<<c3<<" : "<<cost<<endl;
    return cost;
}

int main()
{
    ll t, n ,a, b;
    ll x, y;
    cin>>t;
    while(t--)
    {
        cin>> n>>a>>b;
        x = (n *b)/ (a + b);
        cout<<findCost(x, n, a, b)<<endl;
    }
    
    return 0;
}
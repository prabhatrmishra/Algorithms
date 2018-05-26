#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;

typedef unsigned long long int ll;


int main() {
    vector<ll>a;
    map<ll ,ll> m;
    ll n,q ,in,l,r, sum ;
    
   // cin>>n;
    scanf("%lld",&n);
   // cout<<n;
   for(ll i =0 ; i< n; i++)
    {
     //cin>> in;
      scanf("%lld",&in);
      a.push_back(in);
    }
    cin>>q;
    
    while(q--)
    {   
        m.clear();
        map<ll,ll>:: iterator it;
        //cin>>l>>r;
        scanf("%lld%lld",&l,&r);
        for(ll i = l-1; i < r; i++)
        {
            ll key = a[i];
             it = m.find(key);
            if(it == m.end())
            {
                m[key] =1;
            }
            else
            {
                it->second = (it->second) +1;
            }
        }
         sum = 0;
        for(it = m.begin(); it != m.end(); ++it)
        {
          
            ll key = it ->first;
            ll val = it->second;
            if(val %2 != 0)
            {
                sum  += (key* val);
            }
            
        }
         printf("%lld \n", sum);
      
    }
  
}
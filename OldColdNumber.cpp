#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
typedef  long long  ll; 
// Complete the extraLongFactorials function below.

int isOld(ll num)
{
    if(num  == 0)
        return 0; 
    else
    {
        ll c = -1,v;
        if(num % 2 == 0)
             c = (num / 2);
        else
             c = (num / 2) + 1;
        if((num % c) == 0)
            v=  0;
        else
            v = 1;
      // cout<<"v value for "<<num << " : "<<c<<endl; 
        return v;
    }
 
}
int main()
{
    ll n , q, tmp ,l , r , num, res, c_old, n_old, T;
    vector<ll> a;
    
    
    cin>> T;
    while(T--)
    {
            cin>>n;
            for(int i = 0 ; i < n ; i++)
            {
                cin>>tmp;
                a.push_back(tmp);
            }

            cin>>q;
            while(q--)
            {
                c_old = 0;
                n_old = 0;
                cin>>l>>r;
                for(ll i = l-1 ; i <= r-1 ; i++)
                {
                    num = a[i];
                    
                   // cout<<"num value: "<<num<<endl; 
                    if(isOld(num) == 0)
                        c_old ++;
                    else
                        n_old ++;
                }
                if((n_old - c_old) > 0)
                    res = (n_old - c_old);
                else
                    res = 0;
                //cout<<"old : "<< n_old<<"cold : "<< c_old<<endl;
                cout<<res<<endl;
              }
    }
   
    

    return 0;
}

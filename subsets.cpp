#include <cmath>
#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<int> list_set;
int mp[2048];

void calDP(int a[], int n , int k)
{
    int c = 0;
    for (int i = 0; i < n ; i++)
    {   
        mp[c] = a[i];
        c++;
    }
   
    for(int i = 2; i <= k ; i++ )
    {
        int s = c;
        for(int j = 0; j < n ; j++)
        {
            for(int f = (s - n-1 ) ; f < s; f++)
            {
                mp[c] = ( mp[f] | a[j]);
                //cout<<  mp[c]<< endl;
                c++;
            }
        }
    }

    for(int i = 0 ; i < 2048; i++)
    {
        list_set.insert(mp[i]);
    }
    return;
}
int main()
{
    int n,k;
     set <int > :: iterator itr;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i <n ; i++)
            cin>>a[i];
    calDP(a, n ,k);
  //  for(itr = list_set.begin(); itr != list_set.end(); itr++)
   //     cout<<*itr<< " , ";
    //cout<< endl;
    cout<<list_set.size()-1<< endl;
    return 0;
}
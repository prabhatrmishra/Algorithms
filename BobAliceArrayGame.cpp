#include<iostream>
#include<vector>
#include <cmath>
using namespace std;
typedef unsigned long long  ll; 
#define even 1
#define odd 0
ll a[200000];
int getMaxIndex(int start ,int end)
{
    if(a[start] >= a[end])
        return start;
    else
        return end;
}

ll getAbsDiff(ll a , ll b)
{
    if(a >= b )
        return (a - b);
    else
        return (b - a);
}
int main()
{
    ll N, val, alex_score = 0, bob_score = 0 ;
    int start, end;  
    int flag , turn , oddSelect;
    cin>>N;
    for(int i = 0; i < N ; i++)
    {
        cin>> val;
        a[i] = val;
    }
    
    if((N % 2) == 1)
    {
        start =  (N/2);
        end = start;
        turn = odd;
    }
    else
    {
        start = (N/2) -1;
        end = (N/2);
        turn = even;
    }
    if(turn == odd )
    {
       alex_score += a[start];
        start --;
        end ++;
        turn = even; flag  = 1; 
    }
    else
    {
         flag = 0;
    }
   
    while((start >= 0) || (end < N) )
    {
        //cout<<"Start : "<< start<<"End : "<<end<<endl;
        int val ;
        if((turn == odd) && (oddSelect == 0)  )
        {
            val = a[start];
            start --;
        }
         if((turn == odd) && (oddSelect == 1)  )
        {
            val = a[end];
            end++;
        }
        if(turn == even)
        {
            int index = getMaxIndex(start , end);
          //  cout<<"Index : "<< index<<endl;
             val = a[index];
            if(index == start)
            {
                start -- ;
                oddSelect = 1;
            }
            if(index == end)
            {
                end ++;
                oddSelect = 0;
            }
        }
        if(flag == 0 )
        {
             alex_score += val;
           // cout<<"Alex Score : "<< alex_score<<endl;
        }
           
        else
        {
            bob_score += val;  
            //cout<<"Bob Score : "<< bob_score<<endl;
        }
    
        flag = 1-flag;
        turn = 1- turn;
    }
    cout<<alex_score<<endl;
    cout<< bob_score<<endl;
    ll diff = getAbsDiff(alex_score, bob_score);
    
    if(alex_score >= bob_score)
        cout<<"Alex " << diff<<endl;
    else
        cout<<"Bob " << diff << endl;
    return 0;
}
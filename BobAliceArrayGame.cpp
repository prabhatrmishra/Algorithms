#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long  ll; 
typedef even 1;
typedef odd 0;
ll a[200000];
int getMaxIndex(int start ,int end)
{
    if(a[start] >= a[end])
        return start;
    else
        return end;
}
int main()
{
    ll N, val, alex_score, bob_score ;
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
       alex_score = a[start];
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
            alex_score += val;
        else
            bob_score += val;
        flag = 1-flag;
    }
}
    ll diff = abs(alex_score -bob_score);
    if(alex_score >= bob_score)
        cout<<"Alex" << diff<<endl;
    else
        cout<<"Bob" << diff << endl;
    return 0;
}

#include <iostream>
#include <sstream>
#include<vector>
#define max_query_word 10
#define max_relevent_pages 5
#define max_program_word 10


using namespace std;


vector<vector<string> > program;
vector<vector<string> > query;

void insertionSort(int arr[], int index[],int n)
{
   int i, key,key1,j;
   for (i = 1; i < n; i++)
   {
        key1=index[i];
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] < key)
       {
           arr[j+1] = arr[j];
           index[j+1]=index[j];

           j = j-1;

       }
       arr[j+1] = key;
       index[j+1]=key1;
   }
return;
}




void printRankForGivenQuery(vector<string> & passed_query)
{
    int strength_list_for_query[10]={0};
    int program_order_by_strength[10]={0};
    for(int i=0;i<program.size();i++)

    {
        int total_strength_for_given_program=0;
        for(int k=0;k<program[i].size();k++)
        {
            for(int j=0;j< passed_query.size();j++)

            {
                if(program[i][k]==passed_query[j])
                    total_strength_for_given_program=total_strength_for_given_program +(max_query_word-j)*(max_program_word-k);
            }

        }
        if(total_strength_for_given_program!=0)
        {

            strength_list_for_query[i]=total_strength_for_given_program;
            program_order_by_strength[i]=i+1;
        }


    }

//insertion sort is used for stable sort
    insertionSort(strength_list_for_query,program_order_by_strength,program.size());
    int limit;
    if(program.size()<max_relevent_pages)

        limit=program.size();
    else
        limit=max_relevent_pages;

    for(int k=0;k<limit; k++)
    {
        if(program_order_by_strength[k]>0)
        cout<<"P"<<program_order_by_strength[k]<<" ";
    }
cout<<"\n";

return;
}






int main()
{
    string line;
    getline(cin,line);
    while(line!="$")
    {


    if(line.at(0)=='P')
    {
    line=line.substr(line.find_first_of(" \t")+1);
    istringstream iss(line);
    string word;
    vector<string>v1;
    while(iss >> word)
      v1.push_back(word);
    program.push_back(v1);
    }



    if(line.at(0)=='Q')
    {
    line=line.substr(line.find_first_of(" \t")+1);
    istringstream iss(line);
    string word;
    vector<string>v1;
    while(iss >> word)

      v1.push_back(word);
      query.push_back(v1);
    }



    getline(cin,line);
    if(line=="$")
        break;
}


for(int i=0;i<query.size();i++)
{
    int query_no=i+1;
    cout<<"Q"<<query_no<<":";
    printRankForGivenQuery(query[i]);

}
 return 0;
}

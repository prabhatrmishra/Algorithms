#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int runRobot(vector<string> grid, int i, int j, int n, int m){
    int l =1, u= 1;
    int sum = 1;
    
    while(  (j + l) < m
         && (j - l) >=0
         && (i + u) < n
         && (i - u) >= 0
         && (grid[i][j + l] == 'G')
         && (grid[i][j - l] == 'G')
         && (grid[i + u][j] == 'G')
         && (grid[i - u][j] == 'G')    
    ){
        cout<< "I am here -------"<< i << j << endl;
        cout<< "I am here -------"<<grid[i][j]<< endl;
        l++; u++;
    }
    sum = 2 * (l + u) + 1;
    return sum ;
}

// Complete the twoPluses function below.
int twoPluses(vector<string> grid) {
    int n, m;
    int val, val2 , val1 ;
    n = grid.size();
    if(n == 0 ){
        return 0;
    }
    
    m = grid[0].length();
    
    cout<<"m --> "<<  m << "n ---> " << n<< endl;
    
    
    for(int i =0; i < m ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
         if(grid[i][j] == 'G')
         {
           // cout<< "I am here -------"<<grid[i][j]<< endl;
           int val =  runRobot(grid , i, j , n , m) ; 
            if(val >= val1)
                val1 = val;
             else if((val <val1) && (val >= val2))
             {
                 val2 = val;
             }
         }   
        }
    }
    
 
    return (val1 * val2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

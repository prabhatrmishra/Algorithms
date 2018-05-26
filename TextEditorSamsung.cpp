#include <iostream>
#include<vector>
#include<stdio.h>
using namespace std;


vector<string>txt;
int p,q;
vector<string>buff;

void ddee()
{
    cout<<"I am called"<<endl;
    if(txt.size()== 0)
    {
        p=0; q=0;
    }
    else {
             txt.erase(txt.begin()+p);
            // for(int i = 0; i < txt.size(); i++)
            //    cout<<txt[i]<<endl;
            for(int i = 0; i < txt.size(); i++)
               cout<<txt[i]<<endl;
             if(txt.size() == 0){
                p = 0; q= 0;
             }
             else if(p == (txt.size() - 1) )
             {
                p = txt.size(); q= txt[p].length();
             }
            else if (p != (txt.size()-1))
            {
                q = txt[p].length(); 
            }
    }
 //  cout<< txt.size() <<" "<< q<< endl;
    return;
}

void colon_m( int m)
{
    p = m-1;
    q= txt[p].length();
    // cout<< p <<" "<< q<< endl;
}

void yee()
{
    buff.empty();
    buff.push_back(txt[p]);
      // cout<< p <<" "<< q<< endl;
}
void peee()
{
    if(buff.size() == 0)
        return;
    else
    {
        txt.insert(txt.begin()+p, buff[0]);
       // p = p+1;
        q = txt[p].length();
        buff.empty();
    }
     // cout<< p <<" "<< q<< endl;
     return;
}
void dyee()
{
     if(txt.size()== 0)
        {
            p=0;q=0;
        }
    else{
             buff[0] = txt[p];
             txt.erase(txt.begin()+p);
             if(txt.size() == 0){
                p = 0; q= 0;
             }
             else if(p == txt.size() - 1 )
             {
                 p = txt.size(); q= txt[p].length();
             }
            else if (p != (txt.size()-1))
            {
                q = txt[p].length(); 
            }
    }
     // cout<< p <<" "<< q<< endl;
    return;
}

int main() {
    int N,q;
    p = 0; q= 0;
    cin>>N;
    while(N--)
    {
       string s;
       // cin>>s;
     getline(cin, s);
      while (s.length()==0 )
            getline(cin, s);
      // scanf(" %[^\n]s",s);
    txt.push_back(s);
    }
   // for(int i = 0; i < txt.size(); i++)
   //     cout<<txt[i]<<endl;
    cin>>q;
   
    while(q--)
    {
            string val;
            //cin>>val;
            getline(cin, val);
        while (val.length()==0 )
            getline(cin, val);
           cout<< val<<endl;
            if(val == "dd")
            {
                ddee();
            }
            else if(val[0] == ':')
            {
                
                int l = val.length() -1;
                int m = stoi(val.substr(1,l));
               // cout<<"I am called"<<m<<endl;    
                colon_m(m) ;
                //cout<<"I am called"<<p<<" , "<< q<<endl; 
               //  for(int i = 0; i < txt.size(); i++)
                //    cout<<txt[i]<<endl;
            }
            else if(val[0] == 'i')
            {
                int l = val.length() -2;
                int m = stoi(val.substr(2,l));
                string ls;
                //cin>>ls;
                //cout<<"I am called"<<m<<endl;
                 getline(cin, ls);
                  while (ls.length()==0 )
                     getline(cin, ls);
                if(p == 0)
                    txt.push_back(ls);
                else
                {
                    string tmp = txt[p];
                    tmp = tmp.append(ls);
                   // cout<<tmp<<" ########"<< endl;
                    txt[p] = tmp;
                }
                q = txt[p].length();
                m--;
                while(m--)
                {
                    //cin>>ls;
                    getline(cin, ls);
                     while (ls.length()==0 )
                        getline(cin, ls);
                    txt.push_back(ls);
                   
                }
                //  for(int i = 0; i < txt.size(); i++)
                 //        cout<<txt[i]<<endl;
            }
            else if(val[0] == 'y')
            {
                yee();
            }
            else if(val[0] == 'p')
            {
                peee();
            }
            else if(val == "dy")
            {
                dyee();
            }
    }
   // for(int i = 0; i < txt.size(); i++)
   //     cout<<txt[i]<<endl;
   
	return 0;
}

/*
 * Complete the function below.
 */
string find_phone_number(string text) {
regex e("[[:digit:]]{3}-[[:digit:]]{3}-[[:digit:]]{4}");
string s = text;
smatch m;
    string value ;
    while (regex_search (s,m,e)) {
    for (auto x:m){
        cout << x << " ";
        value = x;
        
    } 
   
   cout << std::endl;
    s = m.suffix().str();
  }
    if(value.length() == 0)
    {
        return "NONE";
    }
    else
    return value;
}

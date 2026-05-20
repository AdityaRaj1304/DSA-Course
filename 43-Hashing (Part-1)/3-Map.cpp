#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string,int>m;
    m["India"]=150;
    m["China"]=150;
    m["US"]=50;
    m["Nepal"]=20;

    for(auto it:m){
        cout << it.first << ": " << it.second << endl;
    }
    if(m.count("Nepal")){
        cout << "Nepal Exists\n";
    }else{
        cout << "Doesn't Exist";
    }
    cout << m.size() << endl;
    m.erase("Nepal");
    if(m.count("Nepal")){
        cout << "Nepal Exists";
    }else{
        cout << "Doesn't Exist";
    }
    return 0;
}
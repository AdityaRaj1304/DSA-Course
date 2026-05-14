#include<iostream>
#include<string>
using namespace std;
class User{
    public:
    int id ;
    string username , password , bio ;
    void deactivate(){
        cout << "Deactivating Account\n";
    }
    void updatebio(string newbio){
        bio = newbio;
    }
};
int main (){
    User x;
    x.username = "SouLAdityA";
    x.bio="Hello";
    cout << "Username : " << x.username << endl;
    cout << "Bio : " << x.bio << endl;
    x.updatebio("I am best");
    cout << "Username : " << x.username << endl;
    cout << "Bio : " << x.bio << endl;
    x.deactivate();
    return 0 ;
}
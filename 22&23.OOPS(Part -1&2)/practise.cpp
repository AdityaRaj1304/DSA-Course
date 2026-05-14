#include<iostream>
#include<string>
using namespace std;
class User{
    private:
    int id ;
    string pwd;
    public:
    string username;
    User(int id){
        this->id=id;
    }
    void setPassword(string pwd){
        this->pwd=pwd;
    }
    string getPassword(){
        return pwd;
    }
};
int main(){
    User s1(1);
    s1.username="Aditya";
    s1.setPassword("rajgupta");
    cout << "UserName : " << s1.username << endl;
    cout << "Password : " << s1.getPassword();
    return 0 ;
}
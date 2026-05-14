#include<iostream>
#include<string>
using namespace std;
class BankAccount {
    public:
    float account_number , balance;
    string name;
    BankAccount(){
        cout << "Enter Name : ";
        getline(cin,name);
        cout << "Enter Account Number : ";
        cin >> account_number;
        cout << "Enter Balance : ";
        cin >> balance;
    }
    void showDetails(){
        cout << "Name : " << name << endl;
        cout << "Account Number : " << account_number << endl;
        cout << "Balance : " << balance << endl;
    }
    void deposit(float amount){
        balance+= amount;
    }
    void withdraw(float amount){
        balance-=amount;
    }
    float getBalance(){
        return balance;
    }
};
int main(){
    BankAccount user1;
    user1.showDetails();
    user1.deposit(50000);
    user1.getBalance();
    user1.withdraw(30000);
    user1.getBalance();
}
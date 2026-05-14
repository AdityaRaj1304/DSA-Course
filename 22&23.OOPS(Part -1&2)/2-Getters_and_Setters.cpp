#include<iostream>
#include<string>
using namespace std;
class Student{
    public:
    string name;
    float cgpa;
    void getPercantage(){
        cout << "Percentage : " << cgpa * 10  << "%" << endl;
    }
    void setName(string nameVal){ // Setter
        name = nameVal;
    }
    string getName(){ //Setter
        return name;
    }
};
int main(){
    Student s1;
    s1.setName("Aditya Raj Gupta");
    s1.cgpa=9.27;
    cout << "Name : " << s1.getName() << endl;
    s1.getPercantage();
}
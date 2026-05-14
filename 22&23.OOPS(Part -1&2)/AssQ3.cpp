#include<iostream>
#include<string>
using namespace std;
class Person{
    public:
    string name ;
    int age;
    Person(string name , int age){
        this->name=name;
        this->age=age;
    }
};
class Student : public Person{
    public:
    string studentId ;
    Student(string name,int age ,string id): Person(name,age),studentId(id){
        cout << "Student Constructor Called" << endl;
    }
    void display_details(){
        cout << "Name : " << name<<endl;
        cout << "Age : " << age<< endl;
        cout << "Student ID : " << studentId<<endl;
    }
};
int main(){
    Student student("Alice", 20, "S12345");
    student.display_details();
    return 0 ;
}
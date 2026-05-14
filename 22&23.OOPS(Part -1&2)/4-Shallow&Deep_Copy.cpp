#include<iostream>
#include<string>
using namespace std;
class Car{
    public:
    string car_name , color;
    int *mileage;
    Car(string car_name , string color){
        cout << "Constructor is called\n";
        this->car_name=car_name;
        this->color=color;
        mileage=new int;
        *mileage=12;
    }
    Car(Car&original){//Deep Copy
        cout << "Copyying orignial to new";
        car_name=original.car_name;
        color=original.color;
        mileage=new int;
        *mileage=*original.mileage;
    }
};
int main(){
     return 0;
}
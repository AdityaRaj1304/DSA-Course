#include<iostream>
#include<string>
using namespace std;
class Car{
    public:
    string car_name , color;
    Car(string car_name , string color){
        cout << "Constructor is called\n";
        this->car_name=car_name;
        this->color=color;
    }
    void start(){
        cout << "Car has started\n";
    }
    void stop(){
        cout << "Car has stopped\n";
    }
    Car(Car & original){
        cout << "Copyying orignial to new";
        car_name=original.car_name;
        color=original.color;
    }
    ~Car(){
        cout << "Desturctor is called\n";
    }
};
int main (){
    Car c1("Audi A8","Red");
    c1.start();
    c1.stop();
    Car c2(c1); // Default Copy Constructor(If custom copy contructor not created)
    cout << c2.car_name << endl;
    cout << c2.color;
    return 0 ;
}
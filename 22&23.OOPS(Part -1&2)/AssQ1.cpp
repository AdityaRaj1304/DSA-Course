#include<iostream>
using namespace std;
class Complex {
    public:
    float real , img;
    Complex(int real , int img){
        this->real=real;
        this->img=img;
    }
    void print(){
        cout << "Number : " << real << " + " << img << "i" << endl;
    }
    Complex operator - (Complex &num){
        int res_real=this->real - num.real;
        int res_img=this->img - num.real;
        Complex c3(res_real,res_img);
        cout << "Difference : ";
        c3.print();
    }
};
int main(){
    Complex c1(7,2) , c2(8,1);
    c1.print();
    c2.print();
    c1-c2;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int rank;
    Student(string name , int rank){
        this->name=name;
        this->rank=rank;
    }

    bool operator < (const Student& obj) const{
        return this->rank > obj.rank;  // Max Heap(<) , Min Heap(>)
    }
};

int main(){
    priority_queue<Student>pq; //Min Heap
     
    pq.push(Student("Aditya",1));
    pq.push(Student("Pratham",2));
    pq.push(Student("Abhisekh",3));

    while(!pq.empty()){
        cout << pq.top().name << "," << pq.top().rank << endl; 
        pq.pop();
    }   
    return 0;
}
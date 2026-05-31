#include<bits/stdc++.h>
using namespace std;

class Heap{
    vector<int>vec;
    public:

    void push(int val){ //TC=O(log n)
        //Step 1: Insert Value
        vec.push_back(val);
        
        //Step-2: Fix Heap
        int x = vec.size()-1; //childIdx
        int parIdx = (x-1)/2; //parentIdx
        while(parIdx>=0 && vec[x]>vec[parIdx]){
            swap(vec[x],vec[parIdx]);
            x = parIdx;
            parIdx = (x-1)/2;
        }
    }

    void heapify(int i){//i=parIdx
        if(i>=vec.size()){
            return;
        }
        int lc = 2*i+1;
        int rc = 2*i+2;
        int maxIdx = i;
        if(lc<vec.size() && vec[lc]>vec[maxIdx]){
            maxIdx=lc;
        }
        if(rc<vec.size() && vec[rc]>vec[maxIdx]){
            maxIdx=rc;
        }
        swap(vec[i],vec[maxIdx]);
        if(i!=maxIdx){ // Swap with child node
            heapify(maxIdx);
        }
    }

    void pop(){ //TC=O(log n)
        //Step-1:Swap with last node
        swap(vec[0],vec[vec.size()-1]);
        //Step-2:Remove the last node
        vec.pop_back();
        //Step-3:Fix the Heap
        heapify(0);
    }

    int top(){//TC=O(1)
        return vec[0];
    }

    bool empty(){//TC=O(1)
        return vec.size()==0;
    }
};

int main(){
    Heap heap;
    heap.push(8);
    heap.push(4);
    heap.push(5);
    heap.push(1);
    heap.push(2);
    heap.push(9);
    
    while(!heap.empty()){
        cout << "Top Element: " << heap.top() << endl;
        heap.pop();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val){
        this->key=key;
        this->val=val;
        next=NULL;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

class HashTable{
    int totSize;
    int currSize;
    Node** table;

    int hashFunction(string key){
    int idx= 0;
    for(int i = 0 ;i<key.size();i++){
        idx=idx+(key[i]*key[i])%totSize;
    }
    return idx%totSize;
}

void rehash(){
    Node** oldTable = table;
    int oldSize = totSize;
    totSize=2*totSize;
    currSize=0;
    table = new Node*[totSize];

    for(int i = 0;i<totSize;i++){
        table[i]=NULL;
    }
    
    //copy old values
    for(int i = 0 ;i<oldSize;i++){
        Node* temp = oldTable[i];
        while(temp!=NULL){
            insert(temp->key,temp->val);
            temp=temp->next;
        }
        if(oldTable[i]!=NULL){
        delete oldTable[i];
    }
    }
    delete[] oldTable;
}

public:
    HashTable(int size=5){
        totSize=size;
        currSize=0;
        table = new Node*[totSize];

        for(int i = 0 ;i<totSize;i++){
            table[i]=NULL;
        }
    }

    void insert(string key,int val){//O(1)->Avg
        int idx = hashFunction(key);

        Node* newNode = new Node(key,val);
        
        newNode->next=table[idx];
        table[idx]=newNode;
        currSize++;

        double lambda = currSize/(double)totSize;
        if(lambda>1){
            rehash();//O(n)->Worst
        }
    }

    bool exists(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return true; //FOUND
            }
            temp=temp->next;
        }
        return false;
    }

    int search(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return temp->val;
            }
            temp=temp->next;
        }
        return -1;
    }

    void remove(string key){

    }

    void print(){
        for(int i = 0;i<totSize;i++){
            cout<<"idx" << i << "->";
            Node*temp = table[i]; 
            while(temp!=NULL){
                cout<<"(" << temp->key<<","<<temp->val<<") -> ";
                temp=temp->next;
            }
            cout << endl;
        }
    }

};


int main(){
    HashTable ht;
    ht.insert("India",150);
    ht.insert("China",150);
    ht.insert("US",50);
    ht.insert("Nepal",10);
    ht.insert("UK",20);

    ht.print();
    // if(ht.exists("UK")){
    //     cout << "UK Population: " << ht.search("UK");
    // }
    
    return 0;
}

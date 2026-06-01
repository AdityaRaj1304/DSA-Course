#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    unordered_map<char,Node*>children;
    bool endOfWord;

    Node(){
        endOfWord=false;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(char ch:word){
            if(temp->children.count(ch)==0){
                temp->children[ch]=new Node();
            }
            temp=temp->children[ch];
        }
        temp->endOfWord=true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(char ch:word){
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            }else{
                return false;
            }
        }
        return temp->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char ch:prefix){
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            }else{
                return false;
            }
        }
        return true;
    }
};
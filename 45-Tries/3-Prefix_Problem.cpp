#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    unordered_map<char,Node*>children;
    bool endOfWord;
    int freq ;

    Node(){
        endOfWord=false;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
        root->freq=-1;
    }

    void insert(string key){ //TC = O(L)
        Node* temp = root;
        for(char ch : key){
            if(temp->children.count(ch)==0){
                temp->children[ch]=new Node();//insert
                temp->children[ch]->freq=1;
            }else{
                temp->children[ch]->freq++;
            }
            temp = temp->children[ch];//level update
        }
        temp->endOfWord=true;//end of key
    }

    bool search(string key){
        Node* temp = root;
        for(char ch: key){
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            }else{
                return false;
            }
        }
        return temp->endOfWord;
    }

    string getPrefix(string key){
        Node* temp = root;
        string prefix ="";
        for(char ch:key){
            prefix+=ch;
            if(temp->children[ch]->freq==1){
            return prefix;
            }
            temp=temp->children[ch];
        }
        return prefix;
    }
};

    void prefixProblem(vector<string>words){
        Trie trie;
        for(string s:words){
            trie.insert(s);
        }

        for(string s:words){
            cout << trie.getPrefix(s) << endl; 
        }
    }


int main(){
    vector<string>words={"zebra","dog","duck","dove"};
    prefixProblem(words);
    return 0;
}
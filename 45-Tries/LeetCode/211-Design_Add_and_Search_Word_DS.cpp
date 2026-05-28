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

class Trie{
public:
    Node* root;

    Trie(){
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

    bool helper(string &word,int idx , Node* node){
        if(idx == word.size()){
            return node->endOfWord;
        }
        char ch = word[idx];
        if(ch!='.'){
            if(node->children.count(ch)){
                return helper(word,idx+1,node->children[ch]);
            }else{
                return false;
            }
        }else{
            for(auto &it:node->children){
                if(helper(word,idx+1,it.second)){
                    return true;
                }
            }
            return false;
        }
    }
    bool search(string word){
        return helper(word,0,root);
    }
};


class WordDictionary {
    Trie t;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        t.insert(word);
    }
    
    bool search(string word) {
        return t.search(word);
    }
};
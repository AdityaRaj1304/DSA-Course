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
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string key){ //TC = O(L)
        Node* temp = root;
        for(char ch : key){
            if(temp->children.count(ch)==0){
                temp->children[ch]=new Node();//insert
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
};


class Solution {
    unordered_map<string,bool>result;
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        for(string s:wordDict){
            t.insert(s);
        }
        return helper(t,s);
    }
    
    bool helper(Trie& t, string key){
        if(key.size()==0){
            return true;
        }
        if(result.count(key)){
            return result[key];
        }

        for(int i = 0;i<key.size();i++){
            string first = key.substr(0,i+1);
            string second = key.substr(i+1);

            if(t.search(first) && helper(t,second)){
                return result[key]=true;
            }
        }
        return result[key]=false;
    }
};
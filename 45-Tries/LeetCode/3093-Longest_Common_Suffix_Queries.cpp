#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    unordered_map<char,Node*>children;
    int idx;
    int length;

    Node(){
        idx=-1;
        length=INT_MAX;
    }
};

class Trie{
public:
    Node* root ;
    Trie(){
        root = new Node();
    }  

    void update(Node* node , int idx , int length){
        if(length<node->length){
            node->length = length;
            node->idx=idx;
        }
    }


    void insert(string key, int idx){
        reverse(key.begin(),key.end());
        Node* temp =root;
        update(temp,idx,key.size());
        for(char ch:key){
            if(temp->children.count(ch)==0){
                temp->children[ch]=new Node();
            }
            temp=temp->children[ch];
            update(temp,idx,key.size());
        }
    }

    int search(string key){
        reverse(key.begin(),key.end());
        Node* temp = root;
        for(char ch:key){
            if(!temp->children.count(ch)){
                break;
            }
            temp=temp->children[ch];
        }
        return temp->idx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int>ans;
        Trie t;
        for(int i = 0 ;i<wordsContainer.size();i++){
            t.insert(wordsContainer[i],i);
        }
        for(string s:wordsQuery){
            ans.push_back(t.search(s));
        }
        return ans;
    }
};









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
    Node* root ;
    Trie(){
        root = new Node();
    }  

    void insert(string key){
        Node* temp =root;
        for(char ch:key){
            if(temp->children.count(ch)==0){
                temp->children[ch]=new Node();
            }
            temp=temp->children[ch];
        }
        temp->endOfWord= true;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans =strs[0];
        Trie t;
        t.insert(strs[0]);
        for(int i =1 ;i<strs.size();i++){
            if(ans.empty()){
                return ans;
            }
            int length = 0;
            Node* temp = t.root;
            for(char ch:strs[i]){
                if(temp->children.count(ch)){
                    temp=temp->children[ch];
                    length++;
                }else{
                    break;
                }
            }
            ans=ans.substr(0,length);
        }
        return ans;
    }
};
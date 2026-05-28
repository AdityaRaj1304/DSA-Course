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
    unordered_map<int,vector<string>>result;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        for(string s:wordDict){
            t.insert(s);
        }
        return helper(t,s,0);
    }

    vector<string> helper(Trie& t, string& key , int idx){
        if(result.count(idx)){
            return result[idx];
        }
        vector<string>ans ;
        if(idx==key.size()){
            ans.push_back("");
            return ans;
        }

        Node* temp = t.root;
        string word ="";

        for(int i = idx;i<key.size();i++){
            char ch = key[i];
            if(!temp->children.count(ch)){
                break;
            }
            temp=temp->children[ch];
            word.push_back(ch);

            if(temp->endOfWord){
                vector<string>suffixes = helper(t,key,i+1);
                for(string suffix : suffixes){
                    if(suffix == ""){
                        ans.push_back(word);
                    }else{
                    ans.push_back(word + " " + suffix);
                    }
                }
            }
        }
        return result[idx]=ans;
    }
};
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

    void longestHelper(Node* root , string&ans , string temp){
        for(auto child : root->children){
            if(child.second->endOfWord){
                temp+=child.first;
                if((temp.size()==ans.size() && temp<ans) || (temp.size()>ans.size())){
                    ans = temp;
                }
                longestHelper(child.second,ans,temp);
                temp = temp.substr(0,temp.size()-1);
            }
        }
    }
    string longestStringwithEOW(){
        string ans = "";
        longestHelper(root,ans,"");
        return ans;
    }
};


class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie t;
        for(string s:words){
            t.insert(s);
        }
        return t.longestStringwithEOW();
    }
};
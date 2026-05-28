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

    int countHelper(Node* root){
        int ans = 0;
        for(auto it:root->children){
            ans+=countHelper(it.second);
        }
        return ans+1;
    }

    int countNodes(){
        return countHelper(root);
    }
};

int countUniqueSubstr(string str){
    Trie trie;
    for(int i = 0;i<str.size();i++){
        string suffix = str.substr(i);
        trie.insert(suffix);
    }
    return trie.countNodes();

}

int main(){
    string s = "ababa";
    cout << countUniqueSubstr(s);
    return 0;
}
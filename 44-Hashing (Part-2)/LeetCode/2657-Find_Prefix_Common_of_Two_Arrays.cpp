#include<bits/stdc++.h>
using namespace std;


//Two Hash Map
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n =A.size();
        unordered_map<int,int>freq1,freq2;
        vector<int>ans(n,0);
        int count = 0;
        for(int i = 0;i<n;i++){
            freq1[A[i]]=1,freq2[B[i]]=1;
            if(A[i]==B[i]){
                count++;
                ans[i]=count;
            }else if(freq1.count(B[i])&&freq2.count(A[i])){
                count+=2;
                ans[i]=count;
            }else if(freq1.count(B[i])&&!freq2.count(A[i])){
                count++;
                ans[i]=count;
            }else if(!freq1.count(B[i])&&freq2.count(A[i])){
                count++;
                ans[i]=count;
            }else{
                ans[i]=count;
            }
        }
        return ans;
    }
};

//Optimal - Single Freq Array
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n,0);
        vector<int>freq(n+1,0);
        int count = 0;
        for(int i = 0;i<n;i++){
            freq[A[i]]++;
            if(freq[A[i]]==2){
                count++;
            }
            freq[B[i]]++;
            if(freq[B[i]]==2){
                count++;
            }
            ans[i]=count;
        }
        return ans;
    }
};
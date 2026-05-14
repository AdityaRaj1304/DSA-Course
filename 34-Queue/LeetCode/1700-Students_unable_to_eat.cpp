#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int>st;
        stack<int>sw;
        for(int i = 0 ;i<n;i++){
            st.push(students[i]);
        }
        for(int i = n-1 ;i>=0;i--){
            sw.push(sandwiches[i]);
        }
        int served =0 ;
        while(!st.empty() && served < st.size()){
            if(st.front()==sw.top()){
                st.pop();
                sw.pop();
                served=0;
            }else{
                st.push(st.front());
                st.pop();
                served++;
            }
        }
        return st.size();
    }
};
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// class Solution {  // Wrong for Test Cases
// public:
//     int scheduleCourse(vector<vector<int>>& courses) { 
//         sort(courses.begin(),courses.end(),[&](auto a ,auto b){
//             if(a[1]==b[1]){
//                 return a[0]<b[0];
//             }
//             return a[1]<b[1];
//         });
//         int ans =0;
//         int time =0;
//         for(auto course:courses){
//             time+=course[0];
//             if(time>course[1]){
//                 return ans;
//             }
//             ans++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[&](auto a ,auto b){
            return a[1]<b[1];
        });
        priority_queue<int>pq;
        int time =0;
        for(auto course:courses){
            time+=course[0];
            pq.push(course[0]);
            if(time>course[1]){
                time-=pq.top();
                pq.pop();
            }
        }
        int ans = pq.size();
        return ans;
    }
};

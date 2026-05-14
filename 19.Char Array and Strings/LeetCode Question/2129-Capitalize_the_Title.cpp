#include<iostream>
#include<string>
#include<vector>
using namespace std ;
class Solution {
public:
    string capitalizeTitle(string title) {
        int count = 0;
        int n = title.length();

        for (int i = 0; i <= n; i++) {
            if (i == n || title[i] == ' ') {
                int j = i - 1;
                count = 0;

                while (j >= 0 && title[j] != ' ') {
                    count++;
                    j--;
                }

                if (count == 1) {
                    if (title[j + 1] >= 'A' && title[j + 1] <= 'Z') {
                        title[j + 1] = title[j + 1] - 'A' + 'a';
                    }
                }

                else if (count == 2) {
                    if (title[j + 1] >= 'A' && title[j + 1] <= 'Z') {
                        title[j + 1] = title[j + 1] - 'A' + 'a';
                    }
                    if (title[j + 2] >= 'A' && title[j + 2] <= 'Z') {
                        title[j + 2] = title[j + 2] - 'A' + 'a';
                    }
                }
                else if (count > 2) {
                    if (title[j + 1] >= 'a' && title[j + 1] <= 'z') {
                        title[j + 1] = title[j + 1] - 'a' + 'A';
                    }
                    for (int k = j + 2; k < i; k++) {
                        if (title[k] >= 'A' && title[k] <= 'Z') {
                            title[k] = title[k] - 'A' + 'a';
                        }
                    }
                }
            }
        }
        cout << title ;
        return title;
    }
};
int main (){
    Solution x ;
    string s ;
    cout << "Enter String : ";
    getline(cin,s);
    x.capitalizeTitle(s);
    return 0 ;
}
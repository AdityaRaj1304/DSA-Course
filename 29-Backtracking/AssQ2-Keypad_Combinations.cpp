#include<bits/stdc++.h>
using namespace std;

// Method - 1 (My implementation)
void helper(int pos, string &digits, string &str,vector<string> &ans,vector<vector<char>> &comb) {

    // Base case: one full combination formed
    if (pos == digits.length()) {
        ans.push_back(str);
        cout << str << endl;
        return;
    }

    int idx = digits[pos] - '2';

    for (int j = 0 ; j<comb[idx].size();j++) {
        str.push_back(comb[idx][j]);           // choose
        helper(pos + 1, digits, str, ans, comb); // explore
        str.pop_back();              // backtrack
    }
}

vector<string> keypad_comb(string digits) {
    vector<string> ans;
    if (digits.length()==0) {
        return ans;
    }
    vector<vector<char>> comb = {
        {'a','b','c'}, {'d','e','f'}, {'g','h','i'},
        {'j','k','l'}, {'m','n','o'},
        {'p','q','r','s'}, {'t','u','v'},
        {'w','x','y','z'}
    };

    string str = "";
    helper(0, digits, str, ans, comb);
    return ans;
}

// Method -2 (Class Solution)


int main() {
    string digits = "23";
    keypad_comb(digits);
    return 0;
}

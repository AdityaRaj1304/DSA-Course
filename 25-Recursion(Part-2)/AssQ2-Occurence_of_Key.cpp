#include <iostream>
#include <vector>
using namespace std;

vector<int> occurence(vector<int>& arr, int i, int key) {
    if (i == arr.size()) {
        return {};
    }
    vector<int> ans = occurence(arr, i + 1, key);
    if (arr[i] == key) {
        ans.insert(ans.begin(), i);
    }
    return ans;
}

int main() {
    vector<int> arr = {3, 2, 4, 5, 6, 2, 7, 2, 2};
    int key = 2;

    vector<int> result = occurence(arr, 0, key);

    for (int idx : result) {
        cout << idx << " ";
    }
    return 0;
}

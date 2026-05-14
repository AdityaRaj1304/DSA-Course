#include <bits/stdc++.h>
using namespace std;

// Method-1 

// bool path(int n, int r, int c, int mov,    // Not  the optimised way to solve this problem
//           vector<vector<bool>>& vis,
//           vector<vector<int>>& ans) {

//     // Base case: all squares are filled
//     if (mov == n * n) {
//         return true;
//     }

//     // Move 1: (-2, +1)
//     if (r - 2 >= 0 && c + 1 < n && !vis[r - 2][c + 1]) {
//         vis[r - 2][c + 1] = true;
//         ans[r - 2][c + 1] = mov + 1;
//         if (path(n, r - 2, c + 1, mov + 1, vis, ans))
//             return true;
//         vis[r - 2][c + 1] = false;
//         ans[r - 2][c + 1] = 0;
//     }

//     // Move 2: (-1, +2)
//     if (r - 1 >= 0 && c + 2 < n && !vis[r - 1][c + 2]) {
//         vis[r - 1][c + 2] = true;
//         ans[r - 1][c + 2] = mov + 1;
//         if (path(n, r - 1, c + 2, mov + 1, vis, ans))
//             return true;
//         vis[r - 1][c + 2] = false;
//         ans[r - 1][c + 2] = 0;
//     }

//     // Move 3: (+1, +2)
//     if (r + 1 < n && c + 2 < n && !vis[r + 1][c + 2]) {
//         vis[r + 1][c + 2] = true;
//         ans[r + 1][c + 2] = mov + 1;
//         if (path(n, r + 1, c + 2, mov + 1, vis, ans))
//             return true;
//         vis[r + 1][c + 2] = false;
//         ans[r + 1][c + 2] = 0;
//     }

//     // Move 4: (+2, +1)
//     if (r + 2 < n && c + 1 < n && !vis[r + 2][c + 1]) {
//         vis[r + 2][c + 1] = true;
//         ans[r + 2][c + 1] = mov + 1;
//         if (path(n, r + 2, c + 1, mov + 1, vis, ans))
//             return true;
//         vis[r + 2][c + 1] = false;
//         ans[r + 2][c + 1] = 0;
//     }

//     // Move 5: (+2, -1)
//     if (r + 2 < n && c - 1 >= 0 && !vis[r + 2][c - 1]) {
//         vis[r + 2][c - 1] = true;
//         ans[r + 2][c - 1] = mov + 1;
//         if (path(n, r + 2, c - 1, mov + 1, vis, ans))
//             return true;
//         vis[r + 2][c - 1] = false;
//         ans[r + 2][c - 1] = 0;
//     }

//     // Move 6: (+1, -2)
//     if (r + 1 < n && c - 2 >= 0 && !vis[r + 1][c - 2]) {
//         vis[r + 1][c - 2] = true;
//         ans[r + 1][c - 2] = mov + 1;
//         if (path(n, r + 1, c - 2, mov + 1, vis, ans))
//             return true;
//         vis[r + 1][c - 2] = false;
//         ans[r + 1][c - 2] = 0;
//     }

//     // Move 7: (-1, -2)
//     if (r - 1 >= 0 && c - 2 >= 0 && !vis[r - 1][c - 2]) {
//         vis[r - 1][c - 2] = true;
//         ans[r - 1][c - 2] = mov + 1;
//         if (path(n, r - 1, c - 2, mov + 1, vis, ans))
//             return true;
//         vis[r - 1][c - 2] = false;
//         ans[r - 1][c - 2] = 0;
//     }

//     // Move 8: (-2, -1)
//     if (r - 2 >= 0 && c - 1 >= 0 && !vis[r - 2][c - 1]) {
//         vis[r - 2][c - 1] = true;
//         ans[r - 2][c - 1] = mov + 1;
//         if (path(n, r - 2, c - 1, mov + 1, vis, ans))
//             return true;
//         vis[r - 2][c - 1] = false;
//         ans[r - 2][c - 1] = 0;
//     }

//     return false;
// }

// vector<vector<int>> knightTour(int n) {
//     vector<vector<int>> ans(n, vector<int>(n, 0));
//     vector<vector<bool>> vis(n, vector<bool>(n, false));
//     vis[0][0] = true;
//     ans[0][0] = 1;
//     path(n, 0, 0, 1, vis, ans);
//     return ans;
// }


// Method-2 


int main() {
    int n = 8;
    // vector<vector<int>> board = knightTour(n);

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << setw(2) << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}

#include<iostream>
using namespace std;
int main(){
 int row = 2, column = 3;
 int matrix[][3] = { {2, 3, 7}, {5, 6, 7} };
 int matrix2[3][3]={{1,2,3},{4,5,6},{7,8,9}};
 int transpose[3][2]={{0}};
 for(int i = 0 ; i < row ; i++){ // S.C.=O(n)
    for(int j = 0 ; j < column;j++){
        transpose[j][i]= matrix[i][j];
    }
 }
 for(int i = 0 ; i < column ;i++){
    for(int j = 0 ; j < row ; j++){
        cout << transpose[i][j] << " ";
    }
    cout << endl;
 }
 cout << endl;
 // Works only for Square Matrices O(1)
 int n = 3;
 for(int i = 0 ; i < n; i++){
    for(int j = i+1 ; j < n;j++){
        swap(matrix2[i][j],matrix2[j][i]);
    }
 }
 for(int i = 0 ; i < n;i++){
    for(int j = 0 ; j < n; j++){
        cout << matrix2[i][j] << " ";
    }
    cout << endl;
 }
}

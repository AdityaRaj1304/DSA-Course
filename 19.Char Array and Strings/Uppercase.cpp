#include<iostream>
#include<cstring>
using namespace std;

void toUpper(char arr[], int size) {
    for(int i = 0; i < size; i++) {
        char ch = arr[i];
        if(ch >= 'a' && ch <= 'z') {
            arr[i] = ch - 'a' + 'A';
        }
        cout << arr[i];
    }
    cout << endl;
}
void toLower(char *arr , int n ){
    for(int i =  0 ; i < n ; i++){
        if(arr[i]>='A'&&arr[i]<='Z'){
            arr[i]=arr[i]-'A'+'a';
        }
        cout << arr[i];
    }
}

int main() {
    char word[] = "SometHing";
    toUpper(word, strlen(word)) ;
    toLower(word,strlen(word));
    return 0;
}

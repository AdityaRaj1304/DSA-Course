
int main(){
    queue<int>q;
    for(int i = 1 ; i<=10;i++){
        q.push(i);
    }
    interleave(q);
    for(int i = 0 ; i<q.size();i++){
        cout << q.front() << " " ;
    }
    return 0;
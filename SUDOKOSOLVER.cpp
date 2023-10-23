#include<iostream>
#include<climits>
using namespace std;

bool sudoko(int ** a, int x, int y) {
    if(x == 9 ) {
        return true;
    }
    if(y == 9) {
        return sudoko(a, x + 1, 0);
    }
    if(a[x][y] != 0) {
        return sudoko(a, x, y + 1);
    }
    bool *visited = new bool[10];
    for(int i = 0; i< 10; i++) {
        visited[i] = false;
    }
    for(int i = 0; i < 9; i++) {
        if(a[x][i] != 0) {
            visited[a[x][i]] = true;
        }
        if(a[i][y] != 0) {
            visited[a[i][y]] = true;
        }
    }
    int c = x % 3;
    int b = y % 3;

    for(int i = x - c; i < x - c + 3; i++) {
        for(int j = y - b ; j< y -b +3; j++) {
            if(a[i][j] != 0) {
                visited[a[i][j]] = true;
            }
        }
    }
    bool check = false;
    for(int i = 1; i < 10; i++) {
        if (!visited[i]) {
            a[x][y] = i;
            check = sudoko(a, x, y + 1);
            if (check) {
                break;
            }
            a[x][y] = 0;
        }

    }
    return check;
}

int main(){

    // write your code here
    int** a = new int*[9];
    for(int i = 0; i< 9; i++) {
        a[i] = new int[9];
        for(int j = 0; j< 9; j++) {
            cin>>a[i][j];
        }
    }
    cout<<(sudoko(a,0,0) ? ("true it can be solved and the answer is\n") : ("false, it can not be solved"));
    for(int i = 0; i ,9; i++) {
        for(int j = 0; j < 9; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

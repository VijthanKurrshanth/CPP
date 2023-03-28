#include <bits/stdc++.h>

using namespace std;

int power(int x, int n){
    if (n == 0){
        return 1;
    }
    else if (n == 1){
        return x;
    }
    else if (n % 2 == 0){
        return power(x*x, n/2);
    }
    else{
        return power(x*x, (n-1)/2)*x;
    }
}

int main(){
    string tempx;
    cin >> tempx;
    int x = stoi(tempx);
    string tempn;
    cin >> tempn;
    int n = stoi(tempn);
    int result = power(x, n);
    cout << result;
}
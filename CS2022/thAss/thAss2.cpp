#include <bits/stdc++.h>

using namespace std;

int Factorial(int n){
    if (n == 0)
        return 1;
    else
        return n*Factorial(n-1);
}

int Search(int x, vector<int> arr, int len){
    if (arr[len-1] == x)
        return len-1;
    else
        return Search(x, arr, len-1);
}

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int isPalindrome(int beg, string str, int end){
    if (beg >= end){
        return 1;
    }
    else if (str[beg-1] == str[end-1])
        if (isPalindrome(beg+1, str, end-1)){
            return 1;
        }
        else {
            return 0;
        }

    else {
        return 0;
    }
}

int main(){
    /*FACTORIAL*/ 
    string temp_n;
    cin >> temp_n;
    int n = stoi(temp_n);
    cout << Factorial(n);

    /*SEARCH*/
    //  vector<int> arr = {1,2,3,4,5,6,7,8};
    //  int len = arr.size();
    //  int x = 8;
    //  cout << Search(x, arr, len);

    /*PALINDROME*/
    // string str;
    // cin >> str;
    // removeSpaces(str);
    // int beg = 1; int end = str.size();
    // int result = isPalindrome(beg, str, end);
    // cout << result;
    return 0;

}
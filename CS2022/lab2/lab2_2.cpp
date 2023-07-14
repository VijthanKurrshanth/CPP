#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <string_view>
#include <numeric>
#include <iterator>

using namespace std;

int hourglassSum (vector<vector<int>> arr){
    int j = 0, i = 0, k = 0, l = 0, sum = 0;

    int sums[16]; 
    for (j = 0; j < 4; j++ ){
        for (i = 0; i < 4; i++){
            vector<int> row = {i, i+1, i+2, i+1, i, i+1, i+2};
            vector<int> column = {j, j, j, j+1, j, j, j};
            for (k = 0; k < 8; k++){
                sum += arr[row[k]][column[k]];
            }
            sums[l] = sum;
            l++;
        }
    }
    int max = sums[0];
    for (int m = 0; m < 14; m++){
        if (sums[m] < sums[m+1]){
            max = sums[m+1];
        }
    }
    return max;
}

int main(){
    int arr[6][6] = {{1,1,1,1,1,1},{0,0,0,0,0,0},{1,1,1,1,1,1},{0,0,0,0,0,0},{1,1,1,1,1,1},{0,0,0,0,0,0}};
}
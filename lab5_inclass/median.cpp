#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

void insertion_sort(vector<int>& arr){
    int n = arr.size();
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void median(vector<int>& arr){
    int n = arr.size();
    for (int i = 0; i < n; i++){
        vector<int> sorted(arr.begin(), arr.begin()+i+1);
        insertion_sort(sorted);
        cout << "Sorted" << endl;
        for (int j = 0; j < i+1; j++) {
            cout << sorted[j] << " ";
        }
        cout << endl;
        cout << "Median" << endl; float mid;
        if (i == 0){
             mid = sorted[i];
        }
        else if (sorted.size() % 2 == 0){
            int up = (i+1)/2.0 + 0.5;
            int down = (i+1)/2.0 - 0.5;
            mid = (sorted[up] + sorted[down])/2.0;
        }
        else{
            mid = sorted[i/2];
        }
        float result = mid;
        cout << fixed << setprecision(1) << result << endl;
        cout << endl;
     

    }
}

int main() {
    int len;
    cout << "Enter the size of the array: ";
    cin >> len;

    vector<int> arr;
    cout << "Enter " << len << " integers: ";
    for (int i = 0; i < len; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << "The array you entered is: ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    median(arr);

    return 0;
}
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void rec_quicksort(vector<int>& arr, int len){
    if (len == 0){
        return;
    }
    int pivot = arr[len-1];
    int i = -1;
    for (int j = 0; j < len-1; j++){
        if (pivot > arr[j]){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = pivot;
    arr[len-1] = temp;
    vector<int> left(arr.begin(), arr.begin() + i);
    vector<int> right(arr.begin() + i + 1, arr.end());
    rec_quicksort(left, i);
    for (int k = 0; k < i; k++){
        arr[k]=left[k];
    }
    rec_quicksort(right, len - i - 1);
    for (int k = 0; k < len-i-1; k++){
        arr[k+i+1]=right[k];
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

    rec_quicksort(arr, len);

    cout << "The sorted is: ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
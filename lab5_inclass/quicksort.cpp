#include <iostream>
#include <vector>
#include <ctime>
#include <stack>

using namespace std;

void rec_quicksort(vector<int>& arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;
    rec_quicksort(arr, start, i - 1);
    rec_quicksort(arr, i + 1, end);
}


void nonrec_quicksort(vector<int>& arr, int len){
    if (len <= 1){
        return;
    }
    stack<int> s;
    s.push(0);
    s.push(len - 1);
    while (!s.empty()){
        int end = s.top();
        s.pop();
        int start = s.top();
        s.pop();
        int pivot = arr[end];
        int i = start - 1;
        for (int j = start; j <= end - 1; j++){
            if (arr[j] < pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[end]);
        int p = i + 1;
        if (p - 1 > start){
            s.push(start);
            s.push(p - 1);
        }
        if (p + 1 < end){
            s.push(p + 1);
            s.push(end);
        }
    }
}





int main() {
    double timetakenRecursive, timetakenIterative;
    clock_t start;
    clock_t stop;
    int n = 500000;
    for (int j = 0; j < 10; j++){
        vector<int> arr(n, 0);
        for(int i=0; i < n; i++){
            arr[i] =  500 + (rand() % 15000);
        }

        vector<int> arr1;
        arr1 = arr;

        start = clock();
        rec_quicksort(arr, 0, n - 1);
        stop = clock();
        timetakenRecursive = (stop - start) / (double)CLOCKS_PER_SEC;
        cout << "number of items: " << n << endl;
        cout << "Time taken by Recursive: "
        << timetakenRecursive << " seconds" << endl << endl;

        start = clock();
        nonrec_quicksort(arr1, n);
        stop = clock();
        timetakenIterative = (stop - start) / (double)CLOCKS_PER_SEC;
        cout << "number of items: " << n << endl;
        cout << "Time taken by Iterative: "
        << timetakenIterative << " seconds" << endl << endl;

        n = n + 500000;
    }
    return 0;
}

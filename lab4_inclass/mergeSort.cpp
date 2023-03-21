#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void merge(vector<int>& arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = start + (end - start) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void iterative_merge_sort(vector<int>& arr) {
    int n = arr.size();
    int curr_size;
    int left_start;

    for (curr_size = 1; curr_size < n; curr_size *= 2) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);
            merge(arr, left_start, mid, right_end);
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
        merge_sort(arr, 0, n - 1);
        stop = clock();
        timetakenRecursive = (stop - start) / (double)CLOCKS_PER_SEC;
        cout << "number of items: " << n << endl;
        cout << "Time taken by Recursive: "
        << timetakenRecursive << " seconds" << endl << endl;

        start = clock();
        iterative_merge_sort(arr1);
        stop = clock();
        timetakenIterative = (stop - start) / (double)CLOCKS_PER_SEC;
        cout << "number of items: " << n << endl;
        cout << "Time taken by Iterative: "
        << timetakenIterative << " seconds" << endl << endl;

        // if (n == 5000){
        //     for (int i = 0; i < n; i++) {
        //         cout << arr[i] << " ";
        //     }
        //     cout << endl;
        // }
        n = n + 500000;
    }
    return 0;
}

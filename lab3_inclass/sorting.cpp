
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// insertion sort
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// bubble sort
void bubbleSort(int array[], int size) {
    int swapped;
    do{
        swapped = 0;
        for (int i = 0; i < size-1; i++) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

// optimized bubble sort
void bubbleSortOpti(int array[], int size) {
    int swapped;
    for (int i = size-1; i >= 0; i--){
        swapped = 0;
        for (int j = 0; j < i+1; j++){
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped){
            break;
        }
    }
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    int temp = array[min_idx]; 
    array[min_idx] = array[step];
    array[step] = temp;
  }
}


// A utility function to print an array
// of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
	cout << endl;
    cout << endl;

}

// Driver code
int main()
{
    
    int sz = 5000;
    for (int j = 0; j < 5; j++){
        int randArray[sz];
        for(int i=0; i < sz; i++){
            randArray[i] =  500 + (rand() % 15000); //Generate number between 500 to 20000
        }
        //printArray(randArray, sz);
        auto start = high_resolution_clock::now();
        selectionSort(randArray, sz);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "number of items: " << sz << endl;
        cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl << endl;
        //if (sz == 5000)
        //printArray(randArray, sz);
        sz = sz + 5000;
    }
    return 0;
}
// This is code is contributed by rathbhupendra

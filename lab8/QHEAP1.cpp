#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void heapify(vector <long>* arr, int root){
    auto n = arr->size();
    int l = root*2 + 1; int r = root*2 + 2;
    int smallest;
    if (l < n && arr->at(l) < arr->at(root)){
        smallest = l;
    }
    else {
        smallest = root;
    }
    if (r < n && arr->at(r) < arr->at(smallest)){
        smallest = r;
    }
    if (smallest != root){
        int temp;
        temp = arr->at(root);
        arr->at(root) = arr->at(smallest);
        arr->at(smallest) = temp;
        heapify(arr, smallest);
    }
   
}

void buildheap(vector <long>* arr, int n)
{
   for (int i = (n-3)/2; i >= 0; i--){
      heapify(arr, i);
   }
}   

int delete_heap(vector <long>* arr, int num){
    auto n = arr->size();
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr->at(i) == num) {
            index = i;
            break;
        }
    }
    
    arr->at(index) = arr->at(n-1);
    arr->pop_back();
    for (int i = index; i >= 0; i--){
        heapify(arr, index);
    }
    int size = static_cast<int>(arr->size());
    return size;
}

int main() {
    int q;
    cin >> q;
    vector <long> heap1;
    vector <long>* heap = &heap1;
    int len = 0;
    string type;
    getline (cin, type);
    for (int i = 0; i < q; i++){
        getline (cin, type);
        if ((int(type[0]) - 48) == 1){

            if (len == 0){
                char* in = &type[2];
                long ins_value = atoi(in);
                heap->push_back(ins_value);
                len += 1;
            }

            else {
                char* in = &type[2];
                long ins_value = atoi(in);
                heap->push_back(ins_value);
                len += 1;

                int child = len-1;
                int parent;
                if ((child)%2 ==0){
                    parent = ((child) -2)/2;
                }
                else {
                    parent = ((child) -1)/2;
                }

                while(heap->at(parent) > heap->at(child)){
                    heapify(heap, parent);
                    child = parent;
                    if (child ==0 && child != 0){
                        parent = (child -2)/2;
                    }
                    else if (child != 0){
                        parent = (child -1)/2;
                    }
                }
            }
        }

        else if ((int(type[0]) - 48) == 2){
            char* in = &type[2];
            long ins_value = atoi(in);
            len = delete_heap(heap, ins_value);
        }

        else if ((int(type[0]) - 48) == 3){
            cout << heap->at(0) << endl;
        }
    }
    return 0;
}

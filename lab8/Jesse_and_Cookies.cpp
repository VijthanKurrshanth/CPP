#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void heapify(vector <int>* arr, int root){
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


void buildheap(vector <int>* arr)
{
    auto n = arr->size();
    for (int i = (n-3)/2; i >= 0; i--){
        heapify(arr, i);
    }
}   

/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */

int cookies(int k, vector<int> A) {
    vector<int>* ptr_A = &A;
    int result = 0;
    auto n = ptr_A->size();

    buildheap(ptr_A);
    while (ptr_A->at(0) < k && n > 1){
        
        int least1 = ptr_A->at(0);
        int least2;
        if (n == 2){
            least2 = ptr_A->at(1);
        }
        else{

            if (ptr_A->at(1) < ptr_A->at(2)){
                least2 = ptr_A->at(1);
                ptr_A->at(1) = ptr_A->at(n-1);
            }
            else {
                least2 = ptr_A->at(2);
                ptr_A->at(2) = ptr_A->at(n-1);
            }
        }
        ptr_A->at(0) = least1 + 2*least2;
        ptr_A->pop_back();
        n -= 1;
        buildheap(ptr_A);
        result += 1;
        }
    if (!(n > 1)){
        return -1;
    }
    else {
        return result;
    }
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    int result = cookies(k, A);

    fout << result << "\n";
    cout << result;

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

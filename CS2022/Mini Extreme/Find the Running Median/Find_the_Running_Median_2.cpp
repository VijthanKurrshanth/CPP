#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

void insertElement(vector<int>& arr, int& size, int newElement) {
    // Find the position to insert the new element
    arr.push_back(0);
    int i = size - 1;
    while (i >= 0 && arr[i] > newElement) {
        arr[i + 1] = arr[i];
        i--;
    }

    // Insert the new element at the correct position
    arr[i + 1] = newElement;
}

vector<double> runningMedian(vector<int> a) {
    vector<int> sorted_a;
    vector<double> medians;
    int len_a = a.size();
    for (int i = 0; i < len_a; i++){
        if (i == 0){
            sorted_a.push_back(a[i]);
            medians.push_back(a[i]);
        }
        else{
            insertElement(sorted_a, i, a[i]);
            if (i%2 == 1){
                double median = (sorted_a[(i-1)/2] + sorted_a[(i-1)/2 + 1])/2.0;
                medians.push_back(median);
            }
            else{
                double median = sorted_a[i/2];
                medians.push_back(median);
            }
        }

    }
    return medians;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << setprecision (1) << fixed << result[i];
        cout << setprecision (1) << fixed << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
            cout << "\n";
        }
    }

    fout << "\n";
    cout << "\n";

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

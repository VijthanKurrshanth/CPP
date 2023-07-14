#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(vector<int> arr) {
    int sz = arr.size();
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    map<int, int> m;
    for (int i =0 ; i < sz; i++){
        m.insert({sorted[i], i });
    }
    vector<int> arr1 = arr;
    int swap1 = 0;
    int i = 0;
    while(sorted != arr){
        int it = m[arr[i]];
        int index = it;
        if (index != i){
            int temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
            swap1++;
        }
        else{
            i++;
        }
    }
    reverse(sorted.begin(), sorted.end());
    int swap2 = 0;
    i = 0;
    while(sorted != arr1){
        int it =m[arr1[i]];
        int index = sz-1-it;
        if (index != i){
            int temp = arr1[index];
            arr1[index] = arr1[i];
            arr1[i] = temp;
            swap2++;
        }
        else{
            i++;
        }
    }

    return min(swap1, swap2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";
    cout << result << "\n";

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

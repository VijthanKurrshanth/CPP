#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'closestNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> find_min_idx(vector<int> arr){
    int sz = arr.size();
    vector<int> indexes = {0};
    int min = arr[0];
    for (int i = 1; i < sz; i++){
        if (arr[i] < min){
            min = arr[i];
            indexes.clear();
            indexes.push_back(i);
        }
        else if (arr[i] == min){
            indexes.push_back(i);
        }
    }
    return indexes;
}

vector<int> closestNumbers(vector<int> arr) {
    int sz = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> difference;
    vector<int> output;
    for (int i = 1; i < sz; i++){
        difference.push_back(arr[i] - arr[i-1]);
    }
    vector<int> indexes = find_min_idx(difference);
    for (int j = 0; j < indexes.size(); j++){
        output.push_back(arr[indexes[j]]);
        output.push_back(arr[indexes[j]+1]);
    }
    return output;
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

    vector<int> result = closestNumbers(arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];
        cout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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

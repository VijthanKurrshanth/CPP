#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'bigSorting' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY unsorted as parameter.
 */

struct integer {
    int index;
    string value;
};

long double str_to_int(string s){
    double len = s.size();
    long double output_int = 0;
    for (auto x : s){
        int digit = int(x) - 48;
        long double power = pow(10.0, len-1);
        output_int += digit*power;
        len -= 1;
    }
    return output_int;
}

vector<string> bigSorting(vector<string> unsorted) {
    vector<integer> integer_arr;
    vector<long double> unsorted_int;
    vector<long double> sorted_int;
    int len = unsorted.size();
    for (int i = 0; i < len; i++){
        integer* a = new integer;
        a->index = i;
        a->value = unsorted[i];
        unsorted_int.push_back(str_to_int(unsorted[i]));
        integer_arr.push_back(*a);
    }
    sorted_int = unsorted_int;
    sort(sorted_int.begin(), sorted_int.end());
    for (int i = 0; i < len; i++){
        integer* b = &integer_arr[i];
        for (int j = 0; j < len; j++){
            if (str_to_int(b->value) == sorted_int[j]){
                int k = 0;
                b->index = j;
                sorted_int[j] = -1;
                break;
            }
        }
    }
    vector<string> sorted(len);
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            integer* b = &integer_arr[j];
            if (b->value == unsorted[i]){
                sorted[b->index] = unsorted[i];
                b->value ="";
                break;
            }
        }
    }

    return sorted;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
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

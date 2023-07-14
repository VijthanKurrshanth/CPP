#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'weightedUniformStrings' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY queries
 */

vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector<string> answers;
    vector<int> weights;
    int weight = 0;
    char prev_char = ' ';
    int repeats = 1;
    for (auto x : s){
        char current_char = x;
        if (prev_char == current_char){
            repeats += 1;
            weight = (int(current_char) - 96)*repeats;
            weights.push_back(weight);
            prev_char = x;
        }
        else{
            repeats = 1;
            weight = int(current_char) - 96;
            weights.push_back(weight);
            prev_char = x;
        }

    }

    for (auto x : queries){
        if (std::find(weights.begin(), weights.end(),x)!=weights.end()){
            answers.push_back("Yes");
        }
        else{
            answers.push_back("No");
        }
    }

    return answers;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];
        cout << result[i];

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

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int summation (string p, int len){
    if (len == 1){
        return p[0] - '0';
    }
    else{
        int left = summation(p.substr(0, len/2), len/2);
        int right = summation(p.substr(len/2, len - len/2), len - len/2);
        string result = stoi(left + right);
        len = result.length();
        return summation(result, len)
    }
}

int superDigit(string n, int k) {
    string p ="";
    for (int i = 0; i < k; i++){
        p += n;
    }
    int len = p.length();
    int sum = 0;
    sum = summation (p, len);
    p = to_string(sum);
    len = p.length();

    if (len == 1){
        return p[0] - '0';
    }
    else{
        return superDigit(p, 1);
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    string n = first_multiple_input[0];

    int k = stoi(first_multiple_input[1]);

    int result = superDigit(n, k);

    fout << result << "\n";

    fout.close();

    cout << result;

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

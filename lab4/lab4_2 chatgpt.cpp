#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */

#include <iostream>
#include <cmath>
using namespace std;

int powerSum(int X, int N, int current = 1) {
    // base case: X is zero, we found a valid sum
    if (X == 0) {
        return 1;
    }
    // base case: current number raised to the power N is greater than X, can't use it
    else if (pow(current, N) > X) {
        return 0;
    }
    // recursive case: include current number raised to the power N in the sum and move to the next number
    else {
        int include = powerSum(X-pow(current, N), N, current+1);
        // recursive case: exclude current number raised to the power N from the sum and move to the next number
        int exclude = powerSum(X, N, current+1);
        return include + exclude;
    }
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    int X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    int result = powerSum(X, N, 1);

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

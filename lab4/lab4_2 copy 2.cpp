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

long check(long num, vector<long> init_values){
    if ((count(init_values.begin(), init_values.end(), num) != 0)){
        num = num - 1;
        return check(num, init_values);
    }
    else{
        return num;
    }
}

int powerSum(long X, long N) {
    long no = 0;
    vector<long> init_values;
    long sum = 0;
    double n = N;
    long x = X;

    double temp = pow(x, 1/n);
    long value = temp/1;

    for(long i = value; i > 0; i--){
        if ((count(init_values.begin(), init_values.end(), i) == 0)){
            double temp = pow(i, N);
            long value = temp/1;
            init_values.push_back(i);
            x = X;
            x -= value;
            sum = value;
            long count = 1;
            while (sum != X && init_values[init_values.size()-1] !=1 && init_values[init_values.size()-1] > 0){
                double temp = pow(x, 1/n);
                long value = temp/1;
                value = check(value, init_values);
                double temp2 = pow(value, N);
                long value2 = temp2/1;
                x -= value2;
                sum += value2;
                init_values.push_back(value);
                count ++;
            }
            if (sum == X){
                no +=1;
            }
            else{
                while (count > 0){
                    init_values.pop_back();
                    count --;
                }
            }
        }
    }
    for (long unsigned int i = 0; i < init_values.size(); i++){
        cout << init_values[i] << " ";
    }
    cout << endl;
    return no;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    long X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    long N = stoi(ltrim(rtrim(N_temp)));

    int result = powerSum(X, N);

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

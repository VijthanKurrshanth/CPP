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

int check(int num, vector<unsigned int> init_values){
    if ((count(init_values.begin(), init_values.end(), num) != 0)){
        num = num - 1;
        return check(num, init_values);
    }
    else{
        return num;
    }
}

int powerSum(int X, int N) {
    int no = 0;
    vector<unsigned int> init_values;
    int sum = 0;
    double n = N;
    int x = X;

    double temp = pow(x, 1/n);
    int value = round(temp);

    for(int i = value; i > 0; i--){
        //if ((count(init_values.begin(), init_values.end(), i) == 0)){
            int temp = pow(i, N);
            init_values.push_back(i);
            x = X;
            x -= temp;
            sum = temp;
            int count = 1;
            while (sum < X && init_values[init_values.size()-1] !=1 && init_values[init_values.size()-1] > 0){
                double temp = pow(x, 1/n);
                int value = round(temp);
                value = check(value, init_values);
                int temp2 = pow(value, N);
                x -= temp2;
                sum += temp2;
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
        //}
    }
    for (int i = 0; i < int(init_values.size()); i++){
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

    int X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

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

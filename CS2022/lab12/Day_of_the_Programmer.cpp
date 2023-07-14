#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    bool Julian = 0;
    bool leap = 0;
    if (year < 1918){
        Julian = 1;
        if (year%4 == 0){
            leap = 1;
        }
    }
    else{
        if (year%400 == 0){
            leap = 1;
        }
        else if (year%100 != 0 && year%4 == 0){
            leap = 1;
        }
    }

    int date = 0;
    if (Julian){
        if (leap){
            date = 256 - 244;
        }
        else{
            date = 256 - 243;
        }
    }
    else if (year == 1918){
        date = 256 - 230;
    }
    else{
        if (leap){
            date = 256 - 244;
        }
        else{
            date = 256 - 243;
        }
    }
    string year_str = to_string(year);
    string date_str = to_string(date);
    string result = date_str+".09."+year_str;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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

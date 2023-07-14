#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */
struct HashTable{
    int* letters = new int[26];

    void intialize_hashtable(){
        for (int i = 0; i < 26; i++){
            letters[i] = 0;
        }
    }

    void insert(char x){
        int position = int(x)-97;
        letters[position] = 1;
    }

    bool find(char x){
        int position = int(x)-97;
        if(letters[position] == 1){
            return true;
        }
        else{
            return false;
        }
    } 
};

int count = 0;

string twoStrings(string s1, string s2) {
    HashTable* table = new HashTable;
    table->intialize_hashtable();
    int s1_sz = s1.size();
    for (int i = 0; i < s1_sz; i++){
        table->insert(s1[i]);
        // for (int j = 0; j < 26; j++){
        //     cout << table->letters[j];
        // }
        cout << endl;
    }
    int s2_sz = s2.size();
    for (int i = 0; i < s2_sz; i++){
        bool found = table->find(s2[i]);
        if (found){
            delete table;
            return "YES";
        }
    }
    delete table;
    return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
        cout << result << endl;
    }

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

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream MyFile("filename.txt");
    for (int i = 1; i < 200001; i++){
        MyFile << 1 + (rand() % 10000000) << " " << 1 + (rand() % 10000000) << " " << 1 + (rand() % 1000000000) << endl;
    }
}

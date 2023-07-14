#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string firstline;
    getline (cin, firstline);
    int len_fl = firstline.size();
    string G_str = "";
    int i = 0;
    while (firstline[i] != ' '){
        G_str += firstline[i];
        i++;
    }
    int G = stoi(G_str);
    i++;

    string n_str = "";
    while (i < len_fl){
        n_str += firstline[i];
        i++;
    }
    int n = stoi(n_str);
    i = 0;

    int g[n], x[n], y[n], z[n];
    for (i = 0; i<n; i++){
        string nextline;
        getline (cin, nextline);
        int len_nl = nextline.size();
        string g_str = "";
        int j = 0;
        while (nextline[j] != ' '){
            g_str += nextline[j];
            j++;
        }
        g[i] = stoi(g_str);
        j++;

        string x_str = "";
        while (nextline[j] != ' '){
            x_str += nextline[j];
            j++;
        }
        x[i] = stoi(x_str);
        j++;

        string y_str = "";
        while (nextline[j] != ' '){
            y_str += nextline[j];
            j++;
        }
        y[i] = stoi(y_str);
        j++;

        string z_str = "";
        while (j < len_nl){
            z_str += nextline[j];
            j++;
        }
        z[i] = stoi(z_str);
        j++;
    }

    int max_profit = 0;
    for (int j = 0; j < n; j++){
        int max_stuff = z[0];
        int max_stuff_idx = 0;
        for (i = 1; i < n; i++){
            if (z[i] > max_stuff){
                max_stuff = z[i];
                max_stuff_idx = i;
            }
        }
        int max_stuff_count = g[max_stuff_idx]/x[max_stuff_idx];
        if (y[max_stuff_idx]*max_stuff_count <= G){
            max_profit += max_stuff_count*max_stuff;
            G -= y[max_stuff_idx]*max_stuff_count;
        }
        z[max_stuff_idx] = 0;
    }

    cout << max_profit;
    return 0;
}

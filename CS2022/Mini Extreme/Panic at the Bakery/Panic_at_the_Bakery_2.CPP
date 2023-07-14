#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maximumEarnings(int G, int g[], int x[], int y[], int z[]) {
    int n = g.size();
    vector<vector<int>> dp(n + 1, vector<int>(G + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= G; j++) {
            if (g[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], z[i - 1] + dp[i - 1][j - g[i - 1]] - y[i - 1] * x[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][G];
}

int main() {
    int G; // Amount of flour available
    int n; // Number of stuffing types

    cout << "Enter the amount of flour available (G): ";
    cin >> G;

    cout << "Enter the number of stuffing types (n): ";
    cin >> n;

    vector<int> g(n), x(n), y(n), z(n);

    cout << "Enter the amount of each stuffing type (g[i]): ";
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    cout << "Enter the grams of stuffing required for each type (x[i]): ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter the grams of flour required for each type (y[i]): ";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    cout << "Enter the selling price for each type (z[i]): ";
    for (int i = 0; i < n; i++) {
        cin >> z[i];
    }

    int maxEarnings = maximumEarnings(G, g, x, y, z);

    cout << "Maximum earnings: Rs " << maxEarnings << endl;

    return 0;
}


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

    vector<int> g(n), x(n), y(n), z(n);
    for (i; i<n; i++){
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

    
    return 0;
}

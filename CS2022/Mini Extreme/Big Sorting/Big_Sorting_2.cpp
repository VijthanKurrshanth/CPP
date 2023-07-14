#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

std::string ltrim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    return (start == std::string::npos) ? "" : str.substr(start);
}

std::string rtrim(const std::string& str) {
    size_t end = str.find_last_not_of(" \t\r\n");
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

std::vector<std::string> bigSorting(std::vector<std::string>& unsorted) {
    std::unordered_map<std::string, int> stringMap;
    for (int i = 0; i < unsorted.size(); i++) {
        stringMap[unsorted[i]] = i;
    }

    std::sort(unsorted.begin(), unsorted.end());

    std::vector<std::string> sorted(unsorted.size());
    for (int i = 0; i < unsorted.size(); i++) {
        sorted[i] = unsorted[stringMap[unsorted[i]]];
    }

    return sorted;
}

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string n_temp;
    std::getline(std::cin, n_temp);
    int n = std::stoi(ltrim(rtrim(n_temp)));

    std::vector<std::string> unsorted(n);
    for (int i = 0; i < n; i++) {
        std::string unsorted_item;
        std::getline(std::cin, unsorted_item);
        unsorted[i] = unsorted_item;
    }

    std::vector<std::string> result = bigSorting(unsorted);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    fout << "\n";
    fout.close();

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

struct in_ord {
    int price; // Replace this with your actual member variable(s)
    char name;
};

// Custom comparison function for ascending order
bool compareByValueA(const in_ord* a, const in_ord* b) {
    return a->price < b->price;
}

void insertIntoSortedVectorA(std::vector<in_ord*>& sortedVector, in_ord* newValue) {
    if (sortedVector.empty()) {
        sortedVector.push_back(newValue);
        return;
    }

    auto it = std::lower_bound(sortedVector.begin(), sortedVector.end(), newValue, compareByValueA);

    // Find the first element in the vector with the same price
    auto samePriceIt = it;
    while (samePriceIt != sortedVector.begin() && compareByValueA(*(samePriceIt - 1), newValue) == false) {
        --samePriceIt;
    }

    // Insert the new value after the last element with the same price
    sortedVector.insert(samePriceIt, newValue);
}

int main() {
    // Example usage
    std::vector<in_ord*> sortedVector;
    in_ord* newValue1 = new in_ord{5,'a'};
    in_ord* newValue2 = new in_ord{3,'b'};
    in_ord* newValue3 = new in_ord{7,'c'};
    in_ord* newValue4 = new in_ord{7,'d'}; // Same price as newValue2
    in_ord* newValue5 = new in_ord{7,'e'};

    insertIntoSortedVectorA(sortedVector, newValue1);
    insertIntoSortedVectorA(sortedVector, newValue2);
    insertIntoSortedVectorA(sortedVector, newValue3);
    insertIntoSortedVectorA(sortedVector, newValue4);
    insertIntoSortedVectorA(sortedVector, newValue5);

    // Print the sortedVector to check the order
    for (const auto& inOrdPtr : sortedVector) {
        std::cout << inOrdPtr->price << " "<< inOrdPtr->name << "\n";
    }
    std::cout << std::endl;

    // Don't forget to release memory for the objects you created
    delete newValue1;
    delete newValue2;
    delete newValue3;
    delete newValue4;

    return 0;
}

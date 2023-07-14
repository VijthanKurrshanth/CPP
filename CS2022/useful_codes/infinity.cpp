#include <limits>

int main() {
    int arr[5] = {1, 2, 3, 4, std::numeric_limits<int>::infinity()};
    // 'arr' is now {1, 2, 3, 4, infinity}
    
    double arr2[3] = {0.5, 1.2, std::numeric_limits<double>::infinity()};
    // 'arr2' is now {0.5, 1.2, infinity}

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1,2,0,0,0,1,2,0,};

    // Sort in ascending order
    std::sort(vec.begin(), vec.end());

    for (int num : vec) {
        std::cout << num << " ";
    }
    return 0;
}

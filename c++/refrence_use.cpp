#include <iostream>
#include <vector>

void processVector(const std::vector<int>& data) {
    std::cout << "Size of vector: " << data.size() << std::endl;
    // You can read from 'data' but can't modify it
}

int main() {
    std::vector<int> largeVec(1'000'000, 42); // 1 million integers
    processVector(largeVec); // No copy, just a reference
    return 0;
}
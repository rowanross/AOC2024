#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main() {
    std::ifstream file("input.txt");
    std::vector<long> leftNums;
    std::vector<long> rightNums;
    
    long left, right;
    while (file >> left >> right) {
        leftNums.push_back(left);
        rightNums.push_back(right);
    }

    // Sort both lists
    std::sort(leftNums.begin(), leftNums.end());
    std::sort(rightNums.begin(), rightNums.end());

    long totalDistance = 0;
    
    // Calculate distances between paired numbers
    for (size_t i = 0; i < leftNums.size(); i++) {
        totalDistance += std::abs(leftNums[i] - rightNums[i]);
    }

    std::cout << "Total distance: " << totalDistance << std::endl;

    return 0;
}
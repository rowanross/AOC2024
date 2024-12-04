#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    ifstream file("input.txt");
    vector<long> leftNums;
    vector<long> rightNums;
    
    long left, right;
    while (file >> left >> right) {
        leftNums.push_back(left);
        rightNums.push_back(right);
    }

    // Sort both lists
    sort(leftNums.begin(), leftNums.end());
    sort(rightNums.begin(), rightNums.end());

    long totalDistance = 0;
    
    // Calculate distances between paired numbers
    for (size_t i = 0; i < leftNums.size(); i++) {
        totalDistance += std::abs(leftNums[i] - rightNums[i]);
    }

    std::cout << "Total distance: " << totalDistance << std::endl;

    return 0;
}

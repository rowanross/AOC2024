#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
    std::ifstream file("input.txt");
    std::vector<long> leftNums;
    std::vector<long> rightNums;
    
    long left, right;
    while (file >> left >> right) {
        leftNums.push_back(left);
        rightNums.push_back(right);
    }

    // Count occurrences of numbers in right list
    std::unordered_map<long, int> rightNumCounts;
    for (long num : rightNums) {
        rightNumCounts[num]++;
    }

    // Calculate similarity score
    long totalSimilarity = 0;
    for (long leftNum : leftNums) {
        totalSimilarity += leftNum * rightNumCounts[leftNum];
    }

    std::cout << "Total similarity score: " << totalSimilarity << std::endl;

    return 0;
}

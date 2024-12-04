#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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

    // Count occurrences of numbers in right list
    unordered_map<long, int> rightNumCounts;
    for (long num : rightNums) {
        rightNumCounts[num]++;
    }

    // Calculate similarity score
    long totalSimilarity = 0;
    for (long leftNum : leftNums) {
        totalSimilarity += leftNum * rightNumCounts[leftNum];
    }

    cout << "Total similarity score: " << totalSimilarity << endl;

    return 0;
}

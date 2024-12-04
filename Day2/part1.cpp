#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream file("input.txt");
    string line;
    int safeReports = 0;

    while (getline(file, line)) {
        vector<int> levels;
        stringstream ss(line);
        int level;
        
        // Parse numbers from line into vector
        while (ss >> level) {
            levels.push_back(level);
        }

        if (levels.size() < 2) continue;

        bool isValid = true;
        bool isIncreasing = levels[1] > levels[0];
        
        // Check each adjacent pair
        for (size_t i = 1; i < levels.size(); i++) {
            int diff = levels[i] - levels[i-1];
            
            // Check if difference is between 1 and 3 (inclusive)
            if (abs(diff) < 1 || abs(diff) > 3) {
                isValid = false;
                break;
            }
            
            // Check if direction changes
            if (isIncreasing && diff < 0) {
                isValid = false;
                break;
            }
            if (!isIncreasing && diff > 0) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            safeReports++;
        }
    }

    cout << "Number of safe reports: " << safeReports << endl;
    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::ifstream file("input.txt");
    std::string line;
    int safeReports = 0;

    while (std::getline(file, line)) {
        std::vector<int> levels;
        std::stringstream ss(line);
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
            if (std::abs(diff) < 1 || std::abs(diff) > 3) {
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

    std::cout << "Number of safe reports: " << safeReports << std::endl;
    return 0;
}

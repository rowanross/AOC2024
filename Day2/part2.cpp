#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

// Helper function to check if a sequence is valid
bool isValidSequence(const std::vector<int>& levels) {
    if (levels.size() < 2) return false;
    
    bool isIncreasing = levels[1] > levels[0];
    
    for (size_t i = 1; i < levels.size(); i++) {
        int diff = levels[i] - levels[i-1];
        
        if (std::abs(diff) < 1 || std::abs(diff) > 3) {
            return false;
        }
        
        if (isIncreasing && diff < 0) {
            return false;
        }
        if (!isIncreasing && diff > 0) {
            return false;
        }
    }
    return true;
}

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

        // First check if sequence is valid without removing any level
        if (isValidSequence(levels)) {
            safeReports++;
            continue;
        }

        // Try removing each level one at a time to see if it makes the sequence valid
        bool canBeMadeValid = false;
        for (size_t i = 0; i < levels.size(); i++) {
            std::vector<int> modifiedLevels = levels;
            modifiedLevels.erase(modifiedLevels.begin() + i);
            
            if (isValidSequence(modifiedLevels)) {
                canBeMadeValid = true;
                break;
            }
        }

        if (canBeMadeValid) {
            safeReports++;
        }
    }

    std::cout << "Number of safe reports: " << safeReports << std::endl;
    return 0;
}

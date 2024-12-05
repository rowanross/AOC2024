#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

int main() {
    std::ifstream file("input.txt");
    std::string line;
    std::unordered_map<int, std::unordered_set<int>> rules;
    std::vector<std::vector<int>> updates;
    bool parsingRules = true;

    // Parse input
    while (std::getline(file, line)) {
        if (line.empty()) {
            parsingRules = false;
            continue;
        }

        if (parsingRules) {
            // Parse rules like "47|53"
            int before = std::stoi(line.substr(0, line.find('|')));
            int after = std::stoi(line.substr(line.find('|') + 1));
            rules[before].insert(after);
        } else {
            // Parse updates like "75,47,61,53,29"
            std::vector<int> update;
            std::stringstream ss(line);
            std::string num;
            while (std::getline(ss, num, ',')) {
                update.push_back(std::stoi(num));
            }
            updates.push_back(update);
        }
    }

    int sum = 0;

    // Check each update
    for (const auto& update : updates) {
        bool valid = true;
        
        // For each pair of numbers in the update
        for (size_t i = 0; i < update.size(); i++) {
            for (size_t j = i + 1; j < update.size(); j++) {
                int first = update[i];
                int second = update[j];
                
                // If there's a rule saying second should come before first
                if (rules[second].count(first)) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }

        if (valid) {
            // Add middle number to sum
            sum += update[update.size() / 2];
        }
    }

    std::cout << "Sum of middle numbers in valid updates: " << sum << std::endl;
    return 0;
}

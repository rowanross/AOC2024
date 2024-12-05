#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

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
    for (auto& update : updates) {
        bool valid = true;
        
        // Check if current order is valid
        for (size_t i = 0; i < update.size(); i++) {
            for (size_t j = i + 1; j < update.size(); j++) {
                int first = update[i];
                int second = update[j];
                
                if (rules[second].count(first)) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }

        // If invalid, sort it according to rules
        if (!valid) {
            std::sort(update.begin(), update.end(), 
                [&rules](int a, int b) {
                    // If b should come before a, return false
                    if (rules[b].count(a)) return false;
                    // If a should come before b, return true
                    if (rules[a].count(b)) return true;
                    // If no direct rule, keep original order
                    return a > b;
                });
            
            // Add middle number to sum
            sum += update[update.size() / 2];
        }
    }

    std::cout << "Sum of middle numbers in reordered invalid updates: " << sum << std::endl;
    return 0;
}

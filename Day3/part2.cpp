#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    std::ifstream file("input.txt");
    std::string line;
    int sum = 0;
    bool mulEnabled = true;
    
    // Regular expressions to match instructions
    std::regex mulPattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    std::regex doPattern(R"(do\(\))");
    std::regex dontPattern(R"(don't\(\))");
    
    while (std::getline(file, line)) {
        std::smatch matches;
        std::string::const_iterator searchStart(line.cbegin());
        
        // Process all instructions in order
        while (searchStart != line.cend()) {
            if (std::regex_search(searchStart, line.cend(), matches, doPattern)) {
                if (matches.position() == 0) {
                    mulEnabled = true;
                    searchStart = matches.suffix().first;
                    continue;
                }
            }
            
            if (std::regex_search(searchStart, line.cend(), matches, dontPattern)) {
                if (matches.position() == 0) {
                    mulEnabled = false;
                    searchStart = matches.suffix().first;
                    continue;
                }
            }
            
            if (std::regex_search(searchStart, line.cend(), matches, mulPattern)) {
                if (matches.position() == 0) {
                    if (mulEnabled) {
                        // Convert matched numbers to integers and multiply
                        int x = std::stoi(matches[1]);
                        int y = std::stoi(matches[2]);
                        sum += x * y;
                    }
                    searchStart = matches.suffix().first;
                    continue;
                }
            }
            
            // Move forward one character if no match at current position
            ++searchStart;
        }
    }
    
    std::cout << "Sum of enabled multiplication results: " << sum << std::endl;
    return 0;
}

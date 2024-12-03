#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    std::ifstream file("input.txt");
    std::string line;
    int sum = 0;
    
    // Regular expression to match valid mul(X,Y) instructions
    // Matches: mul(digits,digits) where digits are 1-3 characters
    std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    
    while (std::getline(file, line)) {
        std::smatch matches;
        std::string::const_iterator searchStart(line.cbegin());
        
        // Find all valid mul instructions in the line
        while (std::regex_search(searchStart, line.cend(), matches, pattern)) {
            // Convert matched numbers to integers and multiply
            int x = std::stoi(matches[1]);
            int y = std::stoi(matches[2]);
            sum += x * y;
            
            // Move to next position after current match
            searchStart = matches.suffix().first;
        }
    }
    
    std::cout << "Sum of all multiplication results: " << sum << std::endl;
    return 0;
}

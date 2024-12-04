#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std; 

int main() {
    ifstream file("input.txt");
    string line;
    int sum = 0;
    
    // Regular expression to match valid mul(X,Y) instructions
    // Matches: mul(digits,digits) where digits are 1-3 characters
    regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    
    while (getline(file, line)) {
        smatch matches;
        string::const_iterator searchStart(line.cbegin());
        
        // Find all valid mul instructions in the line
        while (regex_search(searchStart, line.cend(), matches, pattern)) {
            // Convert matched numbers to integers and multiply
            int x = stoi(matches[1]);
            int y = stoi(matches[2]);
            sum += x * y;
            
            // Move to next position after current match
            searchStart = matches.suffix().first;
        }
    }
    
    std::cout << "Sum of all multiplication results: " << sum << endl;
    return 0;
}

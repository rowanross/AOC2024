#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main() {
    ifstream file("input.txt");
    string line;
    int sum = 0;
    bool mulEnabled = true;
    
    // Regular expressions to match instructions
    regex mulPattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    regex doPattern(R"(do\(\))");
    regex dontPattern(R"(don't\(\))");
    
    while (getline(file, line)) {
        smatch matches;
        string::const_iterator searchStart(line.cbegin());
        
        // Process all instructions in order
        while (searchStart != line.cend()) {
            if (regex_search(searchStart, line.cend(), matches, doPattern)) {
                if (matches.position() == 0) {
                    mulEnabled = true;
                    searchStart = matches.suffix().first;
                    continue;
                }
            }
            
            if (regex_search(searchStart, line.cend(), matches, dontPattern)) {
                if (matches.position() == 0) {
                    mulEnabled = false;
                    searchStart = matches.suffix().first;
                    continue;
                }
            }
            
            if (regex_search(searchStart, line.cend(), matches, mulPattern)) {
                if (matches.position() == 0) {
                    if (mulEnabled) {
                        // Convert matched numbers to integers and multiply
                        int x = stoi(matches[1]);
                        int y = stoi(matches[2]);
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
    
    cout << "Sum of enabled multiplication results: " << sum << endl;
    return 0;
}

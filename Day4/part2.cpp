#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream file("input.txt");
    vector<string> grid;
    string line;
    
    // Read input into grid
    while (getline(file, line)) {
        grid.push_back(line);
    }

    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    // Check each potential center position (A)
    for (int r = 1; r < rows - 1; r++) {
        for (int c = 1; c < cols - 1; c++) {
            if (grid[r][c] != 'A') continue;

            // Check all four possible combinations for the X pattern
            // Top-left to bottom-right and top-right to bottom-left
            bool topLeftValid = (grid[r-1][c-1] == 'M' && grid[r+1][c+1] == 'S');
            bool topRightValid = (grid[r-1][c+1] == 'M' && grid[r+1][c-1] == 'S');
            bool bottomLeftValid = (grid[r+1][c-1] == 'M' && grid[r-1][c+1] == 'S');
            bool bottomRightValid = (grid[r+1][c+1] == 'M' && grid[r-1][c-1] == 'S');

            // Check each valid combination
            if (topLeftValid && topRightValid) count++;
            if (topLeftValid && bottomLeftValid) count++;
            if (topRightValid && bottomRightValid) count++;
            if (bottomLeftValid && bottomRightValid) count++;
        }
    }

    cout << "X-MAS appears " << count << " times" << endl;

    return 0;
}

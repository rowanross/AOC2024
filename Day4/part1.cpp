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

    // Check all possible directions
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Check each starting position
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            // Try each direction
            for (int dir = 0; dir < 8; dir++) {
                // Check if "XMAS" can fit in this direction from this position
                if (r + 3*dr[dir] >= 0 && r + 3*dr[dir] < rows &&
                    c + 3*dc[dir] >= 0 && c + 3*dc[dir] < cols) {
                    
                    // Check if letters match "XMAS"
                    if (grid[r][c] == 'X' &&
                        grid[r + dr[dir]][c + dc[dir]] == 'M' &&
                        grid[r + 2*dr[dir]][c + 2*dc[dir]] == 'A' &&
                        grid[r + 3*dr[dir]][c + 3*dc[dir]] == 'S') {
                        count++;
                    }
                }
            }
        }
    }

    cout << "XMAS appears " << count << " times" << endl;

    return 0;
}

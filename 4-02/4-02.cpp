#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Function to check if two ranges overlap
bool rangesOverlap(int start1, int end1, int start2, int end2) {
    return max(start1, start2) <= min(end1, end2);
}

int main() {
    ifstream inputFile("4-02-input.txt"); 
    string line;
    int count = 0;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        vector<pair<int, int>> ranges;

        // Parsing input line to extract ranges
        while (getline(ss, line, ',')) {
            int start, end;
            sscanf(line.c_str(), "%d-%d", &start, &end);
            ranges.push_back({start, end});
        }

        // Checking if any two ranges overlap
        for (size_t i = 0; i < ranges.size(); ++i) {
            for (size_t j = i + 1; j < ranges.size(); ++j) {
                if (rangesOverlap(ranges[i].first, ranges[i].second, ranges[j].first, ranges[j].second)) {
                    count++;
                }
            }
        }
    }

    cout << "Number of assignment pairs where the ranges overlap: " << count << endl;

    return 0;
}

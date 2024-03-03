#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// Function to check if one range fully contains the other
bool containsRange(int start1, int end1, int start2, int end2) {
    return start1 <= start2 && end1 >= end2;
}

int main() {
    std::ifstream inputFile("4-01-input.txt"); // Assuming the input file is named "input.txt"
    std::string line;
    int count = 0;

    while (getline(inputFile, line)) {
        std::stringstream ss(line);
        std::vector<std::pair<int, int>> ranges;

        // Parsing input line to extract ranges
        while (getline(ss, line, ',')) {
            int start, end;
            sscanf(line.c_str(), "%d-%d", &start, &end);
            ranges.push_back({start, end});
        }

        // Checking if one range fully contains the other for each pair
        for (size_t i = 0; i < ranges.size(); ++i) {
            for (size_t j = i + 1; j < ranges.size(); ++j) {
                if (containsRange(ranges[i].first, ranges[i].second, ranges[j].first, ranges[j].second) ||
                    containsRange(ranges[j].first, ranges[j].second, ranges[i].first, ranges[i].second)) {
                    count++;
                }
            }
        }
    }

    std::cout << "Number of assignment pairs where one range fully contains the other: " << count << std::endl;

    return 0;
}

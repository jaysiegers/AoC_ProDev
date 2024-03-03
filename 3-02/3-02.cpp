#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>

int calculatePriority(char item) {
    if (item >= 'a' && item <= 'z') {
        return item - 'a' + 1;
    } else if (item >= 'A' && item <= 'Z') {
        return item - 'A' + 27;
    }
    return 0; // Invalid item
}

int main() {
    std::ifstream fin("3-02-input.txt");
    if (!fin.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    int totalPriority = 0;

    // Read input in groups of three lines
    while (std::getline(fin, line)) {
        std::unordered_set<char> items;

        // Read the first line of the group
        for (char item : line) {
            items.insert(item);
        }

        // Read the next two lines of the group and find common items
        for (int i = 0; i < 2; ++i) {
            std::getline(fin, line);
            std::unordered_set<char> tempItems;
            for (char item : line) {
                tempItems.insert(item);
            }

            // Perform set intersection to find common items between the current line and previous lines
            std::unordered_set<char> commonItems;
            for (char item : tempItems) {
                if (items.find(item) != items.end()) {
                    commonItems.insert(item);
                }
            }
            items = std::move(commonItems); // Update items with common items
        }

        // Calculate and accumulate priorities for common items
        for (char item : items) {
            totalPriority += calculatePriority(item);
        }
    }

    std::cout << "Total Priority: " << totalPriority << std::endl;

    fin.close();
    return 0;
}

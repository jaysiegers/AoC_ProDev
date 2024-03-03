#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

int calculatePriority(char item) {
    if (item >= 'a' && item <= 'z') {
        return item - 'a' + 1;
    } else if (item >= 'A' && item <= 'Z') {
        return item - 'A' + 27;
    }
    return 0; // Invalid item
}

int main() {
    std::ifstream fin("3-01-input.txt");
    if (!fin.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    int totalPriority = 0;

    while (std::getline(fin, line)) {
        std::unordered_set<char> items;

        // Split the line into two compartments
        std::string compartment1 = line.substr(0, line.size() / 2);
        std::string compartment2 = line.substr(line.size() / 2);

        // Find items that appear in both compartments
        for (char item : compartment1) {
            if (compartment2.find(item) != std::string::npos) {
                items.insert(item);
            }
        }

        // Calculate and accumulate priorities
        for (char item : items) {
            totalPriority += calculatePriority(item);
        }
    }

    std::cout << "Total Priority: " << totalPriority << std::endl;

    fin.close();
    return 0;
}

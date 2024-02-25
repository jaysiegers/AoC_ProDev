#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream input("1-02-input.txt");

    std::string line;
    int current = 0;
    std::vector<int> top3;

    while (std::getline(input, line))
    {
        if (line.length() == 0)
        {
            // Sort the top3 vector in descending order
            std::sort(top3.begin(), top3.end(), std::greater<int>());

            // Add current sum to top3 if it's greater than the smallest value in top3
            if (top3.size() < 3 || current > top3.back())
            {
                top3.push_back(current);
                // Sort the top3 vector again after adding a new value
                std::sort(top3.begin(), top3.end(), std::greater<int>());
                // Keep only the top 3 values
                if (top3.size() > 3)
                {
                    top3.pop_back();
                }
            }
            current = 0;
        }
        current += std::atoi(line.c_str());
    }
    input.close();

    // Sort the top3 vector in descending order
    std::sort(top3.begin(), top3.end(), std::greater<int>());

    // Output the top 3 highest sums of calories

    int top3_sum = 0;

    std::cout << "Top 3: ";
    for (int i = 0; i < top3.size(); ++i)
    {
        std::cout << top3[i];
        if (i < 2)
        {
            std::cout << ", ";
        }
    }

    std::cout << "\n";

    for (int i = 0; i < top3.size(); ++i)
    {
        top3_sum += top3[i];

    }

    std::cout << "sum: " << top3_sum;

    return EXIT_SUCCESS;
}
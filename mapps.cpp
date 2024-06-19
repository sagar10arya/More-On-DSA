#include <iostream>
#include <map>
#include <vector>

int main() {
    // Sample vector of elements to count
    std::vector<int> elements = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

    // Create a map to store the counts of each element
    std::map<int, int> elementCount;

    // Count the occurrences of each element
    for (int element : elements) {
        elementCount[element]++;
    }

    // Print the counts
    for (const auto& pair : elementCount) {
        std::cout << "Element " << pair.first << " occurs " << pair.second << " times." << std::endl;
    }

    return 0;
}

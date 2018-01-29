#include "A6.hpp"
#include <vector>
#include <string>
#include <iostream>


int main() {
    // Add more strings here to test.
    const std::vector<std::pair<std::string, size_t>> sample_strings{{"abc",   2},
                                                                     {"abcd",  1},
                                                                     {"abcde", 5}};

    StringStore storage;
    for (auto pair : sample_strings) {
        for (size_t count = 0; count < pair.second; ++count) {
            storage.insert(pair.first);
        }
    }

    for (auto pair : sample_strings) {
        size_t count = pair.second;
        size_t storedCount = storage.getFrequency(pair.first);
        if (count == storedCount) {
            std::cout << "Inserted count equals stored count for string " << pair.first << std::endl;
        }
        else {
            std::cout << "Inserted count does not equal stored count for string " << pair.first << std::endl;
        }
    }

    std::pair<std::string, size_t> maxPair{"", 0};
    for (auto pair : sample_strings) {
        if (pair.second > maxPair.second) {
            maxPair = pair;
        }
    }
    std::pair<std::string, size_t> computedMaxPair = storage.getMaxFrequency();
    if (computedMaxPair == maxPair) {
        std::cout << "Successfully computed max pair." << std::endl;
    }
    else {
        std::cout << "Unsuccessfully computed max pair." << std::endl;
        std::cout << "Found: (" << computedMaxPair.first << ", " << computedMaxPair.second << ")" << std::endl;
        std::cout << "Expected: (" << maxPair.first << ", " << maxPair.second << ")" << std::endl;
    }
    return 0;
}
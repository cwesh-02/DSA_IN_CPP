#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> map1 = {{"apple", 1}, {"banana", 2}};
    std::unordered_map<std::string, int> map2 = {{"banana", 2}, {"apple", 1}};
    std::unordered_map<std::string, int> map3 = {{"apple", 1}, {"banana", 3}};

    // Order does NOT matter for unordered_map comparison
    if (map1 == map2) {
        std::cout << "map1 and map2 are equal\n"; // This will print
    } else {
        std::cout << "map1 and map2 are NOT equal\n";
    }

    if (map1 == map3) {
        std::cout << "map1 and map3 are equal\n";
    } else {
        std::cout << "map1 and map3 are NOT equal\n"; // This will print
    }

    return 0;
}
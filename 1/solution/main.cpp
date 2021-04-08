#include <iostream>
#include "struct.hpp"
#include "vector.hpp"
#include "counting_sort.hpp"
#include <string>

unsigned S2I(std::string string_key){
    unsigned key = 0;
    for (char c: string_key){
        key = key * 10 + c - '0';
    }
    return key;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    TVector<TKeyValue> vector;
    std::string key;
    std::string value;

    while (std::cin >> key >> value){
        TKeyValue current_el(S2I(key), value);
        vector.PushBack(current_el);
    }
    CountingSort<TKeyValue>(vector).Print();
    std::cout << std::endl;
    return 0;
}

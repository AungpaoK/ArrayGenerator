#include <iostream>
#include <vector>
#include <random>
#include <chrono>

int findMax(const std::vector<int>& vec){
    int max = vec[0];
    for (int i = 1; i < vec.size(); i++){
        if (vec[i] > max){
            max = vec[i];
        }
    }
    return max;
}

int main() {

    auto start = std::chrono::high_resolution_clock::now();

    //random number using time seed
    unsigned long long seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 rng(seed);
    std::uniform_int_distribution<long long> dist_size(1, 10000000);

    int size = dist_size(rng);    
    
    //dynamic array size
    std::vector<int> vec(size);
    
    std::uniform_int_distribution<long long> dist_value(1, 100000000000);
    for (int i = 0; i < size; i++){
        vec[i] = dist_value(rng);
    }

    int max = findMax(vec); 
    std::cout << "Array size: " << size << std::endl;
    std::cout << "The max value is: " << max << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time took to execute: " << duration.count() << " milliseconds";

    return 0;
}
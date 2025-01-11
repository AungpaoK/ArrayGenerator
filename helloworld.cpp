#include <iostream>
#include <vector>
#include <random>
#include <chrono>

long long findMax(const std::vector<long long>& vec){
    long long max = vec[0];
    for (size_t i = 1; i < vec.size(); i++){
        if (vec[i] > max){
            max = vec[i];
        }
    }
    return max;
}

void bubbleSort(std::vector<long long>& vec){
    int n = vec.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++){
        swapped = false;
        for (int j = 0; j < n - i - 1; j++){
            if (vec[j] > vec[j+1]){
                std::swap(vec[j], vec[j+1]);
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
    }
}


int main() {

    auto start = std::chrono::high_resolution_clock::now();

    //random number using time seed
    unsigned long long seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 rng(seed);
    std::uniform_int_distribution<long long> dist_size(1, 1000000);

    long long size = dist_size(rng);    
    
    //dynamic array size
    std::vector<long long> vec(size);
    
    std::uniform_int_distribution<long long> dist_value(1, 100000000000);
    for (long long i = 0; i < size; i++){
        vec[i] = dist_value(rng);
    }

    long long max = findMax(vec); 
    std::cout << "Array size: " << size << std::endl;
    std::cout << "Last value before sort: " << vec.back() << std::endl;
    bubbleSort(vec);
    std::cout << "Last value after sort: " << vec.back() << std::endl;
    std::cout << "The max value: " << max << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    std::cout << "Time took to execute: " << duration.count() << " seconds";

    return 0;
}
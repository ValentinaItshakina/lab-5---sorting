#include <iostream>
#include <vector>
#include "func.cpp"


int main(){
    std::vector<float> arr = inputFloatVectorWithValidation();
    std::vector<float> rez = bucketSort(arr);
    for (float num : rez) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << Median(rez) << std::endl;
    
    return 0;
}
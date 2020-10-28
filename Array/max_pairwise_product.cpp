#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<long long int>& numbers) {
    int n = numbers.size();
    int max1 = 0;
    for(int i = 1 ; i < n; i++) {
        if(numbers[max1] < numbers[i]) max1 = i;
    } 

    int max2 = -1;
    for(int i = 0; i < n; i++) {
        if((i != max1) && ((max2 == -1) || (numbers[i] > numbers[max2]))) max2 = i;
    }

    return numbers[max1] * numbers[max2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}

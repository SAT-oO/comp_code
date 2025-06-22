#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
void lambda_invoke(){
    // Immediately invoked lambda
    []() {
        std::cout << "This lambda is called immediately!" << std::endl;
    }(); // The () immediately invokes the lambda

    int result = [](int x, int y) { return x * y; }(4, 2); // Immediately invoked with parameters
    std::cout << "Product: " << result << std::endl;

    // return;

    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Using a lambda with std::for_each
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n * 2 << " ";
    });
    std::cout << std::endl;
}
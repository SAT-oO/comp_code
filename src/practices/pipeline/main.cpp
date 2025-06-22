#include <iostream>
#include <functional>
#include <vector>
#include "lambda.cpp"

template<class T>
std::function<T (T)> makePipeline(const std::vector<std::function<T (T)>>& funcs) {
    
    return [&funcs] (const T& arg) {
        T res = arg;
        for (const auto& func : funcs) {
            res = func(res);
        }
        return res;
    };
}

#ifndef RunTests
int main()
{
    // lambda_invoke();
    // return 0;
    std::vector<std::function<int (int)>> functions;
    functions.push_back([] (int x) -> int { return x * 3; });
    functions.push_back([] (int x) -> int { return x + 1; });
    functions.push_back([] (int x) -> int { return x / 2; });
    
    std::function<int (int)> func = makePipeline(functions);
    std::cout << func(3)<<std::endl; // should print 5
    
}
#endif
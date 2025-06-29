#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>

int numberOfArrangements_recursion(int numberOfStories)
{
    if (numberOfStories <= 0)
    {
        throw std::invalid_argument("Number of stories must be a positive integer.");
    }
    if (numberOfStories == 2)
    {
        return 2;
    }
    if (numberOfStories == 1)
    {
        return 1;
    }

    return numberOfArrangements_recursion(numberOfStories - 1) + numberOfArrangements_recursion(numberOfStories - 2);
}

int numberOfArrangements_math(int numberOfStories)
{
    return 1 / sqrt(5) * (pow((1 + sqrt(5)) / 2, numberOfStories + 1) - pow((1 - sqrt(5)) / 2, numberOfStories + 1));
}

int numberOfArrangements_dp(int numberOfStories, std::vector<int> &vec)
{
    vec[0] = 1;
    vec[1] = 1;
    if (vec[numberOfStories] != -1)
        return vec[numberOfStories];

    vec[numberOfStories] = numberOfArrangements_dp(numberOfStories - 1, vec) + numberOfArrangements_dp(numberOfStories - 2, vec);
    return vec[numberOfStories];
}

#ifndef RunTests
int main()
{
    int n = 3;
    std::vector<int> vec(n + 1, -1);
    std::cout << numberOfArrangements_dp(n, vec) << std::endl;
}
#endif
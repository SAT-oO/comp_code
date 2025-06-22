#include <iostream>
#include <stdexcept>
#include <cmath>

int numberOfArrangements(int numberOfStories)
{
    // if(numberOfStories <= 0){
    //     throw std::invalid_argument("Number of stories must be a positive integer.");
    // }
    // if(numberOfStories == 2){
    //     return 2;
    // }
    // if(numberOfStories == 1){
    //     return 1;

    // }
    

    // return numberOfArrangements(numberOfStories -1) + numberOfArrangements(numberOfStories - 2);

    return 1/sqrt(5) * (pow((1 + sqrt(5)) / 2, numberOfStories+1) - pow((1 - sqrt(5)) / 2, numberOfStories+1));
}

#ifndef RunTests
int main()
{
    std::cout << numberOfArrangements(3);
}
#endif
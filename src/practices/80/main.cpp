#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int prevI = 0;
    
    int currC = 0;
    // int totalC = 0;
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0; i < (int)nums.size(); i++){
            if(nums[prevI] != nums[i]){
                prevI = i;
                
                currC = 0;
                
            }
            if(currC < 2){
                currC++;
                

            }else{
                while(nums[prevI] == nums[i] && i > prevI +1){
                    nums.erase(nums.begin()+i);
                    // i--;
                }
                
                currC = 0;
            }

        }
        return nums.size();
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int result = s.removeDuplicates(nums);
    
    // Output the result
    for(int i = 0; i < result; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}
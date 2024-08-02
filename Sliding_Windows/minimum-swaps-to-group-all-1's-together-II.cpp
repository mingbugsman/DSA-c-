#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count = 0;
        int totalOne = 0;
        for (int i : nums) {
            if (i == 1) totalOne+=i;
        }
        for (int i = 0; i < totalOne; i++) {
            nums.push_back(nums[i]);
        }
        int n = nums.size();
        int MaxTotalOne = 0;
        for (int i = 0; i < totalOne ; i++) {
            MaxTotalOne+=nums[i];
        }
        int current_one = MaxTotalOne;
        for (int i = 1; i <= n - totalOne ; i++) {
            cout << i << " " << MaxTotalOne << endl;
            current_one = current_one - nums[i-1] + nums[i+totalOne-1];
          
            MaxTotalOne = max(current_one,MaxTotalOne);
        }
         
        return totalOne - MaxTotalOne ; 
    }
};


int main()
{
    vector<int> v ={ 0,1,1,1,0,0,1,1,0};
    Solution slt;
    cout << slt.minSwaps(v);

    return 0;
}
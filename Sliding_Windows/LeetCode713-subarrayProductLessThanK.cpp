#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int count = 0;
        unsigned long long product = 1;

        for (int right = 0; right < n ; right++) {
            product*=nums[right];

            while (product >= k) {
                product/=nums[left];
                left++;
            }
            count+= (right - left + 1);
          //  cout << count << " ";
        } 
        return count;
    }
};

int main() {
    vector<int> v = {1,1,1,1,9,1,1,1,1,2,2,3,6};
    int target = 13;
    Solution slt;
    int ans = slt.numSubarrayProductLessThanK(v,target);
    cout << ans;
    return 0 ;
}
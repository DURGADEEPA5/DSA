/*
Brute Force : using div operator(not allowed).
-Multiply all the elements of the array and store it as mul.
-Create a temp vector
-Traverse the given array and for each element, divide mul by that element.

Better Approach : TC-O(n^2), SC-O(n) 
-use nested loops. gives TLE.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    ans[i] *= nums[j];
                }
            }
        }

        return ans;
    }
};

Optimized Approach-1 : TC-O(N), SC-O(2N)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        // Compute prefix products
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Compute suffix products
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Multiply prefix and suffix for final result
        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};

Optimized Approach-2 : TC-O(N), SC-O(1)
Instead of calculating separate prefix and suffix arrays, 
add it to the ans then and there itself.
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1);
        //prefix
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        //suffix
        int suffix=1;
        for(int i=n-2;i>=0;i--){
            suffix*=nums[i+1];
            ans[i]*=suffix;
        }
        return ans;
    }
};
int main(){
    vector<int>nums={1,2,3,4};
    Solution sol; // creating object
    vector<int>result = sol.productExceptSelf(nums);
    for(int x:result){
        cout<<x<<" ";
    }
    return 0;
}
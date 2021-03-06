#include<iostream>
#include<vector>

using namespace std;


// houses on a loop, no consecutive two houses can be robbed together.

class Solution{
public:
    int rob(vector<int> &nums){
        int n=nums.size();
        if (n<2) return n ? nums[0]: 0;
        
        // recursive solution to loop
        return max(robber(nums, 0, n-2), robber(nums, 1, n-1));
    }
private:
    int robber(vector<int>& nums, int l, int r){
        int pre=0, cur=0;
        for(int i=l; i<=r; i++){
            // recursively update max at cur and pre
            int temp = max(pre+nums[i], cur);
            pre=cur;
            cur=temp;
        }
        return cur;
    }
};

int main(){
    int input;
    vector<int> nums;
    cout<<"houses with cash(non-integer to stop):" << endl;
    while (cin>>input) {
        nums.push_back(input);
    }
    Solution m;
    int res = m.rob(nums);
    cout << "maximum cash can be robbed:" << res <<endl;
}

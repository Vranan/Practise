class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> myvec;
        
        
        int n = nums.size();
        if (n<4)
            return myvec;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n-3; i++) {
            
            if (i>0 && nums[i] == nums[i-1]) continue;
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            if (nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target) continue;
             
            for (int j = i+1; j < n-2; j++) {
                
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                if (nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
                if (nums[i]+nums[j]+nums[n-2]+nums[n-1] < target) continue;
                
                
                int l = j+1;
                int r = n - 1;
                
                
                while (r > l) {
                    int sum = nums[j] + nums[r] + nums[l] + nums[i];
                    
                    if (sum == target) {
                        vector<int> temp{nums[i], nums[j], nums[r], nums[l]};
                        myvec.push_back(temp);
                        do {l++; } while (nums[l] == nums[l-1] && r > l);
                        do {r--; } while (nums[r] == nums[r+1] && r > l);
                    } else if (sum > target) 
                        r--;
                    else if (sum < target)
                        l++;
                    
                        
                    
                }
            }
        }
        return myvec;
    }
};

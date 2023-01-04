class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        vector<int>storeF[n];
        
        int prev=0;
        int sum=0;
     for(int i=0;i<n;i++){
            prev+=i*nums[i];
        sum+=nums[i];
     }
     int maxAns=prev;
     int curr=0;
     for(int i=1;i<n;i++){
         curr=0;
         int lastElement=nums[n-i];
         curr=prev+sum-(n)*lastElement;
         maxAns=max(curr,maxAns);
         prev=curr;
     }
     return maxAns;

    }
};

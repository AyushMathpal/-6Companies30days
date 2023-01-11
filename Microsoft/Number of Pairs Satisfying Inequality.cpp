
//https://leetcode.com/problems/number-of-pairs-satisfying-inequality/


#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <iostream> 
using namespace __gnu_pbds; 
using namespace std; 
class Solution {
public:
  typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, 
            tree_order_statistics_node_update> 
    ordered_set; 
    long long f(vector<long long>& vt,  long long n, long long k)
{
     long long count=0;
         ordered_set mySet;
        for(long long i=0;i<n;++i){
           
           
            count+=mySet.order_of_key({vt[i]+k,INT_MAX});
              mySet.insert({vt[i],i});  
        }
 
    return count;
}

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<long long>differ;
        for(int i=0;i<nums1.size();i++){
            differ.push_back(nums1[i]-nums2[i]);
        }
        return f(differ,differ.size(),diff);

    }
};

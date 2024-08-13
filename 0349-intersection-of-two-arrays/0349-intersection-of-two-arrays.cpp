class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0;
        int j=0;
        vector<int> arr;
        while(i<n && j<m){
            if(nums1[i]>nums2[j]){
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                if (arr.empty() || arr.back() != nums1[i]) {
                    arr.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return arr;
    }
};
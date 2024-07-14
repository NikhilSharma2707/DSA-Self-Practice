class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n=arr.size();
        int ans=n;
        int low=0, high=n-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i=0;
        int n=arr.size();
        if(arr.size()==0){
            return 0;
        }
        for(int j=1; j<n; j++){
            if(arr[j]!=arr[i]){
                i++;
                arr[i]=arr[j];
                
            }


        }
        return i+1;
        
    }
};
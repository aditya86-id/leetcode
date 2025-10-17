class Solution {
public:
    int search(vector<int>& nums, int target) {
    int len=nums.size();
    int right=len-1,left = 0;
    

     while(left<=right){
        int mid = (left+right)/2;

        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>=nums[left]){
            if(nums[left]<=target && target<=nums[mid]){
                right = mid-1;
            }
            else{
                left = mid+1;
            }

        }
        else{
            if(nums[mid]<=target&&target<=nums[right]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
     }
        return -1;
    }
};
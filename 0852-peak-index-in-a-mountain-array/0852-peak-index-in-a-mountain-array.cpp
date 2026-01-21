class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //for the calculated mid element, we check if it has increasing slope, decreasing slope or its a peak
        int low = 0;
        int high = arr.size()-1;
        int mid;
        while (high>=low){
            mid = low + (high-low)/2;
            //edge cases because middle can never be the extreme ends
            if (mid==0){
                low+=1;
                continue;
            }
            if (mid==arr.size()-1){
                high-=1;
                continue;
            }
            if (arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) return mid; //satisfies condition for mountain peak
            else if (arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]) low = mid+1; //this means we are still climbing the mountain
            else high=mid-1;
        }
        return -1;
    }
};
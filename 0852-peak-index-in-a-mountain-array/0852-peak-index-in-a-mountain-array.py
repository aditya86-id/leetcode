class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        begin, end = 0, len(arr) - 1
        while begin <= end:
            mid = (begin + end) // 2
            if arr[mid-1] < arr[mid] > arr[mid+1]:
                return mid
            elif arr[mid-1] < arr[mid]:
                begin = mid + 1
            else:
                end = mid  
        return -1
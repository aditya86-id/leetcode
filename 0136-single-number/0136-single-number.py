class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums=Counter(nums)
        return list(filter(lambda x:nums[x] == 1,nums))[0]
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numsets=set(nums)
        longest=0
        for n in nums:
            if (n-1) not in numsets:
                length=0
                while(n+length) in numsets:
                    length+=1
                longest=max(length,longest)
        return longest
        
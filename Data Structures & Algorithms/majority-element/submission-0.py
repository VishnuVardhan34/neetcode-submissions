import random
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        while True:
            c = random.choice(nums)
            if nums.count(c) > n // 2:
                return c

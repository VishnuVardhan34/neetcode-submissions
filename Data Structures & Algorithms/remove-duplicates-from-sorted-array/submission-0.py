class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 1 # as the array is sorted there is no use of using the hashmap to store the index ordered frequencies
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                nums[k] = nums[i]
                k += 1
        return k

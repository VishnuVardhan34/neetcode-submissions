class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        hashmap = {}
        result = []
        for item in nums:
            hashmap[item] = hashmap.get(item, 0) + 1
        
        for key in hashmap:
            if hashmap[key] > len(nums) // 3:
                result.append(key)

        return result
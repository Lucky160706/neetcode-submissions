class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashmap = {}
        for num in nums:
            if num not in hashmap:
                hashmap[num] = 0
            hashmap[num] += 1
        
        buckets = [[] for _ in range(len(nums) + 1)]

        for key, freq in hashmap.items():
            buckets[freq].append(key)
        
        ans = []
        print(buckets)
        for i in range(len(buckets) - 1, 0, -1):
            for num in buckets[i]:
                ans.append(num)
                if len(ans) == k:
                    return ans
        
        return ans
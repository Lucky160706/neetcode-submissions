class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = {}
        ans = []

        for str in strs:
            sorted_str = ''.join(sorted(str))
            if sorted_str not in hashmap:
                hashmap[sorted_str] = []
            hashmap[sorted_str].append(str)
        
        for value in hashmap.values():
            ans.append(value)
        
        return ans
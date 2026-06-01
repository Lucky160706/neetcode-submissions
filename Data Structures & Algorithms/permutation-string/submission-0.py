class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        
        arr = list(s2)
        sorted_s1 = sorted(s1)
        # print(arr)

        for i in range(len(s2) - len(s1) + 1):
            sub_str = ''.join(arr[i : i + len(s1)])
            # print(sub_str, "\n")
            if sorted(sub_str) == sorted_s1:
                return True
        return False


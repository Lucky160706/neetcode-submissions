class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)

        min_k = 0

        while l <= r:
            k = (l + r) // 2
            total_hours = 0
            for pile in piles:
                total_hours += math.ceil(pile / k)
            if total_hours <= h:
                r = k - 1
                min_k = k
            else:
                l = k + 1
        return min_k
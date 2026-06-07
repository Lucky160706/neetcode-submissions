class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        sort_people = sorted(people)
        l, r = 0, len(people) - 1
        ans = 0
        while l <= r:
            ans += 1
            if sort_people[l] + sort_people[r] > limit:
                r -= 1
            else:
                r -= 1
                l += 1
        return ans
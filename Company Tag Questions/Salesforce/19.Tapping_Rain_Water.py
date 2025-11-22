#  this is the solution that uses the O(N) time and O(2*N) space which is equivelent 
#  to the O(N) only.

class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        leftMax = [0]*n
        rightMax = [0]*n
        ans = 0
        for i in range(1, n):
            leftMax[i] = max(leftMax[i-1], max(height[i], height[i-1]))
            rightMax[n-i-1] = max(rightMax[n-i], height[n-i])
        for i in range(0, n):
            diff = min(leftMax[i], rightMax[i]) - height[i]
            ans += 0 if diff < 0 else diff
        return ans

# Now let us focus on the O(N) time and O(1) space complexity solution.

class Solution:
    def trap(self, height: List[int]) -> int:
        l, r = 0, len(height)-1
        leftMax, rightMax = height[l], height[r]
        ans = 0
        while l < r:
            if leftMax < rightMax:
                l += 1
                leftMax = max(leftMax, height[l])
                ans += leftMax - height[l]
            else:
                r -= 1
                rightMax = max(rightMax, height[r])
                ans += rightMax - height[r]

        return ans
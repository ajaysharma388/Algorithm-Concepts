# cook your dish here
class Solution:
    def nextPermutation(self, arr):
        r = len(arr)-1
        # basically I am looking for a number which is lesser 
        # then it's right number while scanning the array in the reverse direction.
        while r > 0:
            if arr[r] > arr[r-1]:  
                break
            else:
                r -= 1
        r -= 1
        if r >= 0:
            for i in range(len(arr)-1, r, -1):
                if arr[i] > arr[r]:
                    arr[i], arr[r] = arr[r], arr[i]
                    break;
            res = [] 
            for i in range(r + 1):
                res.append(arr[i])
            for i in range(len(arr)-1, r, -1):
                res.append(arr[i])
            for i in range(len(arr)):
                arr[i] = res[i]
            return
        arr.reverse()
            

def main():
    lst = [[2, 4, 1, 7, 5, 0], [3, 2, 1], [3, 4, 2, 5, 1], [1, 2, 4, 6, 5, 3]]
    s = Solution()
    for arr in lst:
        s.nextPermutation(arr)
        print(arr)

if __name__ == '__main__':
    main()
    
# Sample Output:
# [2, 4, 5, 0, 1, 7]
# [1, 2, 3]
# [3, 4, 5, 1, 2]
# [1, 2, 5, 3, 4, 6]
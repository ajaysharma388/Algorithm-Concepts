from sortedcontainers import SortedSet

class Helper:
    def __init__(self, x: int):
        self.x = x
        self.result = 0
        self.large = SortedSet()
        self.small = SortedSet()
        self.freq_map = dict()

    def __compare(self, num: int, occ: int) -> bool:
        cur_head = next(iter(self.large))
        return (occ, num) >= cur_head
        
    def __internal_insert(self, num: int, occ: int):
        if len(self.large) < self.x or self.__compare(num, occ):
            self.result += num * occ
            self.large.add((occ, num))
            while len(self.large) > self.x:
                cur_head = self.large[0]
                self.large.discard(cur_head)
                self.result -= int(cur_head[0] * cur_head[1])
                self.small.add(cur_head)
        else:
            self.small.add((occ, num))
    
    def __compare_2(self, num: int, occ: int) -> bool:
        cur_head = next(iter(self.large))
        return (occ, num) >= cur_head

    def __internal_remove(self, num: int, occ: int):
        if self.__compare_2(num, occ):
            self.result -= int(num*occ)
            self.large.discard((occ, num))
            if len(self.small):
                last_element = list(self.small)[-1]
                self.result += int(last_element[0]*last_element[1])
                self.small.discard(last_element)
                self.large.add(last_element)
        else:
            self.small.discard((occ, num))
        
    def get(self):
        return self.result

    def serialize(self):
        print(self.large)
        print(self.small)
        print("*"*20)

    def insert(self, num: int):
        # if the number is already in the data set 
        # we have to first update and modify it value 
        # then we have to re-insert the information.
        if num in self.freq_map:
            self.__internal_remove(num, self.freq_map[num])
        else:
            self.freq_map[num] = 0
        # self.serialize()
        self.freq_map[num] += 1
        self.__internal_insert(num, self.freq_map[num])
        
    def remove(self, num: int):
        # if the number is already in the data set 
        # we have to first update and modify it value 
        # then we have to re-insert the information.
        self.__internal_remove(num, self.freq_map[num])
        self.freq_map[num] -= 1
        if self.freq_map[num]:
            self.__internal_insert(num, self.freq_map[num])
        
class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        helper = Helper(x)
        n, res = len(nums), list()
        for i in range(0, n):
            helper.insert(nums[i])
            if i >= k:
                helper.remove(nums[i - k])
            if i >= k - 1:
                res.append(helper.get())
        return res
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        nbr = collections.defaultdict(list)
        wordList.append(beginWord)
        for word in wordList:
            for i in range(len(word)):
                pat = word[:i] + "*" + word[i+1:]
                nbr[pat].append(word)

        res = 1
        vis = set([beginWord])
        q = deque([beginWord])
        while q:
            for _ in range(len(q)):
                word = q.popleft()
                if word == endWord:
                    return res
                for i in range(len(word)):
                    pat = word[:i] + "*" + word[i+1:]
                    for neighbour in nbr[pat]:
                        if neighbour not in vis:
                            vis.add(neighbour)
                            q.append(neighbour)
            res += 1
        return 0


    def ladderLength_II(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList or beginWord == endWord:
            return 0

        words, res = set(wordList), 1
        q = deque([beginWord])
        while q:
            for _ in range(len(q)):
                word = q.popleft()
                if word == endWord:
                    return res
                for i in range(len(word)):
                    for j in range(97, 123):
                        if word[i] == chr(j):
                            continue
                        nbr = word[:i] + chr(j) + word[i+1:]
                        if nbr in words:
                            words.remove(nbr)
                            q.append(nbr)
            res += 1
        return 0
        
















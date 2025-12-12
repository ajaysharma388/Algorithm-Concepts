def main() -> int:
    n, k = map(int, input().split(" "))
    s = input()
    res, i, j = 0, 0, 0
    while i < n:
        if s[i] == '0':
            res = max(res, res+1)
            i += 1
            continue
        while i < n and s[i] == '1':
            i += 1
        i += k
    return res
        
if __name__ == "__main__":
    k = int(input())
    while k:
	    print(main())
	    k -= 1
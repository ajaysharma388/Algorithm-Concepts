def transform(A, B):
    if len(A) != len(B):
        return -1
    
    # create a dictionary to store the frequency of characters in string A
    m = {}
    n = len(A)
    for i in range(n):
        if A[i] in m:   # if the character already exists in the dictionary
            m[A[i]] += 1  # increment its frequency
        else:
            m[A[i]] = 1   # add the character to the dictionary with a frequency of 1
    
    # subtract the frequency of characters in string B from the dictionary
    for i in range(n):
        if B[i] in m:
            m[B[i]] -= 1
    
    # check if all the frequencies in the dictionary are 0, indicating equal frequency of characters in both strings
    for key in m:
        if m[key] != 0:  # if frequency is not zero
            return -1     # strings cannot be transformed into each other, return -1
    
    # calculate the minimum number of operations required to transform string A into string B
    i, j = n-1, n-1
    res = 0
    while i >= 0 and j >= 0:
        while i >= 0 and A[i] != B[j]:
            res += 1  # increment the number of operations required
            i -= 1    # move the pointer i to the left
        i -= 1
        j -= 1
    
    return res  # returning result

# Driver code
A = "EACBD"
B = "EABCD"
print("Minimum number of operations required is", transform(A, B))
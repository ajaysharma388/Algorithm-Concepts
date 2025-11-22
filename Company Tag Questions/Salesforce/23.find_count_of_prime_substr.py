def countPrimeSubstrings(S):
    MAX = 10**6
    
    # Step 1: Sieve of Eratosthenes
    is_prime = [True] * (MAX+1)
    is_prime[0] = is_prime[1] = False
    for p in range(2, int(MAX**0.5)+1):
        if is_prime[p]:
            for multiple in range(p*p, MAX+1, p):
                is_prime[multiple] = False
    prime_set = {i for i in range(MAX+1) if is_prime[i]}
    
    # Step 2: Count prime substrings
    n = len(S)
    count = 0
    for i in range(n):
        num = 0
        for j in range(i, min(i+6, n)):
            num = num*10 + int(S[j])  # build number incrementally
            if num in prime_set:
                count += 1
    return count
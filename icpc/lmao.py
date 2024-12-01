from itertools import combinations
from functools import reduce

def solve():
    t = int(input())  # Number of test cases
    
    results = []
    for _ in range(t):
        n, k = map(int, input().split())  # Length of array and target K
        arr = list(map(int, input().split()))  # Array elements
        
        # Filter array to only keep elements that could form a valid subset
        valid_indices = [i for i, x in enumerate(arr) if (x & k) == k]
        valid_numbers = [arr[i] for i in valid_indices]
        
        found = False
        # Enumerate all non-empty subsets of valid_numbers
        for size in range(1, len(valid_numbers) + 1):
            for subset_indices in combinations(range(len(valid_numbers)), size):
                subset = [valid_numbers[i] for i in subset_indices]
                if reduce(lambda x, y: x & y, subset) == k:
                    found = True
                    results.append("YES")
                    results.append(str(len(subset)))
                    results.append(" ".join(str(valid_indices[i] + 1) for i in subset_indices))
                    break
            if found:
                break
        if not found:
            results.append("NO")
    
    # Output results
    print("\n".join(results))


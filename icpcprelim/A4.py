from bisect import insort
from sys import stdin, stdout

def solve():
    n, m = map(int, stdin.readline().split())
    A = [0] + list(map(int, stdin.readline().split()))

    A.sort()
    pf = [0] * (n + 1)
    for i in range(1, n + 1):
        pf[i] = pf[i - 1] + A[i]

    answer = [0] * (n + 1)

    for i in range(m):
        answer[i] = pf[i]

    for r in range(m, n + 1):
        l = r - m
        discount = pf[r - 1] - pf[l]
        if (r - 1) % m == 0:
            discount = pf[r - 1] - pf[l]
            answer[r] = answer[l - 1] + A[r] + discount
        else:
            answer[r] = answer[r - 1] + A[r]

    stdout.write(" ".join(map(str, answer[1:])) + "\n")

def main():
    t = int(stdin.readline())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
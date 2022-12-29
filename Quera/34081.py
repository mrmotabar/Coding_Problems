from math import gcd
n, k = list(map(int, input().split()))
print(int(n / gcd(n, k)))

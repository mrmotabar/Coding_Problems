import math
n, k = input().split()
n = int(n)
k = int(k)
for i in range(k):
    n /= 2
print(math.floor(n))

n, k = list(map(int, input().split()))
summ = 0
for i in range(n):
    summ += int(input())
if (summ >= k):
    print("YES")
else:
    print("NO")

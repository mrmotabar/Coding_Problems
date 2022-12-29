from math import floor
n = int(input())
cnt = 0
summ = 0
for i in range(1, n + 1):
    cnt += floor(n / i)
    summ += floor(n / i) * i
print(cnt, summ)

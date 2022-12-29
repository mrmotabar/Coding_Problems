n = int(input())
l = list(map(int, input().split()))
maxx = 0
for i in range(1, n):
    if (l[i] > l[maxx]):
        maxx = i
print(maxx + 1)

n = int(input())

l = [100, 20, 10, 5, 1]
ans = 0

for i in l:
    ans += n // i
    n %= i
    
print(ans)
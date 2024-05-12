
n, k = input().split()
k = int(k)

while(k > 0):
    # print(n)
    if n[-1] == '0':
        n = n[0: -1]
    else:
        n = n[0: -1] + chr(ord(n[-1]) - 1)
    k -= 1

print(n)
        
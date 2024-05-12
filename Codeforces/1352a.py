t = int(input())

while t > 0:
    n = input()
    ans = []
    for i in range(len(n)):
        if n[i] != '0':
            ans .append(int(n[i]) * 10**(len(n) - i - 1))
    print(len(ans))
    for i in ans:
        print(i, end = ' ')
    print()
    t -=1
t = int(input())

while t > 0:
    a, b = list(map(int, input().split()))
    print((b - (a % b)) % b)
    t -= 1
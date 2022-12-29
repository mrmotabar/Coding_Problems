s = input()
g = 0
r = 0
y = 0
for i in s:
    if (i == 'G'):
        g += 1
    if (i == 'R'):
        r += 1
    if (i == 'Y'):
        y += 1
if (g == 0 or (r >= 2 and y >= 2) or r >= 3):
    print("nakhor lite")
else:
    print("rahat baash")

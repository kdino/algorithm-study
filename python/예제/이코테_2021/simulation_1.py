N = int(input())
plan = input().split()

x = y = 1
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for i in plan:
    if i == 'R':
        n = 0
    elif i == 'L':
        n = 1
    elif i == 'D':
        n = 2
    else:
        n = 3

    nx = x + dx[n]
    ny = y + dy[n]

    if nx < 1 or ny < 1 or N < nx or N < ny:
        continue
    else:
        x = nx
        y = ny

print(f"{y} {x}")
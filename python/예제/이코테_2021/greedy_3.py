n = int(input())
people = list(map(int, input().split()))

people.sort()

ans = 0
cnt = 0

for i in people:
    cnt += 1
    if cnt == i:
        ans += 1
        cnt = 0

print(ans)
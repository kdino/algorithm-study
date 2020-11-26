a = [1,2,3,4,5,6]
a.insert(2, 9)
a.reverse
print(a)

b = [i for i in range(10)]
print(b)

n=4
m=3
c = [[0]*m for _ in range(n)]
print(c)

removeSet = {3, 5}
d = [i for i in a if i not in removeSet]
print(d)


# input format
"""
5
1 2 3 4 5
"""

n = int(input())
mylist = list(map(int, input().split()))

print(n)
print(mylist)

# for faster input
"""
1 2 3 4 5
"""
import sys
data = sys.stdin.readline().rstrip()
print(data)
print()

# std output
print("Kidong", "Lee", end=" ")
print("Hello")
lastName = "Lee"
print(f"kidong {lastName}")
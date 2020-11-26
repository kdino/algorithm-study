# dictionary
data = dict()

data['1'] = "apple"
data['2'] = "pear"

print(data['1'])
print(data.keys())
print(data.values())
print(list(data.keys()))

data2 = {
    '1': "apple",
    '2': "pear"
}
print(data2)
print("\n")

# set
mySet = {1,2,3,4,5}
mySet2 = set([1,2,3,4,5])

mySet.add(6)
mySet.remove(4)
mySet.update([6,8,9])

print(mySet)

print(mySet.intersection({1}))
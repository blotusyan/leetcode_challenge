list_1 = [[1,3],[0,7]]
#list_1.sorted(reverse=True)
#print(list_1)

list_2 = sorted(list_1, key = lambda x : x[0])
print(list_2)
print(list_1)
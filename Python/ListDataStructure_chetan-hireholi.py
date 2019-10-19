# This is an example of simple list implementation

# Create a list
shoplist = ['apple', 'mango', 'carrot', 'banana']

# Printing a length of the list
print('I have', len(shoplist), 'items to purchase.')

# Printing the entire list
print('These items are:', end=' ')
for item in shoplist:
    print(item, end=' ')

print('\nI also have to buy rice.')

# Appending an item in a list
shoplist.append('rice')

print('My shopping list is now', shoplist)

print('I will sort my list now')

# Sorting the list
shoplist.sort()

print('Sorted shopping list is', shoplist)

print('The first item I will buy is', shoplist[0])
olditem = shoplist[0]

# Removing an item from the list
del shoplist[0]
print('I bought the', olditem)

print('My shopping list is now', shoplist)

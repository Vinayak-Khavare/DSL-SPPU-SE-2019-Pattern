# neha maam
# written by Vinayak

# a) Write a Python program to store names and mobile numbers of your friends in sorted order on names. Search your friend from list using 
# binary search (recursive and nonrecursive). Insert friend if not present in phonebook b) Write a Python program to store names and mobile 
# numbers of your friends in sorted order on names. Search your friend from list using Fibonacci search. Insert friend if not present in
# phonebook.


# nonrecursive
# def Binsearch(names_of_people, item):
#     names_of_people.sort()
#     l = len(names_of_people)
#     index = -1
#     start = 0
#     end = l
#     while(start<=end):
#         mid = (start+end)//2
#         if(item == (names_of_people[mid])):
#             index = mid
#             return index
#         elif(item > (names_of_people[mid])):
#             start = mid+1
#         else:
#             end = mid
            
            
# recursive
def Binsearch(names_of_people, item, low, high):
    names_of_people.sort()
    index = -1
    mid = (low+high)//2
    if(item==names_of_people[mid]):
        index = mid
        return index
    elif(item > (names_of_people[mid])):
        low = mid+1
        return Binsearch(names_of_people, item, low, high)
    else:
        high = mid
        return Binsearch(names_of_people, item, low, high)
    
            
Phone_book = {}
n = int(input("Enter number of people you want to add to phonebook: "))

print("\nEnter names in sorted order, ")
names = []
for i in range(n):
    name = input("Enter name of the person: ")
    number = int(input("Enter phone number of the person: "))
    Phone_book[name] = number 
    names.append(name)
# names.sort()
# print(Phone_book)
# print(names)

x = input("\nEnter the name you want to search: ")
result = Binsearch(names, x, 0, n)
# print(result)

if(result==-1):
    names.append(x)
    print("The person you are searching is not saved in the phonebook.")
    choice = input("Do you want to add him to phone book(Y/N)?")
    if(choice=="y" or choice=="Y"):
        number = int(input("Enter the phone number: "))
        Phone_book[name]=number
    else:
        pass
else:
    print("The person is present in phonebook.")
    
print("\nPhonebook, ")
for i in Phone_book:
    print(i, ":", Phone_book[i])
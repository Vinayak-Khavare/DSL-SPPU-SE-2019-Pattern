# neha maam
# written by Vinayak

# b) Write a Python program to store names and mobile numbers of your friends in sorted order on names. Search your friend from list using 
# Fibonacci search. Insert friend if not present in phonebook.

def fibsearch(list_of_names, item):
    list_of_names.sort()
    length = len(list_of_names)
    f0 = 0
    f1 = 1
    f2 = 1
    while(f2<length):
        f0 = f1
        f1 = f2
        f2 = f0 + f1
        
    offset = -1
    while(f2>0):
        index = min(offset + f0, length-1)
        if(item == list_of_names[index]):
            return index
        elif(item > list_of_names[index]):
            f2 = f1
            f1 = f0
            f0 = f2 - f1
            offset = index 
        else:
            f2 = f0
            f1 = f1 - f0
            f0 = f2 - f1
    return -1

    
Phone_book = {}
n = int(input("Enter number of people you want to add to phonebook: "))

print("\nEnter names in sorted order, ")
names = []
for i in range(n):
    name = input("Enter name of the person: ")
    number = int(input("Enter phone number of the person: "))
    Phone_book[name] = number 
    names.append(name)


x = input("\nEnter the name you want to search: ")
result = fibsearch(names, x)
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
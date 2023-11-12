# sumedh sir
# written by vinayak

# Write a Python program to store first year percentage of students in array. Write function for sorting array of floating point numbers 
# in ascending order using a) Selection Sort b) Bubble sort and display top five scores.


# selection sort
def selsort(a):
    l = len(a)
    for i in range(l):
        m = i
        for j in range(i+1, l):
            if(a[j]<a[m]):
                m=j
        if(m!=i):
            a[i], a[m] = a[m], a[i]
    return a

# bubble sort
def bubblesort(a):
    l = len(a)
    for i in range(l):
        flag = 0
        for j in range(l-1):
            if(a[j]>a[j+1]):
                a[j], a[j+1] = a[j+1], a[j]
                flag = 1
        if(flag==0):
            break
    return a


n = int(input("Enter no of students in first year: "))
lst = []
for i in range(n):
    print("Student", i+1, end = "")
    pt = float(input(", Enter percentage obtained: "))
    lst.append(pt)
# print(lst)

result = bubblesort(lst)
# print(result)

print("\nTop 5 Scores are, ")
c=0
for _ in result[::-1]:
    if(c==5):
        break
    else:
        c+=1
        print(_, end = " ")

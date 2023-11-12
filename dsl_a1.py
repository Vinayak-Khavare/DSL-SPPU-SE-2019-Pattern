# neha maam
# written by vinayak

# In second year computer engineering class, group A student’s play cricket, group B students play badminton and group C students play
# football. Write a Python program using functions to compute following: - a) List of students who play both cricket and badminton 
# b) List of students who play either cricket or badminton but not both c) Number of students who play neither cricket nor badminton 
# d) Number of students who play cricket and football but not badminton. (Note- While realizing the group, duplicate entries should 
# be avoided, Do not use SET built-in functions)

students = list(map(str, input("Enter the name of all the students: ").split())) #list of all the students

# group A
cricket = list(map(str, input("Enter the name of students that play cricket: ").split())) #list of cricket playing students
# group B
badminton = list(map(str, input("Enter the name of students that play badminton: ").split())) #list of badminton playing students
# group C
football = list(map(str, input("Enter the name of students that play football: ").split())) #list of football playing students


# 1. both cricket and badminton
lst1=[]
for i in students:
    if (i in cricket)and(i in badminton):
        lst1.append(i)
        # print(i, end=" ")
print("list of students that play both cricket and badminton: ",lst1)


# 2. either cricket or badminton but not both
lst2=[]
for i in students:
    if (i in cricket)and(i in badminton):
        continue
    elif i in football:
        continue
    else:
        lst2.append(i)
        # print(i, end=" ")
print("list of students that play either cricket or badminton but not both: ",lst2)


# 3. niether cricket nor badminton count
c=0
for i in students:
    if i in cricket:
        continue
    elif i in badminton:
        continue
    else:
        c+=1
print(c,"is the count of students that play niether cricket nor badminton.")


# 4. count plays football and cricket but not badminton
c=0
for i in students:
    if (i in cricket)and(i in football):
        if i in badminton:
            continue
        else:
            c+=1
print(c,"is the count of students that play football and cricket but not badminton.")

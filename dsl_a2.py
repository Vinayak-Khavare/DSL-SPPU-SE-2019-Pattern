# sumedh sir
# written by vinayak

# Write a Python program to store marks scored in subject “Fundamental of Data Structure” by N students in the class. Write functions to 
# compute following: a) The average score of class b) Highest score and lowest score of class c) Count of students who were absent for the 
# test d) Display mark with highest frequency

# entering marks
def score(marks):
    # n = len(marks)
    n = int(input("enter the no of students that wrote the exams: "))
    for i in range(n):
        r, mark = map(int, input("enter roll no and mark of the student: ").split())
        marks[r-1]=mark
    return marks

# avg score
def avgscore(marks):
    n = len(marks)
    s=0
    for i in range(n):
        if marks[i]!="ab":
            s+=marks[i]
    return (s/n)


# min score
def minscore(marks):
    n = len(marks)
    min = marks[0]
    for i in range(n):
        if marks[i]!="ab":
            if marks[i]<min:
                min = marks[i]
    return min


# max score
def maxscore(marks):
    n = len(marks)
    max = marks[0]
    for i in range(n):
        if marks[i]!="ab":
            if marks[i]>max:
                max = marks[i]
    return max


# students that were absent for test
def absent(marks):
    n = len(marks)
    c=0
    for i in range(n):
        if marks[i]=="ab":
            c+=1
    return c 


# score with max frequency
def freqscore(marks):
    n = len(marks)
    lst=[]
    for i in range(n):
        if marks[i]!="ab":
            f = marks.count(i)
            lst.append(f)
    return max(lst)


# main
if __name__=="__main__":
    n = int(input("Enter no of students: "))

    marks = []

    # initializing the list of scores
    for i in range(n):
        marks.append("ab")

    marks = score(marks)
    print("the average score of class is: ", avgscore(marks))
    print("the maximum and minimun score of the class is ", maxscore(marks), "and", minscore(marks), "respectively.")
    print("the count of absent students is: ", absent(marks))
    print("marks with highest frequency is: ", freqscore(marks))
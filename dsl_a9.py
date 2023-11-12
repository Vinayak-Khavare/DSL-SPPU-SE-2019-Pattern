# sumedh sir
# written by vinayak

# Write a Python program to compute following computation on matrix: a) Addition of two matrices B) Subtraction of two matrices 
# c) Multiplication of two matrices d) Transpose of a matrix

# sqaure matrix
def matrix():
    matrix = []

    n, m = map(int, input("enter no of rows and columns: ").split())
    for i in range(n):
        a=[]
        for j in range(m):
            print("Enter element at position [",i+1,"][",j+1,"]")
            e = int(input())
            a.append(e)
        matrix.append(a)

    # for i in range(n):
    #     print("Enter the elements of row", i+1,": ")
    #     a = list(map(int, input("").split()))
    #     matrix.append(a)
    
    return matrix


# addition of two matrices
def addmatrix(m1, m2):
    m3=[]
    n=len(m1)
    m=len(m1[0])
    for i in range(n):
        a=[]
        for j in range(m):
            s = m1[i][j]+m2[i][j]
            a.append(s)
        m3.append(a)
    return m3
    
    
# subtraction of two matices
def submatrix(m1, m2):
    m3=[]
    n=len(m1)
    m=len(m1[0])
    for i in range(n):
        a=[]
        for j in range(m):
            s = m1[i][j]-m2[i][j]
            a.append(s)
        m3.append(a)
    return m3


# multiplication of two matrices
def mulmatrix(m1, m2):
    m3=[]
    n=len(m1)
    for i in range(n):
        a=[]
        for j in range(n):
            s=0
            for k in range(n):
                s+=m1[i][k]*m2[k][j]
            a.append(s)
        m3.append(a)
    return m3


# transpose of matrix
def tranpose(matrix):
    n=len(matrix)
    # m=len(matrix[0])
    temp = [[0 for i in range(n)]for j in range(n)]
    for i in range(n):
        for j in range(n):
            temp[j][i]+=matrix[i][j]
    return temp


if __name__=="__main__":
    print("for matrix 1")
    m1 = matrix()
    
        
    print("\nfor matrix 2")
    m2 = matrix()
    
    print("Matrix 1 is,")
    for i in m1:
        print(i)
        
    print("matrix 2 is,")    
    for i in m2:
        print(i)
    
    print("\nafter adding matrix1 and matrix2:")
    result=addmatrix(m1,m2)
    for i in result:
        print(i)
        
    print("\nafter subtracting matrix2 from matrix1:")
    result=submatrix(m1,m2)
    for i in result:
        print(i)
    
    print("\nafter multiplying matrix1 and matrix2:")
    result=mulmatrix(m1,m2)
    for i in result:
        print(i)
    
    print("\ntranspose of matrix1 is: ")
    result = tranpose(m1)
    for i in result:
        print(i)
        
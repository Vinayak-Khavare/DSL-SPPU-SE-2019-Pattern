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
            print("Enter element at position (",i+1,j+1,")",end=': ')
            e = int(input())
            a.append(e)
        matrix.append(a)

    # for i in range(n):
    #     print("Enter the elements of row", i+1,": ")
    #     a = list(map(int, input("").split()))
    #     matrix.append(a)
    
    return matrix


# addition of two matrices
def addmatrix(mat1, mat2):
    mat3=[]
    n1=len(mat1)
    m1=len(mat1[0])
    n2 = len(mat2)
    m2 = len(mat2[0])
    if(n1==n2 and m1==m2):
        for i in range(n1):
            a=[]
            for j in range(m1):
                s = mat1[i][j]+mat2[i][j]
                a.append(s)
            mat3.append(a)
        return mat3
    else:
        print("Not suitable for addition")
        return -1
    
    
# subtraction of two matices
def submatrix(mat1, mat2):
    mat3=[]
    n1=len(mat1)
    m1=len(mat1[0])
    n2 = len(mat2)
    m2 = len(mat2[0])
    if(n1==n2 and m1==m2):
        for i in range(n1):
            a=[]
            for j in range(m1):
                s = mat1[i][j]-mat2[i][j]
                a.append(s)
            mat3.append(a)
        return mat3
    else:
        print("Not suitable for subtraction")
        return -1


# multiplication of two matrices
def mulmatrix(mat1, mat2):
    mat3=[]
    n1 = len(mat1)
    m1 = len(mat1[0])
    n2 = len(mat2)
    m2 = len(mat2[0])
    if(m1==n2):
        for i in range(n1):
            a=[]
            for j in range(m2):
                s=0
                for k in range(m2):
                    s+=mat1[i][k]*mat2[k][j]
                a.append(s)
            mat3.append(a)
    else:
        print("Not suitable for multiplication")
        return -1
    return mat3


# transpose of matrix
def tranpose(matrix):
    n=len(matrix)
    m=len(matrix[0])
    temp = [[0 for i in range(n)]for j in range(m)]
    for i in range(n):
        for j in range(m):
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
    if(result!=-1):
        for i in result:
            print(i)
        
    print("\nafter subtracting matrix2 from matrix1:")
    result=submatrix(m1,m2)
    if(result!=-1):
        for i in result:
            print(i)
    
    print("\nafter multiplying matrix1 and matrix2:")
    res=mulmatrix(m1,m2)
    if(res!=-1):
        for i in res:
            print(i) 
    
    print("\ntranspose of matrix1 is: ")
    result = tranpose(m1)
    for i in result:
        print(i)
        
    print("\ntranspose of matrix2 is: ")
    result = tranpose(m2)
    for i in result:
        print(i)
        
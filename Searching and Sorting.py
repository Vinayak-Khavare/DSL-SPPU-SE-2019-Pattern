# linear search
def linsearch(arr, n, key):
    for i in range(n):
        if(arr[i]==key):
            return i
    return -1

# sentinel search
def sensearch(arr, n, key):
    last = arr[n-1]
    arr[n-1] = key
    i=0
    while(arr[i]!=key):
        i+=1
    arr[n-1]=last
    if(i<(n-1) or arr[n-1]==key):
        return i
    else:
        return -1
    
# binary search non recursive
# def binsearch(arr, n, key):
#     start = 0
#     end = n
#     index = -1
#     while(start<=end):
#         mid = (start+end)//2
#         if(arr[mid]<key):
#             start = mid+1
#         elif(arr[mid]>key):
#             end = mid-1
#         else:
#             index = mid
#             return index
#     return index

# binary search recursive
def binsearch(arr, low, high, key):
    if(low>=high):
        mid = (low + high)//2
        if(arr[mid]>key):
            return binsearch(arr, low, mid-1, key)
        elif(arr[mid]<key):
            return binsearch(arr, mid+1, high, key)
        else:
            return mid
    else:
        return -1
    
# fibonacci search
def fibsearch(arr, n, key):
    fib1=0
    fib2=1
    fib3=fib1 + fib2
    while(fib3<n):
        fib1=fib2
        fib2=fib3
        fib3=fib1+fib2
    offset = -1
    while(fib3>1):
        i = min(fib2 + offset, n-1)
        if(arr[i]<key): #right shift
            fib3=fib2
            fib2=fib1
            fib1=fib3-fib2
            offset = i
        elif(arr[i]>key): #left shift
            fib3=fib1
            fib2=fib2-fib1
            fib1=fib3-fib2
        else:
            return i
    if(fib2==1 and arr[offset+1]==key):
        return offset+1
    else:
        return -1
    
# bubble sort
def bubsort(arr, n):
    flag = 1
    for i in range(n):
        for j in range(n-1):
            if(arr[j]>arr[j+1]):
                arr[j], arr[j+1] = arr[j+1], arr[j]
                flag = 0
        if(flag==1):
            break
    return arr
        
# selection sort
def selsort(arr, n):
    for i in range(n):
        m = i
        for j in range(i, n):
            if(arr[j]<arr[m]):
                m = j
        if(m!=i):
            arr[i], arr[m] = arr[m], arr[i]
    return arr

# insertion sort
def insort(arr, n):
    for i in range(1, n):
        key = arr[i]
        j = i-1
        while(j>=0 and arr[j]>key):
            arr[j+1] = arr[j]
            j-=1
        arr[j+1]=key
    return arr

# quick sort
def quicksort(arr, low, high):
    if(low<high):
        pi = partition(arr, low, high)
        quicksort(arr, low, pi)
        quicksort(arr, pi+1, high)
    return arr

def partition(arr, low, high):
    pivot = arr[high-1]
    i = low-1
    for j in range(low, high):
        if(arr[j]<pivot):
            i+=1
            arr[i], arr[j] = arr[j], arr[i]
    arr[high-1], arr[i+1] = arr[i+1], arr[high-1]
    return i+1


# bucket sort
def bucketsort(arr, n):
    buckets = []
    for _ in range(10):
        buckets.append([])
    for i in range(n):
        bi = int(arr[i]*10)
        buckets[bi].append(arr[i])
    arr = []
    for j in buckets:
        r = selsort(j, len(j))
        arr+=r
    return arr
        
lst1 = [1, 3, 8, 2, 5, 6, 0, 9]
lst2 = [0, 1, 2, 3, 5, 6, 8, 9]
lst3 = [0.12, 0.78, 0.54, 0.36, 0.22, 0.98, 0.85, 0.66] # for bucket sort
l = len(lst1)
# res = linsearch(lst1, l, 2)
# res = sensearch(lst1, l, 4)
# res = binsearch(lst2, l, 3)
# res = binsearch(lst2, 0, l, 4)
res1 = fibsearch(lst2, l, 4)
print("index:", res1)

# res2 = bubsort(lst1, l)
# res2 = selsort(lst1, l)
# res2 = insort(lst1, l)
# res2 = quicksort(lst1, 0, l)
res2 = bucketsort(lst3, len(lst3))
print("list sorted: ", res2)
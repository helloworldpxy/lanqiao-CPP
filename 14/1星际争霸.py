
n = int(input())
lst_num = []
for i in range(n):
    num = input()
    lst_num.append(num)


def merge_sort(st,low,high):
    if low >= high:
        return 0
    mid = (low+high)//2
    i, j = low, mid+1
    li1 = []
    num1 = merge_sort(st,low,mid) + merge_sort(st,mid+1,high)
    while i <= mid and j <= high:
        if int(st[i]) <= int(st[j]):
            li1.append(st[i])
            i += 1
        else:
            li1.append(st[j])
            num1 += mid-i+1
            j += 1
    li1.extend(st[i:mid+1])
    li1.extend(st[j:high+1])
    st[low:high+1] = li1
    return num1

lst1 = []
for i in range(len(lst_num)):
    s = lst_num[i].strip()
    num = merge_sort(list(s),0,len(s)-1)
    lst1.append((num,s))
lst1.sort(key=lambda x:((x[0],len(x[1])),x[1]))
for j in range(len(lst1)):
    print(lst1[j][1])

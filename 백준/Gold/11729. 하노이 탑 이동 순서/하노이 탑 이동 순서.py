def hanoi(n, A, B, f):
    if n==1:
        print(A, B)
    else:
        hanoi(n-1, A, f, B)#n-1을 가운데로
        print(A, B)#n을 목표로
        hanoi(n-1, f, B, A)#n-1이 n자리로 들어가서 재귀
        

num = int(input())
print(2**num - 1)
hanoi(num, 1, 3, 2)
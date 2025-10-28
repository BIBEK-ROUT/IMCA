num = int(input("Enter a number: "))
num1 = num
if num % 2 == 0:
    num = num + 3
else:
    num = num + 2

mid = num // 2
left = mid - 1
mid1 = 2

# Upper part
for i in range(0, num1):
    for j in range(0, num):
        if i == 0 and j == mid:
            print(1, end=" ")
        elif j == left and i != 0:
            print(1, end=" ")
            left = left - 1
        elif j == mid and i != 0:
            print(mid1, end=" ")
            mid1 = mid1 + 1
        else:
            print(" ", end=" ")
    print()
    mid = mid + 1
    left = left + 1
    mid1 = mid1 - 1

# Lower part
mid = num // 2 + num1 - 1
left = mid - 1
mid1 = num1
for i in range(num1 - 1, 0, -1):
    for j in range(0, num):
        if j == left:
            print(1, end=" ")
        elif j == mid:
            print(mid1, end=" ")
        else:
            print(" ", end=" ")
    print()
    mid = mid - 1
    left = left - 1
    mid1 = mid1 - 1


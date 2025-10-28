def hollow_number_diamond(n):
    if n <= 0:
        return

    cellw = len(str(n))           # support multi-digit numbers
    width = 2 * n - 1
    mid = n - 1

    rows = []
    # build top half (including middle row)
    for i in range(n):
        row = [' ' * cellw for _ in range(width)]
        left = mid - i
        right = mid + i
        row[left] = '1'.rjust(cellw)
        if left != right:
            row[right] = str(i + 1).rjust(cellw)
        rows.append(' '.join(row).rstrip())

    # print top then mirrored bottom
    for r in rows:
        print(r)
    for r in rows[-2::-1]:
        print(r)


if __name__ == "__main__":
    num = int(input("Enter a number: "))
    hollow_number_diamond(num)

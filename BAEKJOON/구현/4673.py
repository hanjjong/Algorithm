def num_plus(each):
    result = each
    count = 0
    div = each
    while 1:
        div = int(div/10)
        count+=1
        if div == 0:
            break
    for i in range(count):
        div = each
        div = int(div/(10**i))
        result = result + div%10
    return result

def self_check(num):
    if num <= 36:
        for i in range(0, num):
            if num_plus(i) == num:
                return 0
    elif num > 36:
        for i in range(int(num - 36), num):
            if num_plus(i) == num:
                return 0
    return 1

for i in range(1,10001):
    if self_check(i) == 1:
        print(i)


import sys
import random
def swap(list, i, j):
    tmp = list[i]
    list[i] = list[j]
    list[j] = tmp

def generate():
    number_limit = int(sys.argv[1])
    n = int(sys.argv[2])
    list = []
    for i in range(number_limit):
        list.append(i)
    f = open('numbers_input.txt', 'w')
    for i in range(n):
        random_index = random.randint(i, number_limit - 1)
        swap(list, i, random_index)
        f.write(str(list[i]) + '\n')
    f.close()

generate()

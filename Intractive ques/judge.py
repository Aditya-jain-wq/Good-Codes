import random

n = 10
matrix = [[0 for _ in range(n)] for _ in range(n)]

PROBABILITY = 15
weights = [0 for _ in range(100)]
weights[:PROBABILITY] = [1 for _ in range(PROBABILITY)]
random.shuffle(weights)

for i in range(n):
    for j in range(n):
        matrix[i][j] = random.choice(weights)

def submat_sum(matrix, r1, c1, r2, c2):
    return sum(x for i in matrix[r1-1:r2] for x in i[c1-1:c2])

print("1")
print(n,PROBABILITY)
queries = 0
file1 = open("debug.txt","a+")
while queries <= 18000:
    q = [int(i) for i in input().split()]
    file1.write(str(q))
    if q[0] == 1:
        try:
            sum_ = submat_sum(matrix, *q[1:])
            print(sum_)
            file1.write(str(sum_)+"\n")
        except IndexError:
            print(-1)
            exit()
    elif q[0] == 2:
        user_mat = [[int(i) for i in input().split()] for _ in range(n)]
        if user_mat == matrix:
            print(1)
            break
        else:
            print(-1)
            with open('cases', 'a+') as f:
                f.write("ur ans \n")
                for i in user_mat:
                    f.write(' '.join(str(j) for j in i))
                    f.write('\n')
                f.write('\n')
                f.write("actual \n")
                for i in matrix:
                    f.write(' '.join(str(j) for j in i))
                    f.write('\n')
                f.write('\n\n')
            break
    queries+=1
import matplotlib.pyplot as plt
#Assignment no 2
# Role
# point=[(x1,x2,sign),n(),.....]
# n for update

# w0=w0+n*1 ->if sign=1
# w0=w0-n*1 ->if sign=0
# Sum equal Sum=w0+(w1*x1+w2*x2)
a = 'a'
b = 'b'
n = 0.2
point = [(1, 1, 1), (1.5, -0.5, 1), (-2, 1, 1), (2, -2, 0), (-1, -1.5, 0), (-2, -1, 0)]
w = [0, 1, 0.5]
i = 0
u = 3

while i <= 5:
    SumE = w[0] + (w[1] * point[i][0] + w[2] * point[i][1])
    print("//////////////////////")

    print('no', i, 'is', SumE)
    print('X1 is :',point[i][0])
    print('X2 iS :',point[i][1])
    print('The Sgin is :',point[i][2])
    print(w)

    if point[i][2] == 1 & int(SumE <= 0):
        w[0] = w[0] + n * 1
        w[1] = w[1] + n * point[i][0]
        w[2] = w[2] + n * point[i][1]
        print('okay1')
    elif point[i][2] == 0 & int(SumE > 0):
        w[0] = w[0] - n * 1
        w[1] = w[1] - n * point[u][0]
        w[2] = w[2] - n * point[u][1]
        print('okay2')

    else:
        print('no')
        print("//////////////////////\n")

    i += 1

print('/////////&&/////')
"""""
while u <= 5:
    SumE = w[0] + (w[1] * point[u][0] + w[2] * point[u][1])

    print('no', i, 'is', SumE)
    print(w)
    if point[i][2] == 0 & int(SumE >= 0):
        w[0] = w[0] - n * 1
        w[1] = w[1] - n * point[u][0]
        w[2] = w[2] - n * point[u][1]
        print('okay')
    else:
        print('no')
    i += 1
    u += 1
"""
print(w)


plt.scatter(point[0][0],point[0][1],c="r")
plt.scatter(point[1][0],point[1][1],c="r")
plt.scatter(point[2][0],point[2][1],c="r")

plt.scatter(point[3][0],point[3][1],c="g")
plt.scatter(point[4][0],point[4][1],c="g")
plt.scatter(point[5][0],point[5][1],c="g")


plt.show()

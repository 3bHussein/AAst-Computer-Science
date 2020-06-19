import math
import matplotlib.pyplot as plt
p = [(1, 1), (1.5, 2), (3, 4), (5, 7), (3.5, 5), (4.5, 5), (3.5, 4.5)]
m1 = [p[0][0], p[0][1]]
m2 = [p[3][0], p[3][1]]
G1=[]
G2=[]
cen1 = []
Ncen1=[]
cen2 = []
Ncen2=[]
group1=[]
group2=[]

i =v = b = 0
gsum1=gsum2=Gsum1=Gsum2=count1=count2=j=q=0


#this loop for centroid 1
while i <= 6:
    x1 = math.sqrt(pow((m1[0] - p[i][0]), 2) + pow((m1[1] - p[i][1]), 2))
    cen1.append(round(x1, 2))
    i += 1
#this loop for centroid 2
while v <= 6:
    x1 = math.sqrt(pow((m2[0] - p[v][0]), 2) + pow((m2[1] - p[v][1]), 2))
    cen2.append(round(x1, 2))
    v += 1

#First Filter
while b <= 6:

    if cen1[b] <= cen2[b]:
        gsum1 += p[b][0]
        gsum2+=p[b][1]
        count1+=1
        G1.append((p[b][0],p[b][1]))
    else:
        Gsum1 += p[b][0]
        Gsum2+=p[b][1]
        count2+=1
        G2.append((p[b][0], p[b][1]))
    b += 1
group1.extend((round((gsum1/count1),2),round((gsum2/count1),2)))
group2.extend((round(Gsum1/count2,2),round((Gsum2/count2),2)))
print('ni why',G1)
print('ni why',G2)







#this Secoend loop for centroid 1
g=[group1]
ii=0
while ii <= 6:
    xx1 = math.sqrt(pow((g[0][0] - p[ii][0]), 2) + pow((g[0][1] - p[ii][1]), 2))
    # print(round(x1, 2))
    # cen1.append(round(x1, 2))
    # cen1.extend((round(x1,2),i+1))
    Ncen1.append(round(xx1, 2))
    ii += 1
# this Secoend loop for centroid 2
G = [group2]
ix = 0
while ix <= 6:
    xz1 = math.sqrt(pow((G[0][0] - p[ix][0]), 2) + pow((G[0][1] - p[ix][1]), 2))
    Ncen2.append(round(xz1, 2))
    ix += 1


'''
while j<7:
    if j==0:
        plt.scatter(p[j][0], p[j][1], c="g")
    elif j==3:
        plt.scatter(p[j][0], p[j][1], c="b")
    else:plt.scatter(p[j][0], p[j][1], c="r")
    j+=1
#plt.show()
'''

while j< len(G1):
    plt.scatter(G1[j][0], G1[j][1], c="g")

    j+=1

while q < len(G2):
        plt.scatter(G2[q][0], G2[q][1], c="r")

        q+= 1


plt.show()

print('All Point is :',p)
print('m1 is:',m1)
print('m2 is:',m2)
print('old centroid 1 is :',cen1)
print('old centroid 2 is :',cen2)
print(group1)
print('New centroid 1 is :',Ncen1)
print('New centroid 1 is :', Ncen2)


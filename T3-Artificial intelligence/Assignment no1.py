
x1=[0,0,1,1]
x2=[0,1,0.2,1]
a=[None]*4
y=[None]*4
w1=w2=s=1
i=x=0
#a=Sum(xw)-s
while i < 4:
    sum=((x1[x]*w1)+(x2[x]*w2))
    #print("Sum is :",sum)
    a[x]=sum-s


    print("A is :",a)
    if sum > s:
      y[x]=1
      print("Y is :",y)
    else:
        y[x] = 0
        print("Y is :", y)
    i+=1
    x+=1
    print("////////////////")

print("\n")
print("\t//////////////////////")
print("\t// A",a,"//")
print("\t// Y",y,"//")
print("\t///////")
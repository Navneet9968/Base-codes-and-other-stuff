print("enter marks of three subjects:")
sub1=int(input("enter marks of first subject: "))
if sub1>100:
    print("marks cannot be greater than 100")
    quit()
sub2=int(input("enter marks of second subject: "))
if sub2>100:
    print("marks cannot be greater than 100")
    quit()
sub3=int(input("enter marks of third subject: "))
if sub3>100:
    print("marks cannot be greater than 100")
    quit()
avg=(sub1+sub2+sub3)/3
print("the average of the three subjects",avg)

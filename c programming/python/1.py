emprec=[]
while True:
    print("1.to add employee record.")
    print("2.to delete employee record.")
    print("3.to display employee records.")
    print("4.to exit.")
    a=int(input("enter your choice: "))
    if a==1:
        input1=int(input("enter employee no: "))
        input2=input("enter name: ")
        input3=int(input("enter age: "))
        templist=[input1,input2,input3]
        emprec.append(templist)
    if a==2:
        delind=int(input("enter the index which you want deleted: "))
        del emprec[delind]
    if a==3:
        print(emprec)
    if a==4:
        break
    else:
        continue
        
    
    

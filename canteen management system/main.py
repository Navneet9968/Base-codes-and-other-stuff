from tkinter import *
from tkinter import ttk
import mysql.connector
from tkinter import messagebox
import datetime
import tkinter

class CanteenManagementSystem:
    def __init__(self,root):
        self.root = root
        self.root.title("Canteen Management System")
        # in geometry first is the resolution then second and third are x and y respectively
        self.root.geometry("1980x1080+0+0")


        #########################################   variables   #####################################
        self.member_var=StringVar()
        self.prn_no_var=StringVar()
        self.id_no_var=StringVar()
        self.fname_var=StringVar()
        self.lname_var=StringVar()
        self.mob_no_var=StringVar()
        self.fid_var=StringVar()
        self.food_name_var=StringVar()
        self.calories_var=StringVar()
        self.gst_var=StringVar()
        self.handlingCharge_var=StringVar()
        self.date_var=StringVar()
        self.totalCost_var=StringVar()



        label_title = Label(self.root,text="Canteen Management System",bg="black",fg="white",
        bd=20,relief=RIDGE,font=("joker",50,"bold"),padx=4,pady=4)
        label_title.pack(side=TOP,fill=X)

## Framing the whole GUI
        frame=Frame(self.root,bd=12,relief=RIDGE,padx=20,bg="yellow")
        frame.place(x=0,y=130,width=1535,height=400)
        
        
        ## data frame left 
        DataFrameLeft=LabelFrame(frame,text=" Member Information ",bg="powder blue",fg="green",bd=20,relief=RIDGE,font=("times new roman",15,"bold"))
        DataFrameLeft.place(x=0,y=5,width=860,height=350)

        lblMember=Label(DataFrameLeft,text=" Member Type",bg="powder blue",font=("arial",12,"bold"),padx=2,pady=6)
        lblMember.grid(row=0,column=0,sticky=W)
        
        memType=ttk.Combobox(DataFrameLeft,textvariable=self.member_var,font=("arial",12,"bold"),width=27,state="readonly")
        memType["value"]=("Student","Faculty Staff","Guest Lecturer")
        memType.current(0)
        memType.grid(row=0,column=1)

        lblPRN_NO=Label(DataFrameLeft,font=("arial",12,"bold"),text="PRN No :",padx=2,bg="powder blue",pady=6)
        lblPRN_NO.grid(row=1,column=0,sticky=W)
        txtPRN_NO=Entry(DataFrameLeft,textvariable=self.prn_no_var,font=("arial",13,"bold"),width=29)
        txtPRN_NO.grid(row=1,column=1)

        lblID_NO=Label(DataFrameLeft,font=("arial",12,"bold"),text="ID No :",padx=2,bg="powder blue",pady=6)
        lblID_NO.grid(row=2,column=0,sticky=W)
        txtID_NO=Entry(DataFrameLeft,textvariable=self.id_no_var,font=("arial",13,"bold"),width=29)
        txtID_NO.grid(row=2,column=1)

        lblFirstName=Label(DataFrameLeft,font=("arial",12,"bold"),text="First Name :",padx=2,bg="powder blue",pady=6)
        lblFirstName.grid(row=3,column=0,sticky=W)
        txtFN=Entry(DataFrameLeft,textvariable=self.fname_var,font=("arial",13,"bold"),width=29)
        txtFN.grid(row=3,column=1)

        lblLastName=Label(DataFrameLeft,font=("arial",12,"bold"),text="Last Name :",padx=2,bg="powder blue",pady=6)
        lblLastName.grid(row=4,column=0,sticky=W)
        txtFN=Entry(DataFrameLeft,textvariable=self.lname_var,font=("arial",13,"bold"),width=29)
        txtFN.grid(row=4,column=1)

        lblMobNo=Label(DataFrameLeft,font=("arial",12,"bold"),text="Mobile No :",padx=2,bg="powder blue",pady=6)
        lblMobNo.grid(row=5,column=0,sticky=W)
        txtMN=Entry(DataFrameLeft,textvariable=self.mob_no_var,font=("arial",13,"bold"),width=29)
        txtMN.grid(row=5,column=1)

                        # for food
        
        lbl_food_heading=Label(DataFrameLeft,font=("arial",14,"bold"),text="About Food :",padx=5,bg="powder blue",pady=6)
        lbl_food_heading.grid(row=0,column=2,sticky=W)

        lblfid=Label(DataFrameLeft,font=("arial",12,"bold"),text="Food ID :",padx=2,bg="powder blue",pady=6)
        lblfid.grid(row=1,column=2,sticky=W)
        txtFID=Entry(DataFrameLeft,textvariable=self.fid_var,font=("arial",13,"bold"),width=29)
        txtFID.grid(row=1,column=3,sticky=W)

        lbl_fname=Label(DataFrameLeft,font=("arial",12,"bold"),text="Food Name :",padx=2,bg="powder blue",pady=6)
        lbl_fname.grid(row=2,column=2,sticky=W)
        txtFName=Entry(DataFrameLeft,textvariable=self.food_name_var,font=("arial",13,"bold"),width=29)
        txtFName.grid(row=2,column=3)

        lbl_cal=Label(DataFrameLeft,font=("arial",12,"bold"),text="Calories :",padx=2,bg="powder blue",pady=6)
        lbl_cal.grid(row=3,column=2,sticky=W)
        txtCAL=Entry(DataFrameLeft,textvariable=self.calories_var,font=("arial",13,"bold"),width=29)
        txtCAL.grid(row=3,column=3)

        lbl_GST=Label(DataFrameLeft,font=("arial",12,"bold"),text="GST Charges :",padx=2,bg="powder blue",pady=6)
        lbl_GST.grid(row=4,column=2,sticky=W)
        txtGST=Entry(DataFrameLeft,textvariable=self.gst_var,font=("arial",13,"bold"),width=29)
        txtGST.grid(row=4,column=3)

        lbl_Handling=Label(DataFrameLeft,font=("arial",12,"bold"),text="Handling Charges :",padx=2,bg="powder blue",pady=6)
        lbl_Handling.grid(row=5,column=2,sticky=W)
        txtHC=Entry(DataFrameLeft,textvariable=self.handlingCharge_var,font=("arial",13,"bold"),width=29)
        txtHC.grid(row=5,column=3)

        lbl_date=Label(DataFrameLeft,font=("arial",12,"bold"),text="Date :",padx=2,bg="powder blue",pady=6)
        lbl_date.grid(row=6,column=2,sticky=W)
        txtdate=Entry(DataFrameLeft,textvariable=self.date_var,font=("arial",13,"bold"),width=29)
        txtdate.grid(row=6,column=3)

        lbl_cost=Label(DataFrameLeft,font=("arial",12,"bold"),text="Total Cost :",padx=2,bg="powder blue",pady=6)
        lbl_cost.grid(row=7,column=2,sticky=W)
        txtcost=Entry(DataFrameLeft,textvariable=self.totalCost_var,font=("arial",13,"bold"),width=29)
        txtcost.grid(row=7,column=3)
        

        ## data frame left end 

        
        
        #data frame right

        DataFrameRight=LabelFrame(frame,text=" Food Information ",bg="powder blue",fg="green",bd=20,relief=RIDGE,font=("times new roman",15,"bold"))
        DataFrameRight.place(x=910,y=5,width=580,height=350)

        self.txtBox=Text(DataFrameRight,font=("arial",13,"bold"),width=32,height=15,pady=6,padx=2)
        self.txtBox.grid(row=0,column=2)

        listScrollBar=Scrollbar(DataFrameRight)
        listScrollBar.grid(row=0,column=1,sticky="ns")
        
        listItems=["North Indian Thali","Punjabi Thali","Eastern Mix","Navratri Thali","South Indian Thali","Western Mix"]
        
        def SelectFood(event=""):
            value=str(listBox.get(listBox.curselection()))
            a=value
            
            if(a=="North Indian Thali"):
                self.fid_var.set("110001")
                self.food_name_var.set("North Indian Thali")     
                self.calories_var.set("900 calories")
                self.gst_var.set("₹34")
                self.handlingCharge_var.set("₹20")
                self.date_var.set(datetime.datetime.today())
                self.totalCost_var.set("₹254")
            
            if(a=="Punjabi Thali"):
                self.fid_var.set("110002")
                self.food_name_var.set("Punjabi Thali")     
                self.calories_var.set("1200 calories")
                self.gst_var.set("₹34")
                self.handlingCharge_var.set("₹20")
                self.date_var.set(datetime.datetime.today())
                self.totalCost_var.set("₹260")
            
            if(a=="Eastern Mix"):
                self.fid_var.set("110003")
                self.food_name_var.set("Eastern Mix")     
                self.calories_var.set("500 calories")
                self.gst_var.set("₹34")
                self.handlingCharge_var.set("₹20")
                self.date_var.set(datetime.datetime.today())
                self.totalCost_var.set("₹200")
            
            if(a=="Navratri Thali"):
                self.fid_var.set("110004")
                self.food_name_var.set("Navratri Thali")     
                self.calories_var.set("700 calories")
                self.gst_var.set("₹34")
                self.handlingCharge_var.set("₹20")
                self.date_var.set(datetime.datetime.today())
                self.totalCost_var.set("₹150")

            if(a=="South Indian Thali"):
                self.fid_var.set("110005")
                self.food_name_var.set("South Indian Thali")     
                self.calories_var.set("850 calories")
                self.gst_var.set("₹34")
                self.handlingCharge_var.set("₹20")
                self.date_var.set(datetime.datetime.today())
                self.totalCost_var.set("₹220")

            if(a=="Western Mix"):
                self.fid_var.set("110006")
                self.food_name_var.set("Western Mix")     
                self.calories_var.set("1500 calories")
                self.gst_var.set("₹34")
                self.handlingCharge_var.set("₹20")
                self.date_var.set(datetime.datetime.today())
                self.totalCost_var.set("₹300")



        
        listBox=Listbox(DataFrameRight,font=("arial",13,"bold"),width=20,height=15) 
        listBox.bind("<<ListboxSelect>>",SelectFood)
        listBox.grid(row=0,column=0,padx=2)
        listScrollBar.config(command=listBox.yview)
         

        for item in listItems:
            listBox.insert(END,item)


        #####################################################################     buttons frame    ############################################
        FrameButton=Frame(self.root,bd=12,relief=RAISED,padx=20,bg="yellow")
        FrameButton.place(x=0,y=530,width=1535,height=70)

        btnAddData=Button(FrameButton,command=self.add_data,text="ADD DATA",font=("arial",13,"bold"),width=23,bg="black",fg="white")
        btnAddData.grid(row=0,column=0)

        btnAddData=Button(FrameButton,command=self.showData,text="SHOW DATA",font=("arial",13,"bold"),width=23,bg="black",fg="white")
        btnAddData.grid(row=0,column=1)
        
        btnAddData=Button(FrameButton,command=self.update_data,text="UPDATE",font=("arial",13,"bold"),width=23,bg="black",fg="white")
        btnAddData.grid(row=0,column=2)

        btnAddData=Button(FrameButton,text="DELETE",font=("arial",13,"bold"),width=23,bg="black",fg="white")
        btnAddData.grid(row=0,column=3)

        btnAddData=Button(FrameButton,command=self.reset,text="RESET",font=("arial",13,"bold"),width=23,bg="black",fg="white")
        btnAddData.grid(row=0,column=4)

        btnAddData=Button(FrameButton,command=self.Exit,text="EXIT",font=("arial",13,"bold"),width=23,bg="black",fg="white")
        btnAddData.grid(row=0,column=5)


        #####################################################################     information frame    ############################################
        FrameDetails=Frame(self.root,bd=12,relief=RIDGE,padx=20,bg="yellow")
        FrameDetails.place(x=0,y=600,width=1535,height=190)

        Table_frame=Frame(FrameDetails,bd=6,relief=RIDGE,bg="white")
        Table_frame.place(x=0,y=2,width=1460,height=160)

        
        yscroll=ttk.Scrollbar(Table_frame,orient=VERTICAL)

        self.canteen_table=ttk.Treeview(Table_frame,column=("membertype","prnno","idno","fname","lname","mobileno","foodid",
                                                            "foodname","calories","gst","handlingCharge","date","totalCost"),yscrollcommand=yscroll.set)


        
        yscroll.pack(side=RIGHT,fill=Y)
        yscroll.config(command=self.canteen_table.yview)

        
        
        self.canteen_table.heading("membertype",text="Member Type")
        self.canteen_table.heading("prnno",text="PRN No")
        self.canteen_table.heading("idno",text="ID No")
        self.canteen_table.heading("fname",text="First Name")
        self.canteen_table.heading("lname",text="Last Name")
        self.canteen_table.heading("mobileno",text="Mobile No")
        self.canteen_table.heading("foodid",text="Food ID")
        self.canteen_table.heading("foodname",text="Food Name")
        self.canteen_table.heading("calories",text="Calories Contained")
        self.canteen_table.heading("gst",text="GST")
        self.canteen_table.heading("handlingCharge",text="Handling Charges")
        self.canteen_table.heading("date",text="Date")
        self.canteen_table.heading("totalCost",text="Total Cost")


        self.canteen_table["show"]="headings"
        self.canteen_table.pack(fill=BOTH,expand=1)

                        #for reducing the width of the column
        self.canteen_table.column("membertype",width=100)
        self.canteen_table.column("prnno",width=100)
        self.canteen_table.column("idno",width=100)
        self.canteen_table.column("fname",width=100)
        self.canteen_table.column("lname",width=100)
        self.canteen_table.column("mobileno",width=100)
        self.canteen_table.column("foodid",width=100)
        self.canteen_table.column("foodname",width=100)
        self.canteen_table.column("calories",width=100)
        self.canteen_table.column("gst",width=100)
        self.canteen_table.column("handlingCharge",width=100)
        self.canteen_table.column("date",width=100)
        self.canteen_table.column("totalCost",width=100)
        
        self.fetch_data()
        self.canteen_table.bind("<ButtonRelease-1>",self.get_cursor)


    def add_data(self):
        conn=mysql.connector.connect(host="localhost",port=3307,username="root",password="root",database="mydb")
        if(conn.is_connected()):
            print("Connected successfully!")
        mycursor=conn.cursor()
        mycursor.execute("INSERT INTO canteen values (%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s)",(
                                                                            self.member_var.get(),
                                                                            self.prn_no_var.get(),
                                                                            self.id_no_var.get(),
                                                                            self.fname_var.get(),
                                                                            self.lname_var.get(),
                                                                            self.mob_no_var.get(),
                                                                            self.fid_var.get(),
                                                                            self.food_name_var.get(),
                                                                            self.calories_var.get(),
                                                                            self.gst_var.get(),
                                                                            self.handlingCharge_var.get(),
                                                                            self.date_var.get(),
                                                                            self.totalCost_var.get()
                                                                            ))
                                                                    
        conn.commit()
        self.fetch_data()
        conn.close()

        messagebox.showinfo("success","member has been inserted successfully!")
    
    def fetch_data(self):
        conn=mysql.connector.connect(host='localhost',port=3307,username="root",password="root",database="mydb")
        mycursor=conn.cursor()
        mycursor.execute("SELECT * FROM canteen")
        rows=mycursor.fetchall()

        if(len(rows) != 0):
            self.canteen_table.delete(*self.canteen_table.get_children())
            for i in rows:
                self.canteen_table.insert("",END,values=i)
            conn.commit()
        conn.close()

    def update_data(self):
        conn=mysql.connector.connect(host="localhost",port=3307,username="root",password="root",database="mydb")
        mycursor=conn.cursor()
        mycursor.execute("update canteen set member=%s,ID=%s,fname=%s,lname=%s,MOB_NO=%s,fid=%s,foodname=%s,calories=%s,gst=%s,handling=%s,date=%s,totalCost=%s where PRN_NO=%s",(
                                self.member_var.get(),
                                self.id_no_var.get(),
                                self.fname_var.get(),
                                self.lname_var.get(),
                                self.mob_no_var.get(),
                                self.fid_var.get(),
                                self.food_name_var.get(),
                                self.calories_var.get(),
                                self.gst_var.get(),
                                self.handlingCharge_var.get(),
                                self.date_var.get(),
                                self.totalCost_var.get(),
                                self.prn_no_var.get()
        ))
        conn.commit()
        self.fetch_data()
        self.reset()
        conn.close()

        messagebox.showinfo("Success","member has been updated")



    # def delete(self):
    #     if self.prn_no_var=="" or self.id_no_var=="":
    #         messagebox.showinfo("error","first select the member")
    #     else:




    def get_cursor(self,event=""):
        cursor_row=self.canteen_table.focus()
        content=self.canteen_table.item(cursor_row)
        row=content['values']

        self.member_var.set(row[0]),
        self.prn_no_var.set(row[1]),
        self.id_no_var.set(row[2]),
        self.fname_var.set(row[3]),
        self.lname_var.set(row[4]),
        self.mob_no_var.set(row[5]),
        self.fid_var.set(row[6]),
        self.food_name_var.set(row[7]),
        self.calories_var.set(row[8]),
        self.gst_var.set(row[9]),
        self.handlingCharge_var.set(row[10]),
        self.date_var.set(row[11]),
        self.totalCost_var.set(row[12])

    def showData(self):
        self.txtBox.insert(END,"Member Type: \t\t"+self.member_var.get()+"\n")
        self.txtBox.insert(END,"PRN no: \t\t"+self.prn_no_var.get()+"\n")
        self.txtBox.insert(END,"ID no: \t\t"+self.id_no_var.get()+"\n")
        self.txtBox.insert(END,"First name: \t\t"+self.fname_var.get()+"\n")
        self.txtBox.insert(END,"Last name: \t\t"+self.lname_var.get()+"\n")
        self.txtBox.insert(END,"Mobile No: \t\t"+self.mob_no_var.get()+"\n")
        self.txtBox.insert(END,"Food ID: \t\t"+self.fid_var.get()+"\n")
        self.txtBox.insert(END,"Food Name: \t\t"+self.food_name_var.get()+"\n")
        self.txtBox.insert(END,"Calories: \t\t"+self.calories_var.get()+"\n")
        self.txtBox.insert(END,"GST: \t\t"+self.gst_var.get()+"\n")
        self.txtBox.insert(END,"Handling Ch: \t\t"+self.handlingCharge_var.get()+"\n")
        self.txtBox.insert(END,"date: \t\t"+self.date_var.get()+"\n\n")
        self.txtBox.insert(END,"Total Cost: \t\t"+self.totalCost_var.get()+"\n")

    def reset(self):
        self.member_var.set(""),
        self.prn_no_var.set(""),
        self.id_no_var.set(""),
        self.fname_var.set(""),
        self.lname_var.set(""),
        self.mob_no_var.set(""),
        self.fid_var.set(""),
        self.food_name_var.set(""),
        self.calories_var.set(""),
        self.gst_var.set(""),
        self.handlingCharge_var.set(""),
        self.date_var.set(""),
        self.totalCost_var.set("")
        self.txtBox.delete("1.0",END)
    def Exit(self):
        Exit=tkinter.messagebox.askyesno("Exit","Are you sure you want to exit")
        if Exit>0:
            self.root.destroy()
            return 





## Framing ends



if __name__ == "__main__":
    root = Tk()
    obj = CanteenManagementSystem(root)#window name is the root object
    root.mainloop()#we write this so that the window remains open 
    
    

import tkinter as Tk

count=0

def reset():
    global count
    count=0


def EXIT():
    window.destroy()

def upcounter():
    global count
    
    if(count>=10 and count<30):
        label2.config(text=str(count),fg='green')

    elif(count>=30):
        label2.config(text=str(count),fg='red2')
        btn1.config()

    elif(count>=60):
        reset()
    
    label2.config(text=str(count))
    count+=1

    window.after(1000,counter) #1000ms

    

window=Tk.Tk()

label1=Tk.Label(window,text='COUNTER POWERD BY TK',bg='red2',fg='white',font='HELVITICA 20 bold')
label2=Tk.Label(window,text=str(count),bg='white',fg='black',font='HELVITICA 30 bold')

#to account for auto positioning,
label1.pack()
label2.pack()

btn1=Tk.Button(window,text='RESET',font='ARIAL 16 bold',bg='green',command=reset)
btn2=Tk.Button(window,text='EXIT',font='ARIAL 16 bold',bg='red2',command=EXIT)

btn1.pack()
btn2.pack()

upcounter()

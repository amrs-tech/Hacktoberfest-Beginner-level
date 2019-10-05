import tkinter as tk

count=0

def reset():
    global count
    count=0


def EXIT():
    window.destroy()

def counter():
    global count

    
    if(count>=10 and count<20):
        label2.config(text=str(count),fg='green')

        
        
    elif(count>=20):
        label2.config(text=str(count),fg='red2')
        btn1.config()

    
    label2.config(text=str(count))
    count+=1

    window.after(1000,counter) #1000ms

    

window=tk.Tk()

label1=tk.Label(window,text='COUNTER POWERD BY TK',bg='red2',fg='white',font='HELVITICA 20 bold')
label2=tk.Label(window,text=str(count),bg='white',fg='black',font='HELVITICA 30 bold')

label1.pack()#pack for auto positioning
label2.pack()

btn1=tk.Button(window,text='RESET',font='HELVITICA 15 bold',bg='green',command=reset)
btn2=tk.Button(window,text='EXIT',font='HELVITICA 15 bold',bg='red2',command=EXIT)

btn1.pack()
btn2.pack()

counter()

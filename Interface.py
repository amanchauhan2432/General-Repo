import tkinter as tk
from tkinter import ttk
from tkinter import messagebox as mbox
win=tk.Tk()
win.title('Final Round!!!')

label_frame=ttk.LabelFrame(win,text="Find correct answer for Winning the Game")
label_frame.grid(row=0,column=0,padx=320,pady=150)
ttk.Label(label_frame,text="There are three riddles which gives you four english alphabets.Please solve these riddles in order to get alphabets.\n\n1--> What is the last letter in the alphabet?\n\n2-->What letters are in - visible,but never out of sight?\n\n3-->I am the beginning of the end,the end of every place.I am the beginning of eternity, the end of time and space.What am i?\n\n\n\n\nNow you have to rearrange these alphabets in order to make your word.\n\nNOTE: Answer must be in Uppercase.").grid(row=0,column=0)
ttk.Label(label_frame,text="Type your answer: ").grid(row=1,column=0,pady=10)
ans_var=tk.StringVar()
ans_box=ttk.Entry(label_frame,width=15,textvariable=ans_var)
ans_box.grid(row=2,column=0,pady=5)

def submit():
    if ans_var.get()=="ISTE":
        mbox.showinfo("WINNER!!!","Congratulations, You are the Winner.")
    else:
        mbox.showerror("WRONG!!!","Please enter correct word.")

sub_btn=ttk.Button(label_frame,text="Submit!!!",command=submit)
sub_btn.grid(row=3,column=0)
win.mainloop()
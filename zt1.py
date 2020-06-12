from tkinter import *
app = Tk()
app.geometry('400x400')
app .wm_title("计算器")

button_txt = [
['7','8','9','+'],
['4','5','6','-'],
['1','2','3','*'],
['(',')','0','/'],
['清空','退格','.','='],
]

#按钮功能定义
display= StringVar()
#输入内容
def set_content(text):
    content= display.get()+text
    display.set(content)
#清空
def clear():
    display.set('')
#退格
def bck():
    display.set(str(display.get()[:-1]))
#等于计算
def calculate():
    try:
        num= display.get()
        res= eval(num)
        display.set(num+'='+str(res))
    except:
        display.set('error!')


#显示框
label = Label(app,text= "这里是标签显示", relief='ridge', font= ('Arail', '15'), anchor= E)
label.place(x= 0,y= 0,width= 400,height= 60,)

#UI界面
for i in range(5):
    for j in range(4):
        if button_txt[i][j]=="=":
            button= Button(app,text= button_txt[i][j],font= ('Arial','14'),)
            button.place(x=100*j, y=60*i+60, width= 100,height= 60)
        elif button_txt[i][j]=="清空"：
        button= Button(app,text= button_txt[i][j],font= ('Arial','14'),)
        button.place(x=100*j, y=60*i+60, width= 100,height= 60)
        elif button_txt[i][j]=="退格"：
             button= Button(app,text= button_txt[i][j],font= ('Arial','14'),)
             button.place(x=100*j, y=60*i+60, width= 100,height= 60)
        else：
            button= Button(
            app,text= button_txt[i][j],font= ('Arial','14'),)
            button.place(x=100*j, y=60*i+60, width= 100,height= 60)

app.mainloop()
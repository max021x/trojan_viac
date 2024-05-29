import ttkbootstrap as tb


class Commander :
  def __init__(self , window) -> None:
    self.main_frame = tb.Frame(window)
    self.main_frame.columnconfigure((0,1,2,3,4,5,6) , weight=1 , uniform='a')
    self.main_frame.rowconfigure((0,1,2,3,4,5,6) , weight=1 , uniform='a')
    self.command_ui()


  def command_ui(self):
    # Entry 
    self.entry = tb.Combobox(self.main_frame , bootstyle='info' , font='arial 20' , values=['mmd','ali'])
    self.entry.grid(row=2 , column=1 , columnspan=3 , sticky='ew')
    self.main_frame.pack(expand=1 , fill='both')

    #Info Label
    self.label = tb.Label(self.main_frame , text='ok.',font='arial 20',relief='sunken')
    self.label.place(x=45 , y=190 , width=300)

    #Submit BTN
    self.submit = tb.Button(self.main_frame , bootstyle='danger.outline' , text='SUBMIT',padding=(0,14))
    self.submit.grid(row=2 , column=4 ,columnspan=2, sticky='we' ,padx=10)
    self.submit.configure(command=self.do_command)

  def do_command(self):
    self.label.configure(text='not ok.')


window = tb.Window(themename='darkly',resizable=(False,False))
window.geometry('700x400')
command = Commander(window = window)
window.mainloop()

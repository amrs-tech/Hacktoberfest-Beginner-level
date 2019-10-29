'''
Description:
A simple program to create pop-up dialogue boxes to interact with the User

Author:
N Dheeraj Kumar

For more information, refer to the below link:
https://pyautogui.readthedocs.io/en/latest/introduction.html
'''

## importing the pyautogui library
import pyautogui as g

## opening the dialogue box with a message to be displayed
alert_msg = g.alert('Following questions are to be\n answered carefully','ALERT',button = 'OK')

if(alert_msg == 'OK'):                              # if OK button is clicked
    name = g.prompt('Type in your NAME')            # Ask user for input

confrm_msg = g.confirm('Is your name '+name+' ?',title = 'YOUR NAME',buttons=('YES','NO'))      # Opens another dialogue box to confirm the entry

# Welcome dialogue box !!
if(confrm_msg == 'YES'):
    g.alert('WELCOME '+name+' !!')
elif(confrm_msg == 'NO'):
    g.alert('PLEASE TYPE IN YOUR NAME PROPERLY')

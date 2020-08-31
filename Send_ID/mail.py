import smtplib

import gspread

from oauth2client.service_account import ServiceAccountCredentials

scope = ['https://spreadsheets.google.com/feeds','https://www.googleapis.com/auth/drive']

creds = ServiceAccountCredentials.from_json_keyfile_name('client_secret.json',scope)

client = gspread.authorize(creds)

sheet = client.open("It's All About Experimenting").sheet1

mail_list = sheet.col_values(2)

mail_list = mail_list[1:]

print(mail_list)


mail=smtplib.SMTP('smtp.gmail.com',587)

mail.ehlo()

mail.starttls()

mail.login('gndeciste@gmail.com','!STE@Dhingr@')

for i in mail_list:
    msg = f"""\
Hello ISTE welcomes you in our Episode 2 -> It's All About Experimenting of ISTE Growth Series.

In this webinar you will get to know about how to create a real project from scratch and launch in Market and Earn Money

So Please Join The Webinar With The Given Link

Meeting Link- https://meet.google.com/
"""
    mail.sendmail('gndeciste@gmail.com',i,'Subject: Invitation Link Of Webinar.\n\n'+msg)

mail.quit()

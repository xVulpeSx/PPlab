# CODE FROM
# https://www.freecodecamp.org/news/send-emails-using-code-4fcea9df63f/

import smtplib
from string import Template
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

MY_ADDRESS = "email@gmail.com"
MY_PASSWORD = "password"


def getLists(filename):
    names = []
    emails = []
    santas = []
    with open(filename, mode='r') as contactsFile:
        for contact in contactsFile:
            names.append(contact.split()[0])
            emails.append(contact.split()[1])
            santas.append(contact.split()[2])
    return names, emails, santas

def readTemplate(filename):
    with open(filename, 'r', encoding='utf-8') as templateFile:
        templateFileContent = templateFile.read()
    return Template(templateFileContent)

# STARTTLS encryption method

s = smtplib.SMTP('smtp.gmail.com', '587')

s.ehlo()
s.helo()

s.starttls()

s.login(MY_ADDRESS, MY_PASSWORD)

names, emails, santas = getLists("output.txt")
messageTemplate = readTemplate('message.txt')

for name, email, santa in zip(names, emails, santas):
    msg = MIMEMultipart()

    message = messageTemplate.substitute(SANTA_NAME=santa.title(), RECIVER_NAME=name.title())


    msg['From']=MY_ADDRESS
    msg['To']=email
    msg['Subject']="test SecretSanta"

    msg.attach(MIMEText(message, 'plain'))

    s.send_message(msg)

    del msg

if __name__ == '__main__':
    main()

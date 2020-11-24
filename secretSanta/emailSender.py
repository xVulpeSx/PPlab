# CODE FROM
# https://www.freecodecamp.org/news/send-emails-using-code-4fcea9df63f/

import smtplib
from string import Template
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

MY_ADDRESS = "email@outlook.com"
MY_PASSWORD = "Password"


def getLists(filename):
    names = []
    emails = []
    with open(filename, mode='r', encoding='urf-8') as contactsFile:
        for contact in contactsFile:
            names.append(contact.split()[0])
            emails.append(contact.split()[1])
    return names, emails

def readTemplate(filename):
    with open(filename, 'r', encoding='utf-8') as templateFile:
        templateFileContent = templateFile.read()
    return Template(templateFileContent)

MY_ADDRESS = "address"
MY_PASSWORD = "password"

# STARTTLS encryption method

s = smtplib.SMTP('smtp-mail.outlook.com', '587')

s.ehlo()
s.helo()

print("XDDDDD:\n")
print(s.helo_resp)
print(s.ehlo_resp)

s.starttls()

s.login(MY_ADDRESS, MY_PASSWORD)

names, emails = getLists("santa.txt")
messageTemplate = readTemplate('message.txt')

for name, email in zip(names, emails):
    msg = MIMEMultipart()

    message = messageTemplate.substitute(PERSON_NAME=name.title())

    msg['From']=MY_ADDRESS
    msg['To']=email
    msg['Subject']="test SecretSanta"

    msg.attach(MIMEText(message, 'plain'))

    s.send_message(msg)

    del msg

if __name__ == '__main__':
    main()

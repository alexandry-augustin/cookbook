# Import smtplib for the actual sending function
import smtplib

# Import the email modules we'll need
from email.message import EmailMessage

sender_address = 'email@gmail.com'
sender_pass = ''

msg = EmailMessage()
msg.set_content('content')
msg['Subject'] = 'subject'
msg['From'] = sender_address
msg['To'] = sender_address

# Send the message via our own SMTP server.
session = smtplib.SMTP('smtp.gmail.com', 587)
session.ehlo()
session.starttls() #enable security
session.login(sender_address, sender_pass) #login with mail_id and password
text = message.as_string()
session.sendmail(sender_address, receiver_address, text)
s.send_message(msg)
s.quit()

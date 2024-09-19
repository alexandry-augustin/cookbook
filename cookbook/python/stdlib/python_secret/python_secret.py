import secrets
import string

if __name__ == '__main__':

    # See https://stackoverflow.com/questions/3854692/generate-password-in-python
    alphabet = string.ascii_letters + string.digits
    length = 20
    password = ''.join(secrets.choice(alphabet) for i in range(length))
    print(password)


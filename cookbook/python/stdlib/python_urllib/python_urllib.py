from urllib.parse import urlencode

if __name__ == '__main__':

    # Serializing dictionaries into query strings

    data = { 'name': 'John', 'age':25, 'height':1.85 }
    querystring = urlencode(data)

    print(querystring)


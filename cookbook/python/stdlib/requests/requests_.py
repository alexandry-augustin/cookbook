# https://www.w3schools.com/python/ref_requests_post.asp

import requests

def post_00():

#    url = 'https://www.w3schools.com/python/demopage.php'
#    data = {'somekey': 'somevalue'}

    url = "http://bugs.python.org"
    payload = {'number': 12524, 'type': 'issue', 'action': 'show'}

    r = requests.post(url, data=payload)

    print(r.text[:600])
    print(r.status_code, r.reason)


    payload = {'some': 'data'}
    r = requests.post(url, data=json.dumps(payload))

def get_00():

    r = requests.get('https://api.github.com/events')

if __name__ == '__main__':

    post_00()

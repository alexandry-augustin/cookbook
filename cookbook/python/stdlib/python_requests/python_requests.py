# https://www.w3schools.com/python/ref_requests_post.asp

import requests
import json

def pretty_print(text):

    ret = json.loads(text)
    ret = json.dumps(ret, indent=4, sort_keys=True, separators=(',', ': '))

    return ret

def post_00():

#    url = 'https://www.w3schools.com/python/demopage.php'
#    data = {'somekey': 'somevalue'}

    url = "http://bugs.python.org"
    payload = {'number': 12524, 'type': 'issue', 'action': 'show'}

    resp = requests.post(url, data=payload)

    print(resp.text[:600])
    print(resp.status_code, resp.reason)


    payload = {'some': 'data'}
    resp = requests.post(url, data=json.dumps(payload))

def get_00():

    resp = requests.get('https://api.github.com/events')
    print(pretty_print(resp.text))

if __name__ == '__main__':

    get_00()
    post_00()

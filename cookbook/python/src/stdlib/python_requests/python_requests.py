# https://www.w3schools.com/python/ref_requests_post.asp

import requests
import json

def pretty_print(text):

    ret = json.loads(text)
    ret = json.dumps(ret, indent=4, sort_keys=True, separators=(',', ': '))

    return ret

def post_00(
        url, 
        data, 
        headers=None):

    resp = requests.post(
        url, 
        headers=headers, 
        data=data)

    return resp

def get_00(url):

    resp = requests.get(url)

    return resp

if __name__ == '__main__':

    # headers = { 
    #     'Content-type': 'application/json', 
    #     'Accept': 'application/json'
    # }

    resp = get_00(url='https://api.github.com/events')

    # resp = post_00(
    #     url='https://www.w3schools.com/python/demopage.php', 
    #     data={
    #         'somekey': 'somevalue'
    #         })
    # resp = post_00(
    #     url='http://bugs.python.org', 
    #     data={
    #         'number': 12524, 
    #         'type': 'issue', 
    #         'action': 'show'
    #         })
    # resp = post_00(
    #     url='http://bugs.python.org', 
    #     data=json.dumps({
    #         'some': 'data'
    #         }))
    
    # print(resp.text[:600])
    # print(pretty_print(resp.text))
    # print(resp.json())
    print(resp.status_code, resp.reason)
    print(resp.headers['content-type'])
    print(resp.encoding)
import json
import sys # for exit()

class base_00():

    def __init__(self, n):

        self.__n=n

    def get(self):

        return self.__n

    def set(self, n):

        self.__n=n

    def __repr__(self):
        pass
        # json.dumps()


def pprint(text):

    ret = json.loads(text)
    ret = json.dumps(ret, indent=4, sort_keys=True, separators=(',', ': '))

    return ret


def load_test():

    #str='{"one": "1", "two": 2, "three": [1, 2]}'
    #or
    str='{\
        "one": "1",\
        "two": 2,\
        "three": [1, 2]\
    }'

    try:
        json_00 = json.loads(str)
    except ValueError as e:
        print(e)
        sys.exit(1)

    assert json_00['one']=="1"
    assert json_00['two']==2

    assert json.dumps(json_00)=='{"three": [1, 2], "two": 2, "one": "1"}'
    assert json.dumps(json_00, indent=4, sort_keys=True, separators=(',', ': '))=="""{
    "one": "1",
    "three": [
        1,
        2
    ],
    "two": 2
}"""

def test_array_float():

    array_str = '["-13.2","14.2"]'
    try:
        array=json.loads(array_str)
    except ValueError as e:
        print(e)
        sys.exit(1)
    assert(array == [ '-13.2', '14.2' ])
    array = [ float(e) for e in array ]

if __name__ == '__main__':

    # load_test()
    test_array_float()

    print(pprint('{"three": [1, 2], "two": 2, "one": "1"}'))

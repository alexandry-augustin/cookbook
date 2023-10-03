import re

def test():

    regex=re.compile("\.py")
    assert(regex.search("asdasd.py"))

    regex=".*"+re.escape("*te.*st")+".*"
    assert(re.match(regex, "_*te.*st_"))

    # bool(regex.search(...)) #to force True/False

def test_floats(): 
    
    # https://stackoverflow.com/questions/4703390/how-to-extract-a-floating-number-from-a-string
    query = "Current Level: -13.2db or 14.2 or 3"
    regex = r"[-+]?(?:\d*\.*\d+)"
    res = re.findall(regex, query)
    assert(res == [ '-13.2', '14.2', '3' ])

    # FIXME
    # query = "[-13.2,14.2]"
    # regex = r"[-+]?(?:\d,\d+)"
    # res = re.findall(regex, query)
    # print(res)
    # assert(res == [ '-13.2', '14.2' ])

if __name__ == '__main__':

    test()
    test_floats()


try:
    raise ValueError('error')
except Exception as e:
    print(e)




try:
    raise ValueError('error')
except ValueError as e:
    print(e)




try:
    raise RuntimeError("oops")
except RuntimeError:
    print(RuntimeError)
except:
    print("except")
else:
    print("else")
finally:
    print("finally")




try:
    5/0
except ZeroDivisionError:
    print("oops")

class BaseException(Exception):
    pass


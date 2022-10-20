from enum import Enum, unique

@unique
class color(Enum):
        
    RED   = 0
    GREEN = 1
    BLUE  = 2
    
    def __str__(self):
        return str(self.value)

# class ITEM_ACTION(object):
#     def __init__(self):
#         self.INVALID   = 0
#         self.CHECK_IN  = 1
#         self.CHECK_OUT = 2

# ITEM_ACTION.INVALID

if __name__ == '__main__':
    
    print(color.RED)
    print(color.RED is color.RED)

    c = color
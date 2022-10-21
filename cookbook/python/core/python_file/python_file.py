"""
	in Python, you don't need to import any library to read and write files.
	http://www.pythonforbeginners.com/files/reading-and-writing-files-in-python
"""
import os

if __name__ == '__main__':
    print(__file__)
    print(os.path.realpath(__file__))

    f=open("file_00.txt", "w")
    f.write("hello world in the new file\n")
    f.close()

    with open('file_00.txt', 'a') as file:
        file.write('Hi there!')

    #--------------------------------------

    f=open("file_00.txt", "r")
    print(f.read()) #read entire file in a single string
    print(f.read().splitlines())
    print(f.readlines()) #return an array of strings (with \n included)
    print(f.readline()) #return a single string

    with open('file_00.txt') as file: # Use file to refer to the file object
        data = file.read()

import difflib

if __name__ == '__main__':

    some_text_a = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua." 
    some_text_b = some_text_a
    
    some_text_b = some_text_b.replace("ipsum", "ispum")

    differ = difflib.Differ()
    diff = differ.compare(some_text_a.split(), some_text_b.split())
    print('\n'.join(diff))


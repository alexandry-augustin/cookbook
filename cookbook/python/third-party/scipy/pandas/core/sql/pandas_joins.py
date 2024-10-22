import pandas as pd

def load_data():
   
    d = {'id': [1, 2, 10, 12], 
        'val1': ['a', 'b', 'c', 'd']}
    
    A = pd.DataFrame(d)

    d = {'id': [1, 2, 9, 8],
     'val1': ['p', 'q', 'r', 's']}
    
    B = pd.DataFrame(d)

    return A, B

if __name__ == '__main__':

    A, B = load_data()

    inner_join = pd.merge(A, B, on='id', how='inner')
    left_outer_join = pd.merge(A, B, on='id', how='left')
    right_outer_join = pd.merge(A, B, on='id', how='right')
    full_outer_join = pd.merge(A, B, on='id', how='outer')

    print(A)
    print(B)
    print(full_outer_join)
import pandas as pd

def example_00():

    df = pd.DataFrame({ 
        'Company': [
            'Stark Industries', 
            'Stark Industries', 
            'Stark Industries', 
            'Initech', 
            'Initech', 
            'Initech'
        ],
        'Employee Name': [
            'Tony Stark', 
            'Pepper Posts', 
            'Maria, Hill', 
            'Peter Gibbons', 
            'Bill Lumbergh', 
            'Milton Waddams'
        ],
        'Yearly Salary': [
            250, 
            180, 
            160, 
            150, 
            103, 
            0
        ] 
    })

    df_ = pd.DataFrame({ 
        'Company': [
            'Token', 
            'Token', 
            'Token'
        ],
        'Employee Name': [
            'Steve',
            'John Doe',
            'Jane Doe'
        ],
        'Yearly Salary': [
            8, 
            5, 
            10
        ] 
    })

    # df = pd.concat([df, df_])

    # df = df.sample(frac=1) # shuffle rows

    # df['mean'] = df.groupby('Company').transform('mean')

    # ---

    def f(x):
        # return 9
        # print(len(x))
        print('##################')
        print(x)
        print(type(x))
        print('##################')
        

    print('-------------------')
    print(df)
    print('-------------------')
    # df['mean_'] = 
    df.groupby('Company').transform(f)

def example_01():
    
    data = {
        'a': [ 
            'a1',
            'a2',
            'a3',
            'a4',
            'a5' ],
        'b': [ 
            'b1',
            'b1',
            'b2',
            'b2',
            'b1' ],
        'c': [ 
            55,
            44.2,
            33.3,
            -66.5,
            0 
        ],
        'd': [ 
            10,
            100,
            1000,
            10000,
            100000 
        ],
    }
    df = pd.DataFrame.from_dict(data)

    df.groupby('b')['c'].transform(sum)

    def f(x, col):
        return df.loc[x.index, col]*x

    df.groupby('b')['c'].transform(f, col='d')


    for group_name, df_group in df.groupby('b'):
        print(group_name)
        print(df_group)


    def f(x):
        print(type(x))
        print(x)
    #     print('\n')
    #     print(x)
    #     print(x.index)
    #     return df.loc[x.index,'d']*x

    # df['e'] = 
    df.groupby('b').transform(f)

if __name__ == '__main__': 

    example_00()
    # example_01()
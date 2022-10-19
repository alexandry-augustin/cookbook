import numpy as np

if __name__ == '__main__':

    a = np.array([1, 2, 3], dtype='float')

    np.ma.masked_array(a, mask=[True, True, False], fill_value=np.nan).filled()

    np.ma.masked_greater(a, 1).filled(np.nan)

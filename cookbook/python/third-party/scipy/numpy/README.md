---
title: NumPy
author: 
date: 
url: 
---

# Arrays

- same as native list but with the same data type

- numpy does not support jagged arrays natively

## Member Variables
```
ndim
shape
T       # transpose
```

## Member Functions

```
fill()
copy()       # deep copy
transpose()
tolist()
tostring()   # [deprecated]
squeeze()
all()
reshape()
```

# Matrix

## Member Functions

```
TODO
```

## Member Variables

```
TODO
```

# Functions

```python
assert(np.array_equal(b,c))  # test if same shape and same elements values
assert(np.array_equiv(b,c))  # test if broadcastable shape and same elements values
assert(np.allclose(b,c)) # test if same shape and elements have close enough values
```

```python
numpy.testing.assert_allclose()
numpy.allclose
```

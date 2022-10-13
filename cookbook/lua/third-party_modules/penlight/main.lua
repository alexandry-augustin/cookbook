-- file

file = require('pl.file')

data = file.read("TEST")

print(data)

-- strinx

stringx = require('pl.stringx')

print(stringx.replace("abc old_token", 'old_token', 'new_token'))

print(stringx.split("abc 123")) -- split by whitespace by default



cjson = require 'cjson'

function read_json(path)
  local f = io.open(path, 'r')
  local s = f:read('*all')
  f:close()
  return cjson.decode(s)
end

function write_json(path, obj)
  local s = cjson.encode(obj)
  local f = io.open(path, 'w')
  f:write(s)
  f:close()
end

json = read_json("sample.json")

print(type(json))

print(json["menu"]["value"])


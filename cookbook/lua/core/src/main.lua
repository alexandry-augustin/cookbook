-- FIX "Function table.maxn is deprecated. Write it in Lua if you really need it." -- https://www.lua.org/manual/5.2/manual.html#8.2
table.maxn = table.maxn or function(t) return #t end

----------------------------------------------------
-- Comments
----------------------------------------------------

-- this is a single line comment

--[[
     This is a
     multi-line comment.
--]]

----------------------------------------------------
-- ;
----------------------------------------------------

--[[

Only use semicolons to prevent ambiguity.
Generally only required when writing multiple statements on a line:

--]]

a=1; print(a)
a=1 print(a) -- <- works

--[[

(http://www.lua.org/manual/5.2/manual.html#3.3) Function calls and assignments can start with an open parenthesis. This possibility leads to an ambiguity in the Lua grammar. Consider the following fragment:

a = b + c (print or io.write)('done')

The grammar could see it in two ways:

a = b + c(print or io.write)('done')

a = b + c; (print or io.write)('done')

--]]

----------------------------------------------------
-- Built-in Functions
----------------------------------------------------

----------------------------------------------------
---- Assert
----------------------------------------------------

--[[

The assert function checks whether its first argument is not false and simply returns that argument; if the argument is false (that is, false or nil), assert raises an error. Its second argument, the message, is optional, so that if you do not want to say anything in the error message, you do not have to.

--]]

assert(1<2)	

assert(1>0, "error")

----------------------------------------------------
---- Print
----------------------------------------------------

print("test")
print "test"

print(1,2,3)

----------------------------------------------------
---- I/O
----------------------------------------------------

io.write('abc\n')  -- Defaults to stdout.

io.write("version: ", _VERSION, "\n")

print("Print any key to continue...")
line = io.read()  -- Reads next stdin line.

----------------------------------------------------
---- pairs(table)
----------------------------------------------------

--[[

Iteration over key-value pairs.
The order that items are returned is not defined, not even for indexed tables.

--]]

t={a=5, b=6, c=7}
--t={"a", "b", "c"}

for key,value in pairs(t) do 
    print(key,value)
end

----------------------------------------------------
---- ipairs(table)
----------------------------------------------------

--[[

Allow iteration over index-value pairs. These are key-value pairs where the keys are indices into an array.
The order in which elements are returned is guaranteed to be in the numeric order of the indices, and non-integer keys are simply skipped.

--]]

t={"a", "b", "c"}

for index,value in ipairs(t) do 
    print(index,value)
end

----------------------------------------------------
-- Variable
----------------------------------------------------

assert((1==1)==true)
assert((1==0)==false)

--[[

Only nil and false are falsy; 0 and '' are true!

All numbers are doubles.

--]]

n=5

x, y, z = 1, 2, 3, 4 -- 4 is thrown away.

----------------------------------------------------
-- Type
----------------------------------------------------

n=5
s="abc"

print(type(n))
print(type(s))

----------------------------------------------------
-- String
----------------------------------------------------

--[[

strings are immutable

--]]

print('walternate')

print("double-quotes are also fine")

----------------------------------------------------
---- multiline string
----------------------------------------------------
print([[ Double brackets
         start and end
         multi-line strings.]])

--[[

String concatenation uses the .. operator
If both operands are strings or numbers, then they are converted to strings

--]]

print('123 ' .. "abc")
print(123 .. " abc")
print(123 .. 456)

assert(string.len("abc")==3)

----------------------------------------------------
-- Nil
----------------------------------------------------

print(nil)

-- Undefined variables return nil

foo = anUnknownVariable
assert(foo==nil)

----------------------------------------------------
-- Tables
----------------------------------------------------

--[[

Tables are heterogeneous dictinaries

--]]

----------------------------------------------------
---- Size
----------------------------------------------------

t = {}
t[1] = 0
size = #t
print(size)

--[[

[Programming in Lua, Roberto Ierusalimschy ] it is customary in Lua to start arrays with index 1. The Lua libraries adhere to this convention; so does the length operator. If your arrays do not start with 1, you will not be able to use these facilities.

--]]

t = {}
-- t[0] = -- not recommended
t[1] = "abc"
t[2] = 30

for i=1,#t do
    print(i, t[i]) 
end

--

t = {}
t[0] = "abc"
t["one"] = 30
t.two=2

print(t[0])
print(t["one"])
print(t["two"])

--

t = {key1 = 'value1', key2 = false} -- the keys key1 and key2 are strings

assert(t.key1=="value1")
t[1] = "abc"
t.newKey = {}  -- Adds a new key/value pair.
t.key2 = nil   -- Removes key2 from the table.

-- Literal notation for any (non-nil) value as key:
u = {['@!#'] = 'qbert', [{}] = 1729, [6.28] = 'tau'}
assert(u[6.28]=="tau")

t={[0] = 5}

----------------------------------------------------
---- Insert
----------------------------------------------------

--[[

calling insert without a position inserts the element in the last position of the array

--]]

t = {name = 'abc', value = 123}
table.insert(t, 1, 0)
print(t)

--

t = {1, 2, 3}
table.insert(t, 1, 0) -- insert a 0 in position 1
table.insert(t, 4) -- insert a 4 at the last position
print(t)

-- Remove

t = {1, 2, 3}
table.remove(t, 1) -- remove first element
table.remove(t) -- remove last element
print(t)

----------------------------------------------------
-- _G
----------------------------------------------------

--[[

_G is a special table of all global variables

--]]

a={"a", "b", "c"}
b={1, 2, 3}
assert(_G["a"]==a)

assert(_G['_G'] == _G)	

----------------------------------------------------
-- Using tables as lists / arrays
----------------------------------------------------

--[[

List literals implicitly set up int keys
A 'list' is not a real type, it is just a table with consecutive integer keys, treated as a list.

--]]

v = {'value1', 'value2', 1.21}
for i = 1, #v do -- indices start at 1
  print(i, v[i])  
end

----------------------------------------------------
-- Member Function
----------------------------------------------------

t = {}
t.f0 = function(n)
    return n+2
end

print(t.f0(2))
-- or
--print(t["f0"](2))

--

t = {}
f0 = function(n) return n+2 end

t.f0=f0
print(t.f0(2))
-- or
--print(t["f0"](2))

----------------------------------------------------
-- Namespaces
----------------------------------------------------

--[[

By using a table to store related functions, it can act as a namespace.

--]]

Point = {}

Point.new = function (x, y)
  return {x = x, y = y}  --  return {["x"] = x, ["y"] = y}
end

Point.set_x = function (point, x)
  point.x = x  --  point["x"] = x;
end

----------------------------------------------------
-- Metamethods
----------------------------------------------------

--[[

predefined functions that can be overloaded to change functionalities

Full list: http://lua-users.org/wiki/MetatableEvents

| .           | .    |
| ----------- | ---- |
| __index     |      |
| __newindex  |      |
| __mode      |      |
| __call      |      |
| __metatable |      |
| __tostring  |      |
| __len       |      |
| __gc        |      |

Mathematic Operators

| .        | .                                                            |
| -------- | ------------------------------------------------------------ |
| __unm    |                                                              |
| __add    |                                                              |
| __sub    | Subtraction. Similar to addition, using the '-' operator.    |
| __mul    | Multiplication. Similar to addition, using the '*' operator. |
| __div    | Division. Similar to addition, using the '/' operator.       |
| __mod    | Modulo. Similar to addition, using the '%' operator.         |
| __pow    | Involution. Similar to addition, using the '^' operator.     |
| __concat | Concatenation. Similar to addition, using the '..' operator. |

Equivalence Comparison Operators

| .    | .    |
| ---- | ---- |
| __eq |      |
| __lt |      |
| __le |      |

----------------------------------------------------
---- __index
----------------------------------------------------

--[[

lets you run a custom function or use a "fallback" table if a key in a table doesn't exist.
If a function is used, its first parameter will be the table that the lookup failed on, and the second parameter will be the key.

--]]

t={ __index=function (tab, key) return "not found" end }

--t={}
--t.__index= function(tab, key) return "not found" end

print(t["a"])

--

t={}

mt = {}
function mt:__index(key)
    assert(self == t) -- self is the table for wich the lookup failed
    return "key not found" 
end

setmetatable(t, mt)

print(t["a"])

--

t={ }
mt = { __index= { a="key found!" } }  -- when __index is a table, lua redoes the access in that tabel
setmetatable(t, mt)


print(t["a"])

----------------------------------------------------
---- __add
----------------------------------------------------

t={n=3}

t.__add = function (lhs, rhs) -- "add" event handler
    return { value = lhs.value + rhs.value }
  end

--y = t + t
--print(y.value)
--print(t.m)

----------------------------------------------------
---- __call
----------------------------------------------------

t={}
setmetatable(t, { __call=function () print("called") end })
t()

--

----------------------------------------------------
-- Metatables
----------------------------------------------------

--[[

a metatable is a normal table that attaches itself to another normal table to add extra functionalities

--]]

t={n=1}
mt={n=10}
ret = setmetatable(t, mt) --return t with mt as metatable

print(t.n)
print(getmetatable(t).n)
print(ret.n)
print(getmetatable(ret).n)
assert(ret == t)
assert(tostring(ret) == tostring(t)) -- compare memory address

--[[

https://www.lua.org/pil/13.html

Usually, tables in Lua have a quite predictable set of operations. We can add key-value pairs, we can check the value associated with a key, we can traverse all key-value pairs, and that is all. We cannot add tables, we cannot compare tables, and we cannot call a table.

Metatables allow us to change the behavior of a table. For instance, using metatables, we can define how Lua computes the expression a+b, where a and b are tables. Whenever Lua tries to add two tables, it checks whether either of them has a metatable and whether that metatable has an __add field. If Lua finds this field, it calls the corresponding value (the so-called metamethod, which should be a function) to compute the sum.

Each table in Lua may have its own metatable. (userdata also can have metatables).
Lua always create new tables without metatables:

--]]

t = {}
assert(getmetatable(t)==nil)

-- A table can be its own metatable (so that it describes its own individual behavior).

t={ n=5 }

t.__add = function (lhs, rhs)
-- OR
--function t.__add(lhs, rhs)
    return { n = lhs.n + rhs.n }
  end

setmetatable(t, t)

y = t + t

assert(y.n==10)

--

t={ n = 5 }

mt = {
  __add = function (lhs, rhs)
    return { n = lhs.n + rhs.n }
  end
}

setmetatable(t, mt)

y = t + t

assert(y.n==10)

--

t1 = { 1, 2, 3 }

setmetatable(t1, {
   __add = function(lhs, rhs)
      for i = 1, table.maxn(rhs) do
         table.insert(lhs, table.maxn(lhs)+1, rhs[i])
      end
      return lhs
   end
})

t2 = { 4,5,6 }

t3 = t1 + t2

for k,v in ipairs(t3) do
   print(k, v)
end

--

t1= {}
t2={ n = 1 }
mt = { __index = t2 } --fallback table when index can't be found?

setmetatable(t1, mt)

assert(t1.n==1)

----------------------------------------------------
-- Classes
----------------------------------------------------

--[[

Although Lua does not have a built-in concept of classes, they can be implemented using two language features: first-class functions and tables. By placing functions and related data into a table, an object is formed.

Inheritance (both single and multiple) can be implemented via the metatable mechanism, telling the object to look up nonexistent methods and fields in parent object(s).

Lua is a prototype-based languages (like Self and NewtonScript). In those languages, each object is not an instance of a specific class. Instead, each object may have a prototype, which is a regular object where the first object looks up any operation that it does not know about. To represent a class in such languages, we simply create an object to be used exclusively as a prototype for other objects (its instances). Both classes and prototypes work as a place to put behavior to be shared by several objects.

Declaring member functions:

> function tablename:fn(...)
> is the same as
> function tablename.fn(self, ...)

--]]

----------------------------------------------------
---- Prototype
----------------------------------------------------

--[[

make b a prototype for a:

After that, a looks up in b for any operation that it does not have.

--]]

a={}
b={n=10}
setmetatable(a, {__index = b})
assert(a.n==10)

--

base = {}
base.__index = base  --  failed table lookups on the instances should fallback to the class table

function base:new(n) -- factory method that create a new object with the table base (self) as prototype
-- or
-- function base.new(self, ...)
  assert(self == base)
  newObj = {n = n} -- instance of class base
  return setmetatable(newObj, self) --return the new object with base as metatable
end

function base:get_n()
  assert(self ~= base) -- self is the instance, not the prototype
  print(self:print_n()) -- calling self.print_n() will fail
  return self.n
end

function base:print_n()
    print(self.n)
end

b = base:new(1)
assert(b:get_n()==1)

----------------------------------------------------
---- Inheritance
----------------------------------------------------

-- TODO

----------------------------------------------------
-- Operators
----------------------------------------------------

----------------------------------------------------
---- not equal
----------------------------------------------------

assert(1~=2)

assert(1==1)

----------------------------------------------------
---- .. operator
----------------------------------------------------

----------------------------------------------------
---- ternary (a?b:c)
----------------------------------------------------

aBoolValue=true
ans = aBoolValue and 'yes' or 'no'
assert(ans=="yes")

----------------------------------------------------
---- exponentiation
----------------------------------------------------

assert(9^2==81)

----------------------------------------------------
-- Control Flow
----------------------------------------------------

----------------------------------------------------
---- While loop
----------------------------------------------------

num=0
while num < 50 do
  num = num + 1  -- No ++ or += type operators.
end

----------------------------------------------------
---- if
----------------------------------------------------

num=50
s="sdf"
if num > 40 then
  print('over 40')
elseif s ~= 'walternate' then
  print('not over 40\n')
else
  thisIsGlobal = 5
end

----------------------------------------------------
---- foreach
----------------------------------------------------

--t={ zero=0, one=1 }
t={"one", "two", "three"}

print(#t)

for k,v in ipairs(t) do
   print(k,v)
end

----------------------------------------------------
---- range (begin, end[, step])
----------------------------------------------------

karlSum = 0
for i = 1, 100 do  -- The range includes both ends.
  karlSum = karlSum + i
end

-- Use "100, 1, -1" as the range to count down:
fredSum = 0
for j = 100, 1, -1 do fredSum = fredSum + j end

----------------------------------------------------
---- repeat
----------------------------------------------------

num=10
repeat
  num = num - 1
until num == 0

----------------------------------------------------
---- Table iteration
----------------------------------------------------

t = {key1 = 'value1', key2 = false}

for key, val in pairs(t) do
  print(key, val)
end

----------------------------------------------------
-- Functions
----------------------------------------------------

function f(n)
    return n+1
end
print(f(2))

----------------------------------------------------
---- function object
----------------------------------------------------

g=function (n) return n+2 end
print(g(2))

-- These are the same:

function f(n) return n+1 end
f = function (n) return n+1 end

-- A `one-table-parameter` function call does not need parentesis:

function f(x) print(x.key1) end

f({key1 = 'abc'})
-- or
f{key1 = 'abc'}

--

if False then
    a = {p = print}
    a.p("Hello World") --> Hello World
    print = math.sin  -- `print' now refers to the sine function
    a.p(print(1))     --> 0.841470
    sin = a.p         -- `sin' now refers to the print function
    sin(10, 20)       --> 10      20
end

-- Because functions are first-class values in lua, we can store them in table fields:

t={ n=1, add=function (n) return n+1 end }

assert(t.add(t.n)==2)

--

t={ n=1 }

t.add=function (n) return n+1 end

assert(t.add(t.n)==2)

--

t = { n=1 }

--function t.add(self)
--or
--t.add=function (self)
--    self.n=self.n+1
--end    
--or
function t:add()
    self.n=self.n+1
end

t:add()
t.add(t)

assert(t.n==3)

-- Tables are always passed by reference

a_table = {x = 10}
assert(a_table["x"]==10)

b_table = a_table
b_table["x"] = 20

assert(b_table["x"]==20)
assert(a_table["x"]==20)

--

function f(t)
    t.n=t.n+1
end

t={ n=1 }
f(t)

assert(t.n==2)

----------------------------------------------------
-- Argument Binding
----------------------------------------------------

function add1(a)
   return a+1
end

function bind(f, a)
   return function() return f(a) end
end

local f = bind(add1, 4)
print(f())

--

function add(a, b)
   return a+b
end

function bind(f, b)
   return function(a) return f(a, b) end
end

local add1 = bind(add, 1)
print(add1(10))

----------------------------------------------------
-- Closure
----------------------------------------------------

function add(n)
    return m+n
end

m=5
assert(add(1)==6)

--

function addTo(n)
    ret=function (m)
        return n+m
    end
    return ret 
end

addToOne=addTo(1)
addToTwo=addTo(2)

assert(addToOne(1)==2)
assert(addToTwo(2)==4)

----------------------------------------------------
-- Modules
----------------------------------------------------

--[[

a collection of modules is a package

lua equivalent to namespaces

"require" is the standard way to include modules.

require acts like:
local mod = (function ()
[contents of mod.lua]
end)()
It's like mod.lua is a function body, so that

locals inside mod.lua are invisible outside it.

--]]

mod = require('mod') -- run the file mod.lua
-- or
require("mod")

print(mod)
print(base_math)
print(type(mod))
mod.add(2, 4)

----------------------------------------------------
-- Variable Scope
----------------------------------------------------

--[[

Variables are global by default

--]]

local line = "sfd"

if true then
    n=5 --global
    local m=6
    
    if true then
        assert(m==6)
    end
end
assert(n==5)
--assert(m==nil)

function f()
    n=5 --global
    local m=6
end
--assert(n==5)
--assert(m==nil)

----------------------------------------------------
-- Date / Time
----------------------------------------------------

--[[

number of seconds since some epoch

--]]

os.time()

os.date()

--[[

wday: week day (1 is Sunday)
yday: year day (1 is January 1)

--]]

os.date("*t", os.time())

--[[

%a abbreviated weekday name (e.g., Wed)
%A full weekday name (e.g., Wednesday)
%b abbreviated month name (e.g., Sep)
%B full month name (e.g., September)
%c date and time (e.g., 09/16/98 23:48:10) -- DEFAULT
%d day of the month (16) [01-31]
%H hour, using a 24-hour clock (23) [00-23]
%I hour, using a 12-hour clock (11) [01-12]
%M minute (48) [00-59]
%m month (09) [01-12]
%p either "am" or "pm" (pm)
%S second (10) [00-61]
%w weekday (3) [0-6 = Sunday-Saturday]
%x date (e.g., 09/16/98)
%X time (e.g., 23:48:10)
%Y full year (1998)
%y two-digit year (98) [00-99]
%% the character `%´

--]]

print(os.date("today is %A, in %B"))	

print(os.date("%x", os.time()))

print(os.date("%Y%m%d_%Hh%Mm%Ss", os.time()))

-- os.clock() returns the number of seconds of CPU time for the program.

local x = os.clock()
local s = 0
for i=1,100000 do s = s + i end
print(string.format("elapsed time: %.2f\n", os.clock() - x))

----------------------------------------------------
-- unpack()
----------------------------------------------------

--[[

An important use for unpack is in a generic call mechanism. A generic call mechanism allows you to call any function, with any arguments, dynamically.

--]]

a,b = table.unpack{10,20,30} -- a=10, b=20, 30 is discarded

--

function f(a,b,c) 
    return a+b+c
end

args={1,2,3}
assert(f(table.unpack(args))==6)

----------------------------------------------------
-- Local
----------------------------------------------------

local n=0
while n<3 do
  --print(n)
  n=n+1
end

local inspect = require('inspect')

print(inspect({1,2,3})) -- {1, 2, 3}
print(inspect({a=1,b=2}))
-- {
--   a = 1
--   b = 2
-- }

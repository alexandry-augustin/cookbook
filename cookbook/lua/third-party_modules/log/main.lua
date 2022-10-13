log = require("log")

local function main()
	log.outfile = "LOG"
	log.trace("test")
end

main()

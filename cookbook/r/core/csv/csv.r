#help(read.scv)

#WRITING
aa=matrix(c(1000,110,10,1, 
              0,2000,20,2, 
              30,300,3000,30000)
	, nrow=3
	, byrow=TRUE
	, dimnames=list(NULL, c("C1", "C2", "C3","C4")))

#write.csv(MyData, file = "out.csv", row.names=TRUE)
write.table(aa
		, file="out.csv"
		, row.names=FALSE
		, na=""
		, col.names=TRUE
		, sep=";")

# READING
data <- read.csv("data.csv", sep=";", header=TRUE, nrows=-1) #returns a data frame
data

#Unlike an array, the data you store in the columns of a data frame can be of various types. 
#All columns have to be the same length
#----------------------------------------------------------
# create empty dataframe
# https://stackoverflow.com/questions/10689055/create-an-empty-data-frame

df <- data.frame(Date=as.Date(character()),
                 File=character(), 
                 User=character(), 
                 stringsAsFactors=FALSE) 

#----------------------------------------------------------
a <- c(1, 2, 3, 4)
b <- c("red", "white", "red", NA)
c <- c(TRUE, TRUE, TRUE, FALSE)
frame <- data.frame(a, b, c)

names(frame) <- c("ID", "Color", "Passed") # variable names 
names <- colnames(frame)
str(frame) #print structure of the frame
stop()

#columns
#frame[1:2]
#frame[c("ID","Color")]
#frame["ID"]
#frame[["ID"]]
#frame["ID"][,1]
#frame$a
#frame$"Color"

#rows
#frame[3,]
#frame[c(3,4),]
#frame[3,][,1]
#----------------------------------------------------------
a <- c(1, 2, 3)
b <- c(4, 5, 6)
frame <- data.frame(a, b)


stopifnot(frame[1:2]==c(a,b))
#temp <- frame[1:2]
#temp[2,2]

frame[2,][,]

a <- data.matrix(frame) #convert to matrix
#----------------------------------------------------------
# array to data frame
a <- array(0, dim=c(2,4,2))

as.data.frame(as.table(a))
#or
as.data.frame.table(a) 
#----------------------------------------------------------
# matrix to data frame
x <- matrix(1:6, ncol=2, dimnames=list(LETTERS[1:3], letters[24:25]))
frame <- data.frame(x)

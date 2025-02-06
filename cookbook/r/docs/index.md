---
title: R
author: 
date: 
url: 
---

# Installation

```bash
sudo dnf install R

sudo apt-get install r-base
```

# Syntax

| Quit           | `q()`                                                        |
| -------------- | ------------------------------------------------------------ |
| Help           | `help.start()`                                               |
|                | `help(t.test)` or `?t.test`                                  |
|                | `apropos("keyword")`                                         |
| Comment        | `#`                                                          |
| Assignment     | `x  <-  5 #  assigns  5  to  x`<br>`7  ->  z         #  assigns  7  to  z` |
| List variables | `ls()`                                                       |
| Vector         | `c(...,...) 1:10`                                            |

## Dataframes

`head(dataframe)`: 
`tail(dataframe)`: 
`subset(dataframe, CONDITION)`: 
`names(dataframe)`: get columns names
`summary(dataframe)`: 
`unique(dataframe)`: 
`replace(df$col, df$col<0, 0)`: replaces the negative numbers with zeros

`nrow(dataframe)`: 
`ncol(dataframe)`: 
`length(dataframe)`: 
`dim(dataframe)`: 

`rbind(dataframe, dataframe)`: concat

# Binaries

## R

`R --version`

`R --slave --vanilla < script.r`

## Rscript

`Rscript script.r`

# REPL

`?[cmd_name] #help`


setwd() will set the current working directory to a specific location
getwd() will print out the current directory.

load("survey.rdata")


# Packages

Convergence Diagnostic and Output Analysis (CODA)

- `dplyr`

# R Notebook Kernel

[install anaconda]	
- `wget https://3230d63b5fc54e62148e-c95ac804525aac4b6dba79b00b39d1d3.ssl.cf1.rackcdn.com/Anaconda-2.3.0-Linux-x86_64.sh`
`bash Anaconda-2.3.0-Linux-x86_64.sh`
	
- `conda install jupyter`
- `conda create -n my-r-env -c r r-essentials`
- `source activate my-r-env`
- `ipython notebook&`

## IRKernel

```
conda install jupyter_client
install.packages('IRkernel')
IRkernel::installspec()  # to register the kernel in the current R installation
```

shift+enter	run

# Converte from S-Plus (from OpenBugs) to R dump format (from JAGS)

```R
library(coda)    # Load coda package
bugs2jags('ratDataSplusFormat.txt', 'ratDataJAGSFormat.txt')  #run bugs2jags


read.coda(output.file, index.file, start, end, thin, quiet=FALSE)
read.jags(file = "jags.out", start, end, thin, quiet=FALSE)
```

# Tidyverse

follows the 'Tidy data' philosophy

`install.packages("tidyverse")`
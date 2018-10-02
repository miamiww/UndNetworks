library(tidyverse)

filelocations = "/Users/aljones/ITP/Year2/1Semester/UndNetworks/2Week/"
dlpath <- list.files(path = filelocations)
dlpath <- paste(filelocations,  dlpath, sep="")
all_traces <- lapply(dlpath,function(x) read.csv(x, header=FALSE))

do.call(rbind, all_traces)

all_traces  <-  sapply(all_traces,function(x) rbind.fill(x))

all_traces2 <- as.data.frame(lapply(all_traces, function(x) cbind(x)))

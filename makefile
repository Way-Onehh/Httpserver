#暴露的参数
export name

#目录
BIN=bin
CPP=cpp
TEMP=temp
TEST=test
MAKEI=make

vpath %test.cpp $(TEST)
vpath %.cpp 	$(CPP)
vpath %.o 		$(TEMP)

#配置
CC=g++
FLAG=-g

#链接make文件
include $(MAKEI)/link.mak
#链接实现文件
include $(MAKEI)/*

#自动化配置
ALL:

.PHONY:name

add:
	touch  $(CPP)/$(name).cpp
	touch  $(MAKEI)/$(name).mk
	touch  $(TEST)/$(name)test.cpp
	touch  $(name).h
	echo   "$(name).test=$(name).o $(name)test.o ">> $(MAKEI)/link.mak
del:
	rm   $(CPP)/$(name).cpp
	rm   $(MAKEI)/$(name).mk
	rm   $(TEST)/$(name)test.cpp
	rm   $(name).h
	grep -v $(name) $(MAKEI)/link.mak  >  $(MAKEI)/link.pipe
	cp   $(MAKEI)/link.pipe $(MAKEI)/link.mak
	rm   $(MAKEI)/link.pipe
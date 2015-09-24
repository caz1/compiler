SHELL = /bin/sh
CC = g++
LEX = flex
PROGRAM = c1c
BIN = bin
SRC = src
TEST = test
CONF = config
CFLAGS = 
LFLAGS =
YFLAGS =

default:: ${BIN}/c1c ${BIN}/toy

${BIN}/toy: ${SRC}/toy.cpp
	mkdir -p ${BIN}
	@${CC} ${CFLAGS} -o $@ $^

${BIN}/c1c: ${BIN}/lexer.o ${BIN}/main.o
	mkdir -p ${BIN}
	@${CC} ${CFLAGS} -o $@ $^

${SRC}/lexer.cpp: ${SRC}/c1.lex
	mkdir -p \${SRC}
	@${LEX} ${LFLAGS} -o $@ $<

${BIN}/lexer.o: ${SRC}/lexer.cpp ${SRC}/token.h
	mkdir -p ${SRC}
	@${CC} ${CFLAGS} -c -o $@ $<

${BIN}/main.o: ${SRC}/main.c ${SRC}/token.h
	mkdir -p ${SRC}
	@${CC} ${CFLAGS} -c -o $@ $<

run:
	${BIN}/toy < ${TEST}/testForToy >> log
	${BIN}/c1c  ${TEST}/prime.c	>> log
	${BIN}/c1c  ${TEST}/sort.c	>> log
	${BIN}/c1c  ${TEST}/gcd.c	>> log



.PHONY: clean
clean:
	-rm -f ${BIN}/* ${SRC}/lexer.cpp

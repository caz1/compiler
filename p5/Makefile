CINC	 = -Iinclude
CONF	 = config
SRC	 = src
BIN	 = bin
UTILSRC  = $(SRC)/error.c $(SRC)/list.c $(SRC)/ast.c $(SRC)/dumpdot.c
TEST    = test
ALLDOT = prime.dot sort.dot gcd.dot 
ALLPIC = prime.png sort.png gcd.png 

CC       = gcc -g $(CINC) 
LEX      = flex -i -I 
YACC     = bison -d -y -v

all: c1

# Generates a parser for an c1 programming language
c1:	$(CONF)/c1.y $(CONF)/c1.lex
	@mkdir -p $(BIN)
	@$(YACC) -b c1 -o $(SRC)/c1.tab.c $(CONF)/c1.y
	@$(LEX) -o$(SRC)/c1.lex.c $(CONF)/c1.lex
	@$(CC) $(CINC) -o $(BIN)/c1 $(SRC)/c1.lex.c $(SRC)/c1.tab.c  $(SRC)/symtab.c $(SRC)/main.c $(UTILSRC) -ll -lm -w

run: $(ALLDOT) $(ALLPIC) witherror

$(ALLDOT): %.dot: $(TEST)/%.c
	$(BIN)/c1 -d $@ $< >>log

$(ALLPIC): %.png:   %.dot
	dot -Tpng $< -o $@
witherror:
	$(BIN)/c1 -d error.dot  $(TEST)/error.c
	$(BIN)/c1 -d prime.dot  $(TEST)/prime.c

clean:
	rm -f *.BAK *.o core *~* *.a log
	rm -f $(SRC)/*.tab.h $(SRC)/*.tab.c
	rm -f $(SRC)/*.lex.c $(SRC)/*.output
	rm -f $(BIN)/*
	rm -f *.dot *.png 

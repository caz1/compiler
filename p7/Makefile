CINC	 = -I include
CONF	 = config
SRC	 = src
BIN	 = bin
UTILSRC  = $(SRC)/err.cc $(SRC)/dumpdot.cc $(SRC)/codegen.cc $(SRC)/cal.cc
TEST    = test
TESTSRC = test/prime.c test/sort.c test/gcd.c test/and.c
ALLTEST = bin/prime bin/sort bin/gcd bin/and
ALLMID 	= bin/prime.o bin/sort.o bin/gcd.o bin/and.o
ALLLLVM = bin/prime.ll bin/sort.ll bin/gcd.ll bin/and.ll
LLVMFLAG = `llvm-config --cxxflags --ldflags --system-libs --libs core native|sed 's/-fno-rtti//'`
CC       = clang++ -g $(CINC) 
LEX      = flex -i -I 
YACC     = bison -d -y -v
CFLAGS	 = -std=c++11 -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS
all: bin/c1 bin/lib.a

# Generates a parser for an c1 programming language
bin/c1:	bin/lexer.o bin/parser.o bin/main.o bin/err.o bin/codegen.o bin/cal.o bin/dumpdot.o bin/llvm.o
	@mkdir -p $(BIN)
	@$(CC) $(CFLAGS)  -o $@ $^ $(LLVMFLAG)

bin/cal.o: src/cal.cc include/node.hh include/global.hh include/llvmhead.hh
	@$(CC) $(CFLAGS)  -c -o $@ $<

bin/codegen.o: src/codegen.cc include/node.hh src/c1.tab.hh include/llvmhead.hh
	@$(CC) $(CFLAGS) -c -o $@ $<
	
bin/lexer.o: src/c1.lex.cc src/c1.tab.hh include/node.hh
	@mkdir -p $(BIN)
	@$(CC) $(CFLAGS) -c -o $@ $<

bin/parser.o:  src/c1.tab.cc include/node.hh include/util.hh include/global.hh
	@$(CC) $(CFLAGS) -c -o $@ $<

src/c1.lex.cc: $(CONF)/c1.lex
	@$(LEX) -o $(SRC)/c1.lex.cc $(CONF)/c1.lex

src/c1.tab.cc src/c1.tab.hh:$(CONF)/c1.y 
	@$(YACC) -b c1 -o $(SRC)/c1.tab.cc $(CONF)/c1.y

bin/main.o: src/main.cc include/util.hh include/global.hh include/node.hh src/c1.tab.hh
	@$(CC) $(CFLAGS) -c -o $@ $< 

bin/err.o: src/err.cc include/node.hh src/c1.tab.hh include/errcfg.hh include/err.hh
	@$(CC) $(CFLAGS)  -c -o $@ $< 

bin/dumpdot.o: src/dumpdot.cc include/dumpdot.hh include/node.hh include/llvmhead.hh
	@$(CC) $(CFLAGS)  -c -o $@ $< 

bin/llvm.o: src/llvm.cc include/llvmhead.hh
	@$(CC) -std=c++11 -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS $(LLVMFLAG) -c -o $@ $<
bin/lib.o: src/lib.c
	@clang -c -o $@ $<
bin/lib.a: bin/lib.o
	@ar rcs $@ $<	

run: $(ALLTEST) witherror
	./run.sh
witherror: test/test.c
	$(BIN)/c1  $< 
	
$(ALLTEST): bin/% : bin/%.o
	clang $< bin/lib.a -o $@ 

$(ALLMID): bin/%.o : bin/%.ll
	llc -filetype=obj $< -o $@
	
$(ALLLLVM): bin/%.ll : test/%.c
	$(BIN)/c1  $< 2> $@

clean:
	rm -f *.BAK *.o core *~* *.a log
	rm -f $(SRC)/*.tab.hh $(SRC)/*.tab.cc
	rm -f $(SRC)/*.lex.cc $(SRC)/*.output
	rm -f $(BIN)/*
	rm -f *.ll 
	rm -f *.dot *.png 

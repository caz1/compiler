#ifndef LOC_H_
#define LOC_H_






typedef struct location {
	int first_line;
	int first_column;
	int last_line;
	int last_column;
} *Loc;

Loc	setLoc(ASTNode node, Loc loc);


#endif

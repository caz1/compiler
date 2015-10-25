#ifndef ERROR_H_
#define ERROR_H_

#include <map>
#include <string>

enum{
		MissVarType, 
		MissLPar,
		MissRPar,
		MissOp
	} erorKind;

map<int, string> ERR;

ERR[MissVarType] = "missing variable type @";
ERR[MissLPar] = "missing '(' @";
ERR[MissRPar] = "missing ')' @";
ERR[MissOp] = "missing operator @";

class error{
	bool isWarning;
	int kind;
	int line, column;
public:
	error(int );
	

#ifndef TOKEN_H_
#define TOKEN_H_


#define NUL	0
#define NUMBER	1
#define ID	2
#define PLUS	3
#define MINUS	4
#define MULT	5
#define DIV	6	
#define MOD	7
#define EQ	8
#define NE	9
#define LT	10	
#define LE	11
#define GT	12	
#define GE	13
#define MAIN	14
#define QUOTE	15	//'"'
#define SLASH	16	
#define COMMA	17
#define SEMICOLON	18	//';'
#define LBRACKET	19	//'['
#define RBRACKET	20	//']'
#define LPAR	21	//'('
#define RPAR	22	//')'
#define LBRACE	23	//'{'
#define RBRACE	24	//'}'
#define WHILE	25
#define IF	26	
#define CONST	27
#define INT	28
#define ELSE	29
#define ISEQ	30	// "=="



#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;

extern int num;
extern char *identifier;



#endif

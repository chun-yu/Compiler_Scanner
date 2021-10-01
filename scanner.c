//scanner HW
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isprep(char *val);
bool stringSC(char *val);
bool stringBeginMC(char *val);
bool stringEndMC(char *val);
bool isSpec(char *val);
/*
code by chun-yu
Don't copy!!
All rights reserved, reprints must investigate
*/
int main()
{
    int count = 1;
    FILE *file = fopen("sample.c", "r");
    FILE *fp = fopen("output.txt", "wb");

    bool inMC = false;
    int bigParenthesis = 0;
    char row[300];

    while (fgets(row, sizeof(row), file))
    {
    	int x =0;
        bool inStr = false;
        bool inChr = false;
        bool meetIDEN = false;
        bool meetRev = false;
        bool meetOper = false;
        bool printed = false;
        char temp[10];
		char temp2[200] ;
        //先從會整行涵括的開始 
		if (stringSC(row))
        {
            fprintf(fp, "%d |  SC   %s", count, row);
            printf("%d |  SC   %s", count, row);
        }
        else if (stringBeginMC(row))
        {
            inMC = true;
            fprintf(fp, "%d |  MC   %s", count, row);
            printf("%d |  MC   %s", count, row);
        }
        else if (stringEndMC(row))
        {
            inMC = false;
            fprintf(fp, "%d |  MC   %s", count, row);
            printf("%d |  MC   %s", count, row);
        }
        else if (inMC)
        {
            fprintf(fp, "%d |  MC   %s", count, row);
            printf("%d |  MC   %s", count, row);
        }
        else if (isprep(row))
        {
            fprintf(fp, "%d |  PREP   %s", count, row);
            printf("%d |  PREP   %s", count, row);
        }
        else
        {
        	if(isSpec(row)){
        		int x = 0;	int z = 0;
        		while(row[x]!='\n'){
        			if (row[x] == '{'){
        				fprintf(fp, "%d |  PREP   %s\n", count, "{");
            			printf("%d |  PREP   %s\n", count, "{");
					}
				    else if (row[x] == '}'){
        				fprintf(fp, "%d |  PREP   %s\n", count, "}");
            			printf("%d |  PREP   %s\n", count, "}");
					}
				    else if (row[x] == '('){
        				fprintf(fp, "%d |  PREP   %s\n", count, "(");
            			printf("%d |  PREP   %s\n", count, "(");
					}
				    else if (row[x] == ')'){
        				fprintf(fp, "%d |  PREP   %s\n", count, ")");
            			printf("%d |  PREP   %s\n", count, ")");
					}
				    else if (row[x] == ';'){
        				fprintf(fp, "%d |  PREP   %s\n", count, ";");
            			printf("%d |  PREP   %s\n", count, ";");
					}else{
						switch(row[x]){
						case '+':
							if(row[x+1]=='+'){
            				fprintf(fp, "%d |  OPER   %s\n", count, "++");
            				printf("%d |  OPER   %s\n", count, "++"); x++;
							}else if(row[x+1]=='='){
            				fprintf(fp, "%d |  OPER   %s\n", count, "+=");
            				printf("%d |  OPER   %s\n", count, "+="); x++;
							}else{
							fprintf(fp, "%d |  OPER   %s\n", count, "+");
            				printf("%d |  OPER   %s\n", count, "+");
							}
		                    break;
		                case '-':
		                	if(row[x+1]=='-'){
            				fprintf(fp, "%d |  OPER   %s\n", count, "--");
            				printf("%d |  OPER   %s\n", count, "--"); x++;
							}else if(row[x+1]=='='){
            				fprintf(fp, "%d |  OPER   %s\n", count, "-=");
            				printf("%d |  OPER   %s\n", count, "-="); x++;
							}else if(row[x+1]=='>'){
            				fprintf(fp, "%d |  OPER   %s\n", count, "->");
            				printf("%d |  OPER   %s\n", count, "->"); x++;
							}else{
							fprintf(fp, "%d |  OPER   %s\n", count, "-");
            				printf("%d |  OPER   %s\n", count, "-");
							}
		                    
            				break;
		                case '*':
		                	if(row[x+1]=='='){
            				fprintf(fp, "%d |  OPER   %s\n", count, "*=");
            				printf("%d |  OPER   %s\n", count, "*="); x++;
							}else{
		                    fprintf(fp, "%d |  OPER   %s\n", count, "*");
            				printf("%d |  OPER   %s\n", count, "*");
            				}
            				break;
		                case '/':
		                    if(row[x+1]=='='){
            				fprintf(fp, "%d |  OPER   %s\n", count, "/=");
            				printf("%d |  OPER   %s\n", count, "/="); x++;
							}else{
		                    fprintf(fp, "%d |  OPER   %s\n", count, "/");
            				printf("%d |  OPER   %s\n", count, "/");
            				}
            				break;
            			case ',':
		                    fprintf(fp, "%d |  OPER   %s\n", count, ",");
            				printf("%d |  OPER   %s\n", count, ",");
            				break;
            			case '=':
		                    if(row[x+1]=='='){
            				fprintf(fp, "%d |  OPER   %s\n", count, "==");
            				printf("%d |  OPER   %s\n", count, "=="); x++;
							}else{
		                    fprintf(fp, "%d |  OPER   %s\n", count, "=");
            				printf("%d |  OPER   %s\n", count, "=");
            				}
            				break;
            			case '%':
		                    if(row[x+1]=='='){
            				fprintf(fp, "%d |  OPER   %s\n", count, "%=");
            				printf("%d |  OPER   %s\n", count, "%="); x++;
							}else{
		                    fprintf(fp, "%d |  OPER   %s\n", count, "%");
            				printf("%d |  OPER   %s\n", count, "%");
            				}
            				break;
            			case '!':
		                    if(row[x+1]=='='){
            				fprintf(fp, "%d |  OPER   %s\n", count, "!=");
            				printf("%d |  OPER   %s\n", count, "!="); x++;
							}else{
		                    fprintf(fp, "%d |  OPER   %s\n", count, "!");
            				printf("%d |  OPER   %s\n", count, "!");
            				}
            				break;
            			case '[':
		                    fprintf(fp, "%d |  OPER   %s\n", count, "[");
            				printf("%d |  OPER   %s\n", count, "[");
            				break;
            			case ']':
		                    fprintf(fp, "%d |  OPER   %s\n", count, "]");
            				printf("%d |  OPER   %s\n", count, "]");
            				break;
            			case '|':
		                    if(row[x+1]=='|'){
            				fprintf(fp, "%d |  OPER   %s\n", count, "||");
            				printf("%d |  OPER   %s\n", count, "||"); x++;
							}else{
		                    fprintf(fp, "%d |  OPER   %s\n", count, "|");
            				printf("%d |  OPER   %s\n", count, "|");
            				}
            				break;
            			case '^':
		                    fprintf(fp, "%d |  OPER   %s\n", count, "^");
            				printf("%d |  OPER   %s\n", count, "^");
            				break;
            			case '.':
		                    fprintf(fp, "%d |  OPER   %s\n", count, ".");
            				printf("%d |  OPER   %s\n", count, ".");
            				break;
            			case '>':
            				if(row[x+1]=='>'){
            				fprintf(fp, "%d |  OPER   %s\n", count, ">>");
            				printf("%d |  OPER   %s\n", count, ">>"); x++;
							}else if(row[x+1]=='='){
            				fprintf(fp, "%d |  OPER   %s\n", count, ">=");
            				printf("%d |  OPER   %s\n", count, ">="); x++;
							}else{
							fprintf(fp, "%d |  OPER   %s\n", count, ">");
            				printf("%d |  OPER   %s\n", count, ">");
							}
            				break;
            			case '<':
            				if(row[x+1]=='<'){
            				fprintf(fp, "%d |  OPER   %s\n", count, "<<");
            				printf("%d |  OPER   %s\n", count, "<<"); x++;
							}else if(row[x+1]=='='){
            				fprintf(fp, "%d |  OPER   %s\n", count, "<=");
            				printf("%d |  OPER   %s\n", count, "<="); x++;
							}else{
							fprintf(fp, "%d |  OPER   %s\n", count, "<");
            				printf("%d |  OPER   %s\n", count, "<");
							}
            				break;
            			case ':':
		                    fprintf(fp, "%d |  PER   %s\n", count, ":");
            				printf("%d |  OPER   %s\n", count, ":");
            				break;
            			case '&':
		                    if(row[x+1]=='&'){
            				fprintf(fp, "%d |  OPER   %s\n", count, "&&");
            				printf("%d |  OPER   %s\n", count, "&&"); x++;
							}else if(row[x+1]==','){
            				fprintf(fp, "%d |  OPER   %s\n", count, "&,");
            				printf("%d |  OPER   %s\n", count, "&,"); x++;
							}else{
		                    fprintf(fp, "%d |  OPER   %s\n", count, "&");
            				printf("%d |  OPER   %s\n", count, "&");
            				}
            				break;
            			case '"':
		                    fprintf(fp, "%d |  STR    \"", count);
            				printf("%d |  STR    \"", count);
            				for(x=x+1;row[x] != '"';x++){
								fprintf(fp, "%c", row[x]);
            					printf("%c", row[x]);
							}
							fprintf(fp, "\"\n");
            				printf("\"\n");
            				break;
            			case '\'':
		                    fprintf(fp, "%d |  STR    \'", count);
            				printf("%d |  STR    \'", count);
            				for(x=x+1;row[x] != '\'' ;x++){
								fprintf(fp, "%c", row[x]);
            					printf("%c", row[x]);
							}
							fprintf(fp, "\'\n");
            				printf("\'\n");
            				break;
            			case 'i':
		                    if(row[x+1]=='f'){
            				fprintf(fp, "%d |  REWD   %s\n", count, "if");
            				printf("%d |  REWD   %s\n", count, "if"); x++;
							}else if(row[x+1]=='n'&&row[x+2]=='t'){
							fprintf(fp, "%d |  REWD   %s\n", count, "int");
            				printf("%d |  REWD   %s\n", count, "int"); x=x+2;
							}else{
								fprintf(fp, "%d |  IDEN    ", count);
            					printf("%d |  IDEN    ", count);
								while((row[x]>='A'&&row[x]<='Z')||(row[x]=='_')||(row[x]>='a'&& row[x]<='z')){
                            		fprintf(fp, "%c", row[x]);
            						printf("%c", row[x]);
                            		x++;
                       			}
                       			x--;
                       			fprintf(fp, "\n");
            					printf("\n");
							}
            				break;
            			case 'e':
		                    if(row[x+1]=='l'&&row[x+2]=='s'&&row[x+3]=='e'){
            				fprintf(fp, "%d |  REWD   %s\n", count, "else");
            				printf("%d |  REWD   %s\n", count, "else"); x=x+3;
							}else if(row[x+1]=='x'&&row[x+2]=='t'&&row[x+3]=='e'&&row[x+4]=='r'&&row[x+5]=='n'){
							fprintf(fp, "%d |  REWD   %s\n", count, "extern");
            				printf("%d |  REWD   %s\n", count, "extern"); x=x+5;
							}else if(row[x+1]=='n'&&row[x+2]=='u'&&row[x+3]=='m'){
							fprintf(fp, "%d |  REWD   %s\n", count, "enum");
            				printf("%d |  REWD   %s\n", count, "enum"); x=x+3;
							}else{
								fprintf(fp, "%d |  IDEN    ", count);
            					printf("%d |  IDEN    ", count);
								while((row[x]>='A'&&row[x]<='Z')||(row[x]=='_')||(row[x]>='a'&& row[x]<='z')){
                            		fprintf(fp, "%c", row[x]);
            						printf("%c", row[x]);
                            		x++;
                       			}
                       			x--;
                       			fprintf(fp, "\n");
            					printf("\n");
							}
            				break;
            			case 'c':
		                    if(row[x+1]=='a'&&row[x+2]=='s'&&row[x+3]=='e'){
            				fprintf(fp, "%d |  REWD   %s\n", count, "case");
            				printf("%d |  REWD   %s\n", count, "case"); x=x+3;
							}else if(row[x+1]=='h'&&row[x+2]=='a'&&row[x+3]=='r'){
							fprintf(fp, "%d |  REWD   %s\n", count, "char");
            				printf("%d |  REWD   %s\n", count, "char"); x=x+3;
							}else if(row[x+1]=='o'&&row[x+2]=='m'&&row[x+3]=='s'&&row[x+4]=='t'){
							fprintf(fp, "%d |  REWD   %s\n", count, "const");
            				printf("%d |  REWD   %s\n", count, "const"); x=x+4;
							}else if(row[x+1]=='o'&&row[x+2]=='n'&&row[x+3]=='t'&&row[x+4]=='i'&&row[x+5]=='n'&&row[x+6]=='u'&&row[x+7]=='e'){
							fprintf(fp, "%d |  REWD   %s\n", count, "continue");
            				printf("%d |  REWD   %s\n", count, "continue"); x=x+7;
							}else{
								fprintf(fp, "%d |  IDEN    ", count);
            					printf("%d |  IDEN    ", count);
								while((row[x]>='A'&&row[x]<='Z')||(row[x]=='_')||(row[x]>='a'&& row[x]<='z')){
                            		fprintf(fp, "%c", row[x]);
            						printf("%c", row[x]);
                            		x++;
                       			}
                       			x--;
                       			fprintf(fp, "\n");
            					printf("\n");
							}
            				break;
            			case 's':
		                    if(row[x+1]=='t'&&row[x+2]=='a'&&row[x+3]=='t'&&row[x+4]=='i'&&row[x+5]=='c'){
            				fprintf(fp, "%d |  REWD   %s\n", count, "static");
            				printf("%d |  REWD   %s\n", count, "static"); x=x+5;
							}else if(row[x+1]=='w'&&row[x+2]=='i'&&row[x+3]=='t'&&row[x+4]=='c'&&row[x+5]=='h'){
							fprintf(fp, "%d |  REWD   %s\n", count, "switch");
            				printf("%d |  REWD   %s\n", count, "switch"); x=x+5;
							}else if(row[x+1]=='t'&&row[x+2]=='r'&&row[x+3]=='u'&&row[x+4]=='c'&&row[x+5]=='t'){
							fprintf(fp, "%d |  REWD   %s\n", count, "struct");
            				printf("%d |  REWD   %s\n", count, "struct"); x=x+5;
							}else if(row[x+1]=='i'&&row[x+2]=='z'&&row[x+3]=='e'&&row[x+4]=='o'&&row[x+5]=='f'){
							fprintf(fp, "%d |  REWD   %s\n", count, "sizeof");
            				printf("%d |  REWD   %s\n", count, "sizeof"); x=x+5;
							}else{
								fprintf(fp, "%d |  IDEN    ", count);
            					printf("%d |  IDEN    ", count);
								while((row[x]>='A'&&row[x]<='Z')||(row[x]=='_')||(row[x]>='a'&& row[x]<='z')){
                            		fprintf(fp, "%c", row[x]);
            						printf("%c", row[x]);
                            		x++;
                       			}
                       			x--;
                       			fprintf(fp, "\n");
            					printf("\n");
							}
            				break;
            			case 'w':
		                    if(row[x+1]=='h'&&row[x+2]=='i'&&row[x+3]=='l'&&row[x+4]=='e'){
            				fprintf(fp, "%d |  REWD   %s\n", count, "while");
            				printf("%d |  REWD   %s\n", count, "while"); x=x+4;
							}else{
								fprintf(fp, "%d |  IDEN    ", count);
            					printf("%d |  IDEN    ", count);
								while((row[x]>='A'&&row[x]<='Z')||(row[x]=='_')||(row[x]>='a'&& row[x]<='z')){
                            		fprintf(fp, "%c", row[x]);
            						printf("%c", row[x]);
                            		x++;
                       			}
                       			x--;
                       			fprintf(fp, "\n");
            					printf("\n");
							}
            				break;
            			case 'f':
		                    if(row[x+1]=='l'&&row[x+2]=='o'&&row[x+3]=='a'&&row[x+4]=='t'){
            				fprintf(fp, "%d |  REWD   %s\n", count, "float");
            				printf("%d |  REWD   %s\n", count, "float"); x=x+4;
							}else if(row[x+1]=='o'&&row[x+2]=='r'){
            				fprintf(fp, "%d |  REWD   %s\n", count, "for");
            				printf("%d |  REWD   %s\n", count, "for"); x=x+2;
							}else{
								fprintf(fp, "%d |  IDEN    ", count);
            					printf("%d |  IDEN    ", count);
								while((row[x]>='A'&&row[x]<='Z')||(row[x]=='_')||(row[x]>='a'&& row[x]<='z')){
                            		fprintf(fp, "%c", row[x]);
            						printf("%c", row[x]);
                            		x++;
                       			}
                       			x--;
                       			fprintf(fp, "\n");
            					printf("\n");
							}
            				break;
            			case 'd':
		                    if(row[x+1]=='o'&&row[x+2]=='u'&&row[x+3]=='b'&&row[x+4]=='l'&&row[x+5]=='e'){
            				fprintf(fp, "%d |  REWD   %s\n", count, "double");
            				printf("%d |  REWD   %s\n", count, "double"); x=x+5;
							}else if(row[x+1]=='e'&&row[x+2]=='f'&&row[x+3]=='a'&&row[x+4]=='u'&&row[x+5]=='l'&&row[x+6]=='t'){
            				fprintf(fp, "%d |  REWD   %s\n", count, "default");
            				printf("%d |  REWD   %s\n", count, "default"); x=x+6;
							}else if(row[x+1]=='o'){
							fprintf(fp, "%d |  REWD   %s\n", count, "do");
            				printf("%d |  REWD   %s\n", count, "do"); x=x+1;
							}else{
								fprintf(fp, "%d |  IDEN    ", count);
            					printf("%d |  IDEN    ", count);
								while((row[x]>='A'&&row[x]<='Z')||(row[x]=='_')||(row[x]>='a'&& row[x]<='z')){
                            		fprintf(fp, "%c", row[x]);
            						printf("%c", row[x]);
                            		x++;
                       			}
                       			x--;
                       			fprintf(fp, "\n");
            					printf("\n");
							}
            				break;
            			case 'b':
		                    if(row[x+1]=='r'&&row[x+2]=='e'&&row[x+3]=='a'&&row[x+4]=='k'){
            				fprintf(fp, "%d |  REWD   %s\n", count, "break");
            				printf("%d |  REWD   %s\n", count, "break"); x=x+4;
							}else{
								fprintf(fp, "%d |  IDEN    ", count);
            					printf("%d |  IDEN    ", count);
								while((row[x]>='A'&&row[x]<='Z')||(row[x]=='_')||(row[x]>='a'&& row[x]<='z')){
                            		fprintf(fp, "%c", row[x]);
            						printf("%c", row[x]);
                            		x++;
                       			}
                       			x--;
                       			fprintf(fp, "\n");
            					printf("\n");
							}
            				break;
            			case 'a':
		                    if(row[x+1]=='u'&&row[x+2]=='t'&&row[x+3]=='o'){
            				fprintf(fp, "%d |  REWD   %s\n", count, "auto");
            				printf("%d |  REWD   %s\n", count, "auto"); x=x+3;
							}else{
								fprintf(fp, "%d |  IDEN    ", count);
            					printf("%d |  IDEN    ", count);
								while((row[x]>='A'&&row[x]<='Z')||(row[x]=='_')||(row[x]>='a'&& row[x]<='z')){
                            		fprintf(fp, "%c", row[x]);
            						printf("%c", row[x]);
                            		x++;
                       			}
                       			x--;
                       			fprintf(fp, "\n");
            					printf("\n");
							}
            				break;
            			case 'u':
		                    if(row[x+1]=='n'&&row[x+2]=='i'&&row[x+3]=='o'&&row[x+4]=='n'){
            				fprintf(fp, "%d |  REWD   %s\n", count, "union");
            				printf("%d |  REWD   %s\n", count, "union"); x=x+4;
							}else{
								fprintf(fp, "%d |  IDEN    ", count);
            					printf("%d |  IDEN    ", count);
								while((row[x]>='A'&&row[x]<='Z')||(row[x]=='_')||(row[x]>='a'&& row[x]<='z')){
                            		fprintf(fp, "%c", row[x]);
            						printf("%c", row[x]);
                            		x++;
                       			}
                       			x--;
                       			fprintf(fp, "\n");
            					printf("\n");
							}
            				break;
            			case 'g':
		                    if(row[x+1]=='o'&&row[x+2]=='t'&&row[x+3]=='o'){
            				fprintf(fp, "%d |  REWD   %s\n", count, "goto");
            				printf("%d |  REWD   %s\n", count, "goto"); x=x+3;
							}else{
								fprintf(fp, "%d |  IDEN    ", count);
            					printf("%d |  IDEN    ", count);
								while((row[x]>='A'&&row[x]<='Z')||(row[x]=='_')||(row[x]>='a'&& row[x]<='z')){
                            		fprintf(fp, "%c", row[x]);
            						printf("%c", row[x]);
                            		x++;
                       			}
                       			x--;
                       			fprintf(fp, "\n");
            					printf("\n");
							}
            				break;
            			case 'r':
		                    if(row[x+1]=='e'&&row[x+2]=='t'&&row[x+3]=='u'&&row[x+4]=='r'&&row[x+5]=='n'){
            				fprintf(fp, "%d |  REWD   %s\n", count, "return");
            				printf("%d |  REWD   %s\n", count, "return"); x=x+5;
							}else if(row[x+1]=='e'&&row[x+2]=='g'&&row[x+3]=='i'&&row[x+4]=='s'&&row[x+5]=='t'&&row[x+6]=='e'&&row[x+7]=='r'){
            				fprintf(fp, "%d |  REWD   %s\n", count, "register");
            				printf("%d |  REWD   %s\n", count, "register"); x=x+7;
							}else{
								fprintf(fp, "%d |  IDEN    ", count);
            					printf("%d |  IDEN    ", count);
								while((row[x]>='A'&&row[x]<='Z')||(row[x]=='_')||(row[x]>='a'&& row[x]<='z')){
                            		fprintf(fp, "%c", row[x]);
            						printf("%c", row[x]);
                            		x++;
                       			}
                       			x--;
                       			fprintf(fp, "\n");
            					printf("\n");
							}
            				break;
            			case 'h': case 'j': case 'k': case 'l': case 'Y': case 'Z': case '_': case 'm': case 'n':
		                case 't': case 'v': case 'x': case 'y': case 'Q': case 'R': case 'T': case 'U': case 'V': case 'X':
		                case 'z': case 'A': case 'B': case 'G': case 'H': case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P':
		                case 'o': case 'p': case 'q':
                				fprintf(fp, "%d |  IDEN    ", count);
            					printf("%d |  IDEN    ", count);
								while((row[x]>='A'&&row[x]<='Z')||(row[x]=='_')||(row[x]>='a'&& row[x]<='z')){
                            		fprintf(fp, "%c", row[x]);
            						printf("%c", row[x]);
                            		x++;
                       			}
                       			x--;
                       			fprintf(fp, "\n");
            					printf("\n");
            					break;
            			case '0': case '1': case '6': case '7': case '8': case '9': case '2': case '3': case '4': case '5':
							z=0;
							while(row[x]>='0'&&row[x]<='9'){
								temp2[z]=row[x];
		                        x++;z++;
		                    }
		                    if(row[x]=='.'){
		                    	temp2[z]=row[x];
		                        x++;z++;
		                        while(row[x]>='0'&&row[x]<='9'){
		                        	temp2[z]=row[x];
		                            x++;z++;
		                        }
		                        if((row[x]=='e')||(row[x]=='E')){
		                        	temp2[z]=row[x];z++;
		                            x++;
		                            if((row[x]=='+')||(row[x]=='-')||(row[x]>='0'&&row[x]<='9')){
		                                temp2[z]=row[x];
										x++;z++;
		                                while(row[x]>='0'&&row[x]<='9'){
				                        	temp2[z]=row[x];
				                            x++;z++;
				                        }
		                            }
		                        }
		                        x--;
		                        fprintf(fp, "%d |  FLOT    %s\n", count, temp2);
            					printf("%d |  FLOT    %s\n", count, temp2);
            					memset(temp2, '\0', sizeof(temp2));
		                    }
		                    else{
		                    	fprintf(fp, "%d |  INTE    ", count);
            					printf("%d |  INTE    ", count);
                            		fprintf(fp, "%s", temp2);
            						printf("%s", temp2);
		                        x--;
                       			fprintf(fp, "\n");
            					printf("\n");
            					memset(temp2, '\0', sizeof(temp2));
		                    }
		                    break;
		                default :
		                    break;	
						}
					}
				  x++;  	
				}
			}
        }
        count++;
    }
    
    fclose(file);
    if (bigParenthesis != 0)
    {
        fprintf(fp, "%d|ERROR %s %d\n", count, "missing } is", bigParenthesis);
        printf("%d|ERROR %s %d\n", count, "missing } is", bigParenthesis);
    }
    return 0;
}
bool isSpec(char *val)
{
    if (strstr(val, "{") != NULL)
        return true;
    else if (strstr(val, "}") != NULL)
        return true;
    else if (strstr(val, "(") != NULL)
        return true;
    else if (strstr(val, ")") != NULL)
        return true;
    else if (strstr(val, ";") != NULL)
    	return true;
    return false;
}
bool isprep(char *val)
{
    if (strstr(val, "#") != NULL)
        return true;
    return false;
}
bool stringSC(char val[256])
{
    if (strstr(val, "//") != NULL)
        return true;
    return false;
}
bool stringBeginMC(char val[256])
{
    if (strstr(val, "/*") != NULL)
        return true;
    return false;
}
bool stringEndMC(char val[256])
{
    if (strstr(val, "*/") != NULL)
        return true;
    return false;
}

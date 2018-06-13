############################################################################################
#  Makefile                                                                                #
#  Author: Winter Meng																	   #
#  CSE 374 HW5                                                                      	   #
#                                                                                          # 
############################################################################################

calc: calc.o
	gcc -Wall -std=c11 -g calc.o getExprChar.o -o calc

calc.o: calc.h calc.c
	gcc -Wall -std=c11 -g -c calc.c

clean: 
	rm -f *.o calc

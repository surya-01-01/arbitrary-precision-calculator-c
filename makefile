OBJ:= $(patsubst %.c, %.o, $(wildcard *.c))
output.exe: $(OBJ)
	gcc -o $@ $^  
clean:
	rm *.o *.exe
# a.out: main.o addition.o subtraction.o multiplication.o division.o
# 	gcc -o a.out main.o addition.o subtraction.o multiplication.o division.o
# main.o: main.c
# 	gcc -c main.c
# addition.o:addition.c
# 	gcc -c addition.c 
# subtraction.o:subtraction.c
# 	gcc -c subtraction.c 
# multiplication.o:multiplication.c 
# 	gcc -c multiplication.c 
# division.o:division.c 
# 	gcc -c division.c 
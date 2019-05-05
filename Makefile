paint.out:main.o board.o command.o input_val.o
	gcc -g -Wall -Werror -o paint.out main.o board.o command.o input_val.o
main.o:main.c board.h command.h
	gcc -g -Wall -Werror -c -o main.o main.c
board.o:board.c board.h
	gcc -g -Wall -Werror -c -o board.o board.c
command.o:command.c command.h
	gcc -g -Wall -Werror -c -o command.o command.c
input_val.o:input_val.c input_val.h
	gcc -g -Wall -Werror -c -o input_val.o input_val.c	
clean:
	rm -f *.o *.out

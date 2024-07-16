paint.out: main.o commands.o canvas.o
	gcc -g -Wall -Werror -o paint.out main.o commands.o canvas.o

main.o: main.c commands.h canvas.h
	gcc -g -Wall -Werror -c main.c

commands.o: commands.c commands.h
	gcc -g -Wall -Werror -c commands.c

canvas.o: canvas.c canvas.h
	gcc -g -Wall -Werror -c canvas.c

clean:
	rm -fr *.o *.out
CC=g++
CFLAGS=-Wall -Wextra -g -std=c++11
EXEC=./tp3

${EXEC}: src/main.cc lista.o
	${CC} ${CFLAGS} src/main.cc lista.o -o ${EXEC}

lista.o: src/lista.cc
	$(CC) $(CFLAGS) -c src/lista.cc -o lista.o

test: ${EXEC}
	@bash run_tests.sh ${EXEC}

rand_input: rand_gen/rand_gen.cc
	${CC} ${CFLAGS} rand_gen/rand_gen.cc -o rand_input

valgrind_test: rand_input ${EXEC}
	@./rand_input 32 | valgrind ${EXEC}

clean:
	@rm -rf *.o ${EXEC} rand_input
	rm -rf lista.o
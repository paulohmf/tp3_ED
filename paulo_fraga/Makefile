CC=g++
CFLAGS=-Wall -Wextra -g -std=c++11
EXEC=./tp3

${EXEC}: src/main.cc lista.o huffman.o
	${CC} ${CFLAGS} src/main.cc lista.o huffman.o -o ${EXEC}

lista.o: src/lista.cc
	$(CC) $(CFLAGS) -c src/lista.cc -o lista.o

huffman.o: src/huffman.cc
	$(CC) $(CFLAGS) -c src/huffman.cc -o huffman.o

test: ${EXEC}
	@bash run_tests.sh ${EXEC}

rand_input: rand_gen/rand_gen.cc
	${CC} ${CFLAGS} rand_gen/rand_gen.cc -o rand_input

valgrind_test: rand_input ${EXEC}
	@./rand_input 32 | valgrind ${EXEC}

clean:
	@rm -rf *.o ${EXEC} rand_input
	rm -rf lista.o
	rm -rf huffman.o
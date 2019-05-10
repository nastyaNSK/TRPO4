all: bin build/src build/test bin/geometry bin/geometry_test

bin/geometry: build/src/main.o build/src/geometry.o
	gcc -Wall -Werror build/src/main.o build/src/geometry.o -o bin/geometry -lm

build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

build/src/geometry.o: src/geometry.c
	gcc -Wall -Werror -c src/geometry.c -o build/src/geometry.o


bin/geometry_test: build/test/main.o build/test/geometria_test.o build/src/geometry.o
	gcc build/test/main.o build/test/geometria_test.o build/src/geometry.o -o bin/geometry_test -lm -std=c11

build/test/main.o: test/main.c
	gcc -I thirdparty -c test/main.c -o build/test/main.o

build/test/geometria_test.o: test/geometria_test.c
	gcc -I thirdparty -c test/geometria_test.c  -o build/test/geometria_test.o

clean:
	rm -rf build/src/*.o bin/geometry
	rm -rf build/test/*.o bin/geometry_test

bin:
	mkdir bin
build/src:
	mkdir -p build/src
build/test:
	mkdir -p build/test



.PHONY: clean

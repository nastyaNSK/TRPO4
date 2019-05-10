all: bin build build/src build/test bin/geometry

bin/geometry: build/src/main.o build/src/geometry.o
	gcc -Wall -Werror build/src/main.o build/src/geometry.o -o bin/geometry -lm

build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

build/src/geometry.o: src/geometry.c
	gcc -Wall -Werror -c src/geometry.c -o build/src/geometry.o

test: bin/geometry_test

bin/geometry_test: build/test/main.o build/test/geometry.o
	gcc -Wall -Werror build/test/main.o build/test/geometry.o -o bin/geometry_test -lm

build/test/main.o: test/main.c
	gcc -Wall -Werror -c -I thirdparty -I src test/main.c -o build/test/main.o

build/test/geometry.o: src/geometry.c src/geometry.h
	gcc -Wall -Werror -c -I thirdparty -I src src/geometry.c -o build/test/geometry.o

clean:
	rm -rf build/src/*.o bin/geometry
	rm -rf build/test/*.o bin/test

bin:
	mkdir bin
build:
	mkdir build
build/src:
	mkdir build/src
build/test:
	mkdir build/test
.PHONY: clean

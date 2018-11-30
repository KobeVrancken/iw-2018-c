cpp-iw: src/cpp.c src/util.c src/list.c src/list.h
	gcc -g -std=c99 -Wall src/cpp.c src/util.c src/list.c -o cpp-iw

clean:
	rm -f cpp-iw

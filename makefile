all: main.c
	gcc -o control main.c
clean:
	rm control
run: all
	./control -c 4
	./control -v
	./control -c 3
	./control -v
	./control -r
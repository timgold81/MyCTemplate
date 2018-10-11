CC=gcc
OUT=main
make: ${OBJ}
	$(CC) main.c -o $(OUT)

clean:
	rm -f *.o $(OUT)
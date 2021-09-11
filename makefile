CC=gcc
IN=main.c
OUT=game
target:
	$(CC) $(IN) -o $(OUT)
clean:
	rm $(OUT)

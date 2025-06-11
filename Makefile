CFLAGS = src/main.c -Isrc/lib/ -Isrc/res/ src/lib/tools.c src/lib/utils.c src/lib/layout.c -lncurses -lm -o mdbx

app: src/main.c src/lib/tools.c src/lib/tools.h src/lib/utils.c src/lib/utils.h src/lib/layout.c src/lib/layout.h src/res/banner src/res/options.h
	gcc $(CFLAGS)

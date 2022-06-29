#makefile
.PHONY : clean

CC := gcc
CFLAGS := -o main.out
CPPFLAGS :=
LDFLAGS :=
LDFLIBS :=

main.out : src/main.c src/sub.c
	$(CC) $(CFLAGS) src/main.c src/sub.c
	@echo "exported as \""$@"\""

clean :
	-rm main.out
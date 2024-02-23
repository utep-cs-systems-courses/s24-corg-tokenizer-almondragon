
OBJS = tokenizer.o history.o uimain.o

CFLAGS = -g -O3

all: tokenizerProgram

tokenizerProgram: $(OBJS)
	cc -o tokenizerProgram $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.c# *.c~ *.o tokenizerProgram

run: tokenizerProgram
	./tokenizerProgram

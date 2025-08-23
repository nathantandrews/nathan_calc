CC := gcc

IDIR := ../include
SRCDIR := ../src

SRCS := calculator.c operator.c parser.c scanner.c status_t.c token_stk.c token.c tree_node.c ui_gtk.c
OBJS := $(SRCS:.c=.o)

CFLAGS := -std=c89 -Wall -Werror -I$(IDIR) -g # -fsanitize=address -Wpedantic
LDFLAGS := -lm # -lasan

vpath %.c $(SRCDIR)

all: nathan_calc run

nathan_calc: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

run:
	./nathan_calc

clean:
	del /q /f nathan_calc.exe $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
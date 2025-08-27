CC := gcc

IDIR := ../include
SRCDIR := ../src

SRCS := \
	args.c \
	ast.c \
	calculator.c \
	logger.c \
	operator.c \
	parser.c \
	scanner.c \
	stack.c \
	status.c \
	string_extras.c \
	token.c \
	ui_gtk.c

OBJS := $(SRCS:.c=.o)

CFLAGS := -std=c89 -Wall -Werror -Wpedantic -I$(IDIR) -g # -fsanitize=address
LDFLAGS := -lm # -lasan

vpath %.c $(SRCDIR)

all: nathan_calc run

nathan_calc: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

run:
	./nathan_calc

debug:
	./nathan_calc --debug

clean:
	rm -rf nathan_calc.exe $(OBJS)
	rm -rf *.log

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
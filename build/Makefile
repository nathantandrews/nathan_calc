CC := gcc

IDIR := ../include
SRCDIR := ../src

SRCS := \
	ast.c \
	nta_args.c \
	nta_logger.c \
	nta_stack.c \
	nta_string.c \
	operator.c \
	parser.c \
	scanner.c \
	status.c \
	token.c \
	ui_gtk.c \
	calculator.c

OBJS := $(SRCS:.c=.o)

CFLAGS := -std=c89 -Wall -Werror -Wpedantic -I$(IDIR) -g # -D NDEBUG # -fsanitize=address
LDFLAGS := -lm # -lasan

vpath %.c $(SRCDIR)

all: nta_calc

nta_calc: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

run:
	./nta_calc

debug:
	./nta_calc -m debug -v

clean:
	rm -rf nta_calc.exe *.log $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
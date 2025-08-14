CC := gcc

IDIR := ../include
SRCDIR := ../src

SRCS := calculator.c input.c
OBJS := $(SRCS:.c=.o)

CFLAGS := -std=c89 -Wall -Werror -I$(IDIR) -g # -fsanitize=address
LDFLAGS := -lm # -lasan

vpath %.c $(SRCDIR)

all: nathan_calc run clean

nathan_calc: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

run:
	./nathan_calc

clean:
	del /q /f nathan_calc.exe $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
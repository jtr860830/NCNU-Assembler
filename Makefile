CC=clang
CFLAGS=-Isrc -Wall -Wextra -Werror -Wpedantic -std=c11 -g

SRCDIR=./src
OBJDIR=./obj
BINDIR=./bin
TESTDIR=./tests

HDRS=$(wildcard $(SRCDIR)/*.h)
SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
BIN=main

all: $(BIN)

$(BIN): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HDRS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

test: $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(BINDIR)/op_table_test $(TESTDIR)/op_table_test.c $(filter-out $(OBJDIR)/main.o, $(OBJS))
	$(BINDIR)/op_table_test

clean:
	@rm -rf $(BINDIR) $(OBJDIR)

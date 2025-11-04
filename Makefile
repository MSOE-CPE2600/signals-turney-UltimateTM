CFLAGS=-c -g -Wall -Werror
LDFLAGS= 
SOURCES= recv_signal.c send_signal.c signal_alarm.c signal_handler.c signal_segfault.c signal_sigaction.c
EXECUTABLE= recv_signal send_signal signal_alarm signal_handler signal_segfault signal_sigaction
CC=gcc

all: $(EXECUTABLE)

recv_signal: recv_signal.o
	$(CC) -o recv_signal recv_signal.o $(LDFLAGS)

send_signal: send_signal.o
	$(CC) -o send_signal send_signal.o $(LDFLAGS)

signal_alarm: signal_alarm.o
	$(CC) -o signal_alarm signal_alarm.o $(LDFLAGS)

signal_handler: signal_handler.o
	$(CC) -o signal_handler signal_handler.o $(LDFLAGS)

signal_segfault: signal_segfault.o
	$(CC) -o signal_segfault signal_segfault.o $(LDFLAGS)

signal_sigaction: signal_sigaction.o
	$(CC) -o signal_sigaction signal_sigaction.o $(LDFLAGS)

clean:
	rm -f *.o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<


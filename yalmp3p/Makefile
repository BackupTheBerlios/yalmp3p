CC=gcc
CCFLAGS=-Wall
LDFLAGS=
#-L/usr/local/lib -L/lib -lSDL -lSDL_image -lGL
INCLUDES=
FILES=lcdtest.o
PROGNAME=lcdtest

all: $(PROGNAME)

$(PROGRAM): $(FILES)
	$(CC) $(CCFLAGS) $(LDFLAGS) $(FILES) -o $(PROGNAME)

%.o: %.c $(INCLUDES)
	$(CC) $(CCFLAGS) $(INCLUDES) -c $<

clean:
	rm -f *~
	rm -f *.o
	rm -f $(PROGNAME)



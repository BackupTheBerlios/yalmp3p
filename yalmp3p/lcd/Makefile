lcd: lcd.c panel.o
	gcc -g lcd.c panel.o hw_iface.o -o lcd

panel.o: panel.c panel.h hw_iface.o
	gcc -g -c panel.c

hw_iface.o: hw_iface.c hw_iface.h
	gcc -g -c -O hw_iface.c

clean:
	rm -f *.out
	rm -f *.o
	rm -f lcd
	rm -f *~

OBJS	= tests.o mystring.o
test_mystring: test_mystring.c $(OBJS)
	gcc -o $@ $< $(OBJS)
.c.o:
	gcc -c $<
.PHONY: clean test
clean:
	rm -f *.o
	rm -f test_mystring
test: test_mystring
	./$<

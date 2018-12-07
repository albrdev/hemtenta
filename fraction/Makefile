testfract: fraction.o testfract.cpp
	g++ -o $@ $?

fraction.o: fraction.cpp fraction.hpp
	g++ -c $< -o $@

.PHONY: clean test
clean:
	rm -f testfract
	rm -f *.o

test: testfract
	./$<

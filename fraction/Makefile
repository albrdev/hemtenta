testfract: testfract.cpp
	g++ -o $@ $< 
.PHONY: clean test
clean:
	rm -f testfract
	rm -f *.o
test: testfract
	./$<

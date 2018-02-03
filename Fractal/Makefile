CC=g++
CFLAGS=-c -Wall -ggdb -I. -O3
LDFLAGS=-lpthread
SOURCES=fractal.cpp myComplex.cpp
EXECUTABLE=fractal
TESTS = myComplex_test.h

OBJECTS=$(SOURCES:.cpp=.o)
FLAGS   = -Iinclude

all: $(SOURCES) $(EXECUTABLE)

IMAGESOURCE=image.cpp
IEXE=imagegen
OBJECTS2=$(IMAGESOURCE:.cpp=.o)
image: $(IMAGESOURCE) $(IEXE)
	

# These next lines do a bit of magic found from http://stackoverflow.com/questions/2394609/makefile-header-dependencies
# Essentially it asks the compiler to read the .cpp files and generate the needed .h dependencies.
# This way if any .h file changes the correct .cpp files will be recompiled
depend: .depend

.depend: $(SOURCES) $(IMAGESOURCE)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ >> ./.depend;

include .depend
# End .h file magic

$(EXECUTABLE): $(OBJECTS) 
	$(CC)  $(OBJECTS) -o $@ $(LDFLAGS)
	
$(IEXE): $(OBJECTS2) 
	$(CC)  $(OBJECTS2) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(EXECUTABLE)
	rm -rf *o $(IEXE)
	rm -f ./.depend
	rm -f testrunner
	rm -f testrunner.cpp

# CXX Testing	
CXXLOCATION = ../cxxtest
CXXTESTGEN = $(CXXLOCATION)/bin/cxxtestgen

test: testrunner
	./testrunner

testrunner: testrunner.cpp myComplex.o
	g++ -I. -I$(CXXLOCATION)/ -ggdb -Wall -o testrunner $(OBJECTSTEST) testrunner.cpp myComplex.o

testrunner.cpp: $(HEADERS) $(SOURCES) $(TESTS) depend
	$(CXXTESTGEN) --error-printer -o testrunner.cpp $(TESTS)


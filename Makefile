#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a

HEADERS := $(wildcard .h)
TEACHER_SOURCES := Editor.cpp Document.cpp main.cpp
STUDENT_SOURCES := $(filter-out $(TEACHER_SOURCES), $(wildcard *.cpp))
STUDENT_OBJECTS := $(subst .cpp,.o,$(STUDENT_SOURCES))

run: editor

editor: main.o Document.o Editor.o
	$(CXX) $(CXXFLAGS) $^ -o editor

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o editor
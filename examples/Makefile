CXXFLAGS=-std=c++14 -Wall -Werror
# Source files extension
SOURCE_EXT=cpp
# Find all files with wanted extension
SOURCES:=$(foreach ext, $(SOURCE_EXT), $(wildcard *.$(ext)))
# Destination extension
OBJ_EXT=o
# Object files with wanted extension (converts for example test_trie.cpp to test_trie.o)
OBJECT_FILES:=$(foreach source, $(SOURCES), $(addsuffix .$(OBJ_EXT),$(basename $(source))))
# Destination files without extension
DESTINATION:=$(foreach source, $(SOURCES), $(basename $(source)))

all: ${DESTINATION}

# For a given destination executable, build it from its cpp source
%:%.cpp
	$(CXX) $(CXXFLAGS) -I ../include -o $@ $<

clean:
	rm -f ${OBJECT_FILES}
	rm -f ${DESTINATION}

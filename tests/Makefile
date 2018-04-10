CXXFLAGS=-std=c++14 -Wall -Werror --coverage
# Source files extension
SOURCE_EXT=cpp
# Find all files with wanted extension
SOURCES:=$(foreach ext, $(SOURCE_EXT), $(wildcard *.$(ext)))
# Destination extension
DEST_EXT=o
# Destination files with wanted extension (converts for example test_trie.cpp to test_trie.o)
DESTINATIONS:=$(foreach source, $(SOURCES), $(addsuffix .$(DEST_EXT),$(basename $(source))))

# Build and then test all destination files
test: ${DESTINATIONS}
	$(CXX) ${DESTINATIONS} $(CXXFLAGS) -o test

# For a given destination file using .o extension, build it from its cpp source
%.o: %.cpp ## Converts from cpp to object
	$(CXX) -c $< $(CXXFLAGS) -I ../include

clean:
	rm -f *.o
	rm -f *.gcno *.gcda
	rm -f test

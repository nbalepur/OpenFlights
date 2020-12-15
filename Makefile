EXENAME = finalproj
OBJS = readFromFile.o main.o MapImage.o RouteGraph.o graph.o Utility.o Airport.o AirportList.o PNG.o HSLAPixel.o lodepng.o Animation.o dijkstra.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement Makefile rule:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu")
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

Animation.o : Animation.cpp
	$(CXX) $(CXXFLAGS) Animation.cpp

PNG.o : cs225/PNG.cpp cs225/PNG.h cs225/HSLAPixel.h cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/PNG.cpp

HSLAPixel.o : cs225/HSLAPixel.cpp cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) cs225/HSLAPixel.cpp

lodepng.o : cs225/lodepng/lodepng.cpp cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/lodepng/lodepng.cpp

Utility.o: Utility.cpp Utility.h
	$(CXX) $(CXXFLAGS) Utility.cpp

graph.o : graph.cpp edge.h
	$(CXX) $(CXXFLAGS) graph.cpp edge.h

RouteGraph.o: main.cpp RouteGraph.cpp graph.cpp AirportList.cpp
	$(CXX) $(CXXFLAGS) main.cpp RouteGraph.cpp graph.cpp AirportList.cpp

MapImage.o: main.cpp MapImage.cpp RouteGraph.cpp graph.cpp AirportList.cpp cs225/PNG.cpp cs225/PNG.h cs225/HSLAPixel.cpp cs225/HSLAPixel.h Animation.cpp
	$(CXX) $(CXXFLAGS) main.cpp MapImage.cpp RouteGraph.cpp graph.cpp AirportList.cpp cs225/PNG.cpp cs225/PNG.h cs225/HSLAPixel.cpp cs225/HSLAPixel.h Animation.cpp

readFromFile.o: main.cpp readFromFile.cpp
	$(CXX) $(CXXFLAGS) main.cpp readFromFile.cpp

Airport.o : main.cpp Airport.cpp Airport.h
	$(CXX) $(CXXFLAGS) main.cpp Airport.cpp

AirportList.o: main.cpp AirportList.cpp  AirportList.hpp Airport.h readFromFile.hpp
	$(CXX) $(CXXFLAGS) main.cpp AirportList.cpp Airport.cpp Airport.h readFromFile.cpp readFromFile.hpp

dijkstra.o: main.cpp dijkstra.cpp dijkstra.hpp Utility.h AirportList.hpp RouteGraph.h
	$(CXX) $(CXXFLAGS) main.cpp dijkstra.cpp Utility.cpp AirportList.cpp RouteGraph.cpp

test: output_msg catch/catchmain.cpp tests/tests.cpp readFromFile.cpp Utility.cpp RouteGraph.cpp graph.cpp AirportList.cpp Airport.cpp dijkstra.cpp
	$(LD) catch/catchmain.cpp tests/tests.cpp readFromFile.cpp Utility.cpp RouteGraph.cpp graph.cpp AirportList.cpp Airport.cpp dijkstra.cpp $(LDFLAGS) -o test

clean:
	-rm -f *.o $(EXENAME) test
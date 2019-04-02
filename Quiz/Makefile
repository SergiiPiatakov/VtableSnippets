CXX		= g++

.PHONY all: 001 002 003 004

001:
	$(CXX) -Wall -Wextra 001_main.cpp -o 001_main

002:
	$(CXX) -Wall -Wextra 002_main.cpp -fdump-class-hierarchy=002_main.class -o 002_main

003:
	$(CXX) -Wall -Wextra 003_main.cpp -fdump-class-hierarchy=003_main.class -std=c++11 -o 003_main

004:
	$(CXX) -Wall -Wextra 004_main.cpp -fdump-class-hierarchy=004_main.class -std=c++11 -ggdb -o 004_main

.PHONY clean:
	$(RM) 001_main
	$(RM) 002_main 002_main.class
	$(RM) 003_main 003_main.class
	$(RM) 004_main 004_main.class

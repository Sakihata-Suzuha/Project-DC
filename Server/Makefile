SRC_MAIN=$(wildcard ./src/*.cpp)
SRC_PM=$(wildcard ./src/process_manager/*.cpp)
SRC_NM=$(wildcard ./src/network_manager/*.cpp)
SRC_3M=$(wildcard ./src/module/*.cc)
SRC_RI=$(wildcard ./src/resource_init/*.cpp)
SRC_TM=$(wildcard ./src/thread_manager/*.cpp)

OBJ_MAIN=$(patsubst ./src/%.cpp, ./obj/%.o, $(SRC_MAIN))
OBJ_PM=$(patsubst ./src/process_manager/%.cpp, ./obj/%.o, $(SRC_PM))
OBJ_NM=$(patsubst ./src/network_manager/%.cpp, ./obj/%.o, $(SRC_NM))
OBJ_3M=$(patsubst ./src/module/%.cc, ./obj/%.o, $(SRC_3M))
OBJ_RI=$(patsubst ./src/resource_init/%.cpp, ./obj/%.o, $(SRC_RI))
OBJ_TM=$(patsubst ./src/thread_manager/%.cpp, ./obj/%.o, $(SRC_TM))

CFLAG=-c -g 	#-g Valgrind
TARGET=./bin/launchService

OBJS=$(OBJ_MAIN) $(OBJ_PM) $(OBJ_NM) $(OBJ_3M) $(OBJ_RI) $(OBJ_TM)
$(TARGET):$(OBJS)
	g++ $^ -o $@ -lprotobuf -lpthread 	#use pthread?

./obj/%.o:./src/%.cpp
	g++ $(CFLAG) $< -o $@

./obj/%.o:./src/process_manager/%.cpp
	g++ $(CFLAG) $< -o $@

./obj/%.o:./src/network_manager/%.cpp
	g++ $(CFLAG) $< -o $@

./obj/%.o:./src/module/%.cc
	g++ $(CFLAG) $< -o $@

./obj/%.o:./src/resource_init/%.cpp
	g++ $(CFLAG) $< -o $@

./obj/%.o:./src/thread_manager/%.cpp
	g++ $(CFLAG) $< -o $@

.PHONY:clean
clean:
	$(RM) $(TARGET) $(OBJS)

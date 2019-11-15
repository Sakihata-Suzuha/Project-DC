SRC_MAIN=$(wildcard ./src/*.cpp)
SRC_PM=$(wildcard ./src/Process_Manager/*.cpp)
SRC_NM=$(wildcard ./src/Network_Manager/*.cpp)

OBJ_MAIN=$(patsubst ./src/%.cpp, ./obj/%.o, $(SRC_MAIN))
OBJ_PM=$(patsubst ./src/Process_Manager/%.cpp, ./obj/%.o, $(SRC_PM))
OBJ_NM=$(patsubst ./src/Network_Manager/%.cpp, ./obj/%.o, $(SRC_NM))

CFLAG=-c
#INC=
TARGET=./bin/myServer

OBJS=$(OBJ_MAIN) $(OBJ_PM) $(OBJ_NM)
$(TARGET):$(OBJS)
	g++ $^ -o $@

./obj/%.o:./src/%.cpp	
	g++ $(CFLAG) $< -o $@

./obj/%.o:./src/Process_Manager/%.cpp
	g++ $(CFLAG) $< -o $@

./obj/%.o:./src/Network_Manager/%.cpp
	g++ $(CFLAG) $< -o $@

.PHONY:clean
clean:
	$(RM) $(TARGET) $(OBJS)

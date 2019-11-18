SRC_MAIN=$(wildcard ./src/*.cpp)
SRC_PM=$(wildcard ./src/Process_Manager/*.cpp)
SRC_NM=$(wildcard ./src/Network_Manager/*.cpp)
SRC_LM=$(wildcard ./src/Log_Module/*.cpp)
SRC_RI=$(wildcard ./src/resrc_init/*.cpp)

OBJ_MAIN=$(patsubst ./src/%.cpp, ./obj/%.o, $(SRC_MAIN))
OBJ_PM=$(patsubst ./src/Process_Manager/%.cpp, ./obj/%.o, $(SRC_PM))
OBJ_NM=$(patsubst ./src/Network_Manager/%.cpp, ./obj/%.o, $(SRC_NM))
OBJ_LM=$(patsubst ./src/Log_Module/%.cpp, ./obj/%.o, $(SRC_LM))
OBJ_RI=$(patsubst ./src/resrc_init/%.cpp, ./obj/%.o, $(SRC_RI))

CFLAG=-c
#INC=
TARGET=./bin/myServer

OBJS=$(OBJ_MAIN) $(OBJ_PM) $(OBJ_NM) $(OBJ_LM) $(OBJ_RI)
$(TARGET):$(OBJS)
	g++ $^ -o $@

./obj/%.o:./src/%.cpp	
	g++ $(CFLAG) $< -o $@

./obj/%.o:./src/Process_Manager/%.cpp
	g++ $(CFLAG) $< -o $@

./obj/%.o:./src/Network_Manager/%.cpp
	g++ $(CFLAG) $< -o $@

./obj/%.o:./src/Log_Module/%.cpp
	g++ $(CFLAG) $< -o $@

./obj/%.o:./src/resrc_init/%.cpp
	g++ $(CFLAG) $< -o $@

.PHONY:clean
clean:
	$(RM) $(TARGET) $(OBJS)

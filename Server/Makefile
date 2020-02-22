SRC_MAIN=$(wildcard ./src/*.cpp)
SRC_PM=$(wildcard ./src/process_manager/*.cpp)
SRC_NM=$(wildcard ./src/network_manager/*.cpp)
SRC_3M=$(wildcard ./src/module/*.cc)
SRC_RI=$(wildcard ./src/resource_init/*.cpp)
SRC_TM=$(wildcard ./src/thread_manager/*.cpp)
SRC_PS=$(wildcard ./src/proto_src/*.cc)
SRC_OP=$(wildcard ./src/operation/*.cpp)

OBJ_MAIN=$(patsubst ./src/%.cpp, ./obj/%.o, $(SRC_MAIN))
OBJ_PM=$(patsubst ./src/process_manager/%.cpp, ./obj/%.o, $(SRC_PM))
OBJ_NM=$(patsubst ./src/network_manager/%.cpp, ./obj/%.o, $(SRC_NM))
OBJ_3M=$(patsubst ./src/module/%.cc, ./obj/%.o, $(SRC_3M))
OBJ_RI=$(patsubst ./src/resource_init/%.cpp, ./obj/%.o, $(SRC_RI))
OBJ_TM=$(patsubst ./src/thread_manager/%.cpp, ./obj/%.o, $(SRC_TM))
OBJ_PS=$(patsubst ./src/proto_src/%.cc, ./obj/%.o, $(SRC_PS))
OBJ_OP=$(patsubst ./src/operation/%.cpp, ./obj/%.o, $(SRC_OP))

CFLAG=-c -g 	#-g Valgrind
TARGET=./bin/launchService

OBJS=$(OBJ_MAIN) $(OBJ_PM) $(OBJ_NM) $(OBJ_3M) $(OBJ_RI) $(OBJ_TM) $(OBJ_PS) $(OBJ_OP)
$(TARGET):$(OBJS)
	g++ $^ -o $@ -lprotobuf -lpthread 	#use pthread?
#---------------------------------------------------------------------------------------

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

./obj/%.o:./src/proto_src/%.cc
	g++ $(CFLAG) $< -o $@

./obj/%.o:./src/operation/%.cpp
	g++ $(CFLAG) $< -o $@


.PHONY:clean
clean:
	$(RM) $(TARGET) $(OBJS)

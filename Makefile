# AUTHOR - Bonk

SRCS =	src/main.cpp \
		src/glad.c \
		src/shader.cpp \
		src/VBO.cpp \
		src/VAO.cpp \
		src/EBO.cpp \
		src/stb.cpp \
		src/texture.cpp \
		src/camera.cpp \
		src/mesh.cpp \
		src/model.cpp \
		src/light.cpp \
		src/prefab.cpp

NAME = scene
CPPFLAGS = -Iheaders -Iglm -Iheaders/prefabs -Wall -Wextra -Werror
LIBS = -lglut -lGLU -lGL -lglfw -ldl

all: $(NAME)

$(NAME):
	g++  ${CPPFLAGS} -o ${NAME} ${SRCS} imgui/*.cpp ${LIBS}


run: re
	./${NAME}

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re run
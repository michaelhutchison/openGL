#  List of all programs you want to build
EX=main
THINGS=Boat.o Thing.o
OBJ=$(THINGS) CSCIx229Functions.o View.o Light.o Scene.o Thing.o Overlay.o Mouse.o Texture.o vec3.o
#  Libraries - Linux
LIBS=-lglut -lGLU -lGL
#  Libraries - OSX
#LIBS=-framework GLUT -framework OpenGL
#  Libraries - MinGW
#LIBS=-lglut32cu -lglu32 -lopengl32

#  Main target
all: $(EX)

#  Generic compile rules
.cpp.o:
	g++ -c -O -Wall $< -IGL

#  Generic compile and link
%: %.cpp graphicslib.a
	g++ -Wall -O3 -o $@ $^ $(LIBS)

#  Delete unwanted files
clean:
	rm -f $(EX) *.o *.a

#  Create archive (include glWindowPos here if you need it)
graphicslib.a: $(OBJ) 
	ar -rcs graphicslib.a $^


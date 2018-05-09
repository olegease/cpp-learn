C = g++ -std=c++11 -O0
infocall = ./info.out
examplecall = ./example.out
OUTE = -oexample.out
WSNG = x11/wnd.cpp x11/wsng.cpp
X11-WSNG = $(OUTE) examples/x11-wsng.cpp $(WSNG)  -lX11 -lGL -lGLU
X11-WSNG-GLC = $(OUTE) examples/x11-wsng-glc.cpp $(WSNG) -lX11 -lGL -lGLU
info:
	$(C) -oinfo.out info.cpp
	$(infocall)
x11-wsng:
	$(C) $(X11-WSNG)
x11-wsng-r:
	$(C) $(X11-WSNG)
	$(examplecall)
x11-wsng-glc:
	$(C) $(X11-WSNG-GLC)
x11-wsng-glc-r:
	$(C) $(X11-WSNG-GLC)
	$(examplecall)
valgrind:
	valgrind --leak-check=yes $(examplecall)

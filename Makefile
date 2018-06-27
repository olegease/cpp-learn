C = g++ -std=c++11 -O0
infocall = ./info.out
examplecall = ./example.out
OUTE = -oexample.out
WIN-WSNG = win/wnd.cpp win/wsng.cpp
X11-WSNG = x11/wnd.cpp x11/wsng.cpp
EXP-WIN-WSNG = $(OUTE) examples/win-wsng.cpp $(WIN-WSNG)
EXP-X11-WSNG = $(OUTE) examples/x11-wsng.cpp $(X11-WSNG) -lX11
EXP-X11-WSNG-GLC = $(OUTE) examples/x11-wsng-glc.cpp $(X11-WSNG) -lX11 -lGL -lGLU
info:
	$(C) -oinfo.out info.cpp
	$(infocall)
exp-win-wsng:
	$(C) $(EXP-WIN-WSNG)
exp-x11-wsng:
	$(C) $(EXP-X11-WSNG)
exp-x11-wsng-r:
	$(C) $(EXP-X11-WSNG)
	$(examplecall)
exp-x11-wsng-glc:
	$(C) $(X11-WSNG-GLC)
exp-x11-wsng-glc-r:
	$(C) $(X11-WSNG-GLC)
	$(examplecall)
valgrind:
	valgrind --leak-check=yes $(examplecall)

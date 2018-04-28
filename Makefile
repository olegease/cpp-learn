C = g++ -std=c++11 -O0
infocall = ./info.out
examplecall = ./example.out
X11_WSNG = -oexample.out examples/x11-wsng.cpp x11/wnd.cpp x11/wsng.cpp -lX11
info:
	$(C) -oinfo.out info.cpp
	$(infocall)
x11-wsng:
	$(C) $(X11_WSNG)
x11-wsng-r:
	$(C) $(X11_WSNG)
	$(examplecall)
valgrind:
	valgrind --leak-check=yes $(examplecall)

test:
	g++ -std=c++11 -orun test.cpp x11/wnd.cpp x11/wsng.cpp -lX11
run:
	./run

xtest:
	g++ -std=c++11 -orun x11/xtest.cpp -lX11

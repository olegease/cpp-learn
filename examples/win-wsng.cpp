#include <iostream>
#include "../win/wsng.hpp"

void f(win::Wnd* w)
{
	switch (w->event()->msg) {
		case WM_DESTROY: {
			std::cout << "\ndestroying window\n";
			PostQuitMessage(0);
			break;
		}
		case WM_LBUTTONDOWN: {
			std::cout << "\nmouse left button down at (" << LOWORD(w->event()->lp)
				<< ',' << HIWORD(w->event()->lp) << ")\n";
			break;
		}
	}
}

int main()
{
	win::Wnd* w = win::Wsng::create();
	w->events(f);
	w->title("Titled");
	w->show();
	win::Wsng::run();

	return 0;
}

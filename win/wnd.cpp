#include "wnd.hpp"

#include <array>

namespace win
{
	Wnd::Wnd() : w(640), h(480), ttl("Untitled"), ent(new Event) { }
	Wnd::~Wnd() { delete ent; }

	void Wnd::nextEvent()
	{
		if (ents) {
			ents(this);
		}
	}

	void Wnd::window(HWND window) { wnd = window; }
	HWND Wnd::window() { return wnd; }

	void Wnd::event(Event* event) { ent = event; }
	Event* Wnd::event() { return ent; }

	void Wnd::events(fwndptr events) { ents = events; }
	fwndptr Wnd::events() { return ents; }

	void Wnd::show() { ShowWindow(wnd, SW_SHOW); }
	void Wnd::hide() { ShowWindow(wnd, SW_HIDE); }

	void Wnd::title(const std::string& rename)
	{
		SetWindowText(wnd, rename.c_str());
		ttl = rename;
	}
	std::string& Wnd::title() { return ttl; }

	int Wnd::width() { return w; }
	int Wnd::height() { return h; }

	HINSTANCE Wnd::hinstance() { return hin; }
	void Wnd::hinstance(HINSTANCE hInstance) { hin = hInstance; }


}

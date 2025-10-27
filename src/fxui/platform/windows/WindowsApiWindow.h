#include <fxplatformuidefs.h>

#ifdef BACKEND_WINAPI

#include <windows.h>
#include <cstdint>
// dwm
#include <dwmapi.h>

namespace
{
}

class WinAPIObject
{
	public:
		WinAPIObject()
		{
			hinstance = GetModuleHandle(NULL);
		}
		~WinAPIObject()
		{
		}
	public:
		void CreateHInstance()
		{
			hinstance = GetModuleHandle(NULL);
		};
		void DisableConsole(void)
		{
		};
		void CreateHWindow()
		{
		};
		void CreateHDC()
		{
		};
	public:
		::HINSTANCE GetHInstance() const { return hinstance; }
		::HWND GetHWindow() const { return hwnd; }
		::HDC GetHDC() const { return hdc; }
		::HFONT GetHFont() const {return hfont; }

	public:
		::POINT MousePosition;
	private:
		::HINSTANCE hinstance;
		::HWND hwnd;
		::MSG msg;
		::HACCEL hAccel;
		::HDC hdc;
		::HFONT hfont;
		static ::PAINTSTRUCT ps;
};

#endif

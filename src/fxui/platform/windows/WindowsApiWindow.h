#include <fxplatformuidefs.h>

#ifdef BACKEND_WINAPI

#include <windows.h>

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
		::HINSTANCE GetHInstance() const { return hinstance; }
	private:
		::HINSTANCE hinstance;
		::HWND hwnd;
		::HDC hdc;
};

#endif

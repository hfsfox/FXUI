#ifndef __BEAPIMENUBAR__
#define __BEAPIMENUBAR__
#endif

#if defined(BACKEND_BEAPI)

#include <Menu.h>
#include <MenuBar.h>

/*
inline
BMenuBar* CreateNativeMenuBar()
{
	BMenuBar* menubar = new BMenuBar("menubar");
	return menubar;
};
*/

inline
BMenuBar* GetNativeMenuBar()
{
	BMenuBar* menubar = new BMenuBar("menubar");
	return menubar;
};

inline
void AddMenu(int index, const char* menuname)
{
	BMenu* menu = new BMenu(menuname);
	GetNativeMenuBar()->AddItem(menu, index);
};

/*
 inline
 GetMenu()

 inline
 AddMenuItemToMenu()
*/

#endif

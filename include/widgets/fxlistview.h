//-----------------------------------------------------------------------------
// FXUI SDK
// FXUI: Graphical User Interface Framework:
//
// Version 0.1       Date :
//
//-----------------------------------------------------------------------------
// MIT
// © 2025, , All Rights Reserved
//-----------------------------------------------------------------------------
//
//	@file: include/widgets/fxlistview.h
//	@description: the file contains FX::FXListView declaration
//

#ifndef __FXLISTVIEW__
#define __FXLISTVIEW__

#include <fxwidget.h>

namespace FX
{
    class FXListView: public FX::FXWidget
    {
        public:
            FXListView();
            ~FXListView();
        public:
            void Draw();

        public:
            void RemoveItem(unsigned int index);
            void MakeEmpty();
            void DeselectAll();
            bool IsEmpty() const;
            unsigned int CountItems();
            unsigned int CurrentItemIndex();
            //unsigned int
        public:
            int GetHeight() const;
            int GetWidth() const;
            void SetEnabled(bool is_enabled);
            void SetVisible(bool is_visible);
        public:

        private:
            FX::FXRect rect;
    };
}

#endif

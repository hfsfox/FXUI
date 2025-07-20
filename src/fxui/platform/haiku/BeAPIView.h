/*
 * Copyright 2018, Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef __BEAPIVIEW_H__
#define __BEAPIVIEW_H__

#include <interface/View.h>

namespace FX
{
	class FXDisplay;
}


class BeAPIView : public BView
	{
	public:
    	BeAPIView(BRect frame, FX::FXDisplay* display);
	public:
		virtual void Draw(BRect updateRect) override;
    	virtual void MouseUp(BPoint point) override;
		virtual void MouseDown(BPoint point) override;

	private:
    	FX::FXDisplay* fDisplay;
	public:
    	static int frameCount;
	};

#endif

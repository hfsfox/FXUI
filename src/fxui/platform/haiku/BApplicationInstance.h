/*
 * Copyright 2018, Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef __BAPPLICATIONINSTANCE_H__
#define __BAPPLICATIONINSTANCE_H__
#if defined BACKEND_BEAPI
#include <Application.h>
#include <SupportDefs.h>

#include <mutex>
#include <memory>

class BApplicationInstance
{
	public:
		static BApplication* GetInstance();
		// Prevent copying and assignment
    	BApplicationInstance(const BApplicationInstance&) = delete;
    	BApplicationInstance& operator=(const BApplicationInstance&) = delete;
	private:
		BApplicationInstance() = default;
		static std::once_flag initialized;
    	static std::unique_ptr<BApplication> instance;
};

#endif

#endif // _H

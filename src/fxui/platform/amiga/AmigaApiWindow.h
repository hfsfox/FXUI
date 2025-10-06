#include <fxplatformuidefs.h>

#ifdef BACKEND_MUI

#ifdef PLATFORM_MORPHOS
#include <exec/execbase.h>
#include <exec/system.h>
#endif
#include <proto/exec.h>
#include <exec/ports.h>
#include <exec/resident.h>
#include <exec/memory.h>
#include <exec/types.h>
#include <exec/memory.h>
#include <exec/nodes.h>
#include <proto/dos.h>
#include <exec/libraries.h>

#include <devices/timer.h>
#include <proto/alib.h>

#include <devices/clipboard.h>
#include <exec/io.h>

#include <exec/semaphores.h>

#include <proto/graphics.h>
#include <proto/cybergraphics.h>
#include <cybergraphx/cybergraphics.h>
#include <graphics/gfxbase.h>

#include <proto/muimaster.h>
#include <proto/intuition.h>

namespace
{
}

class MUIAPIObject
{
	public:
		MUIAPIObject()
		{
		}
		~MUIAPIObject()
		{
		}
	private:
};

#endif

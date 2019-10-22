#include <stdio.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main()
{
	Display *d;
	int wx,wy;
	// Open Display
	d=XOpenDisplay(NULL);

	if (d != NULL) {
		// Get screen width and height
		wx = WidthOfScreen(XDefaultScreenOfDisplay(d));
		wy = HeightOfScreen(XDefaultScreenOfDisplay(d));
		// Move mouse pointer
		XWarpPointer(d, None, DefaultRootWindow(d), 0,0,0,0,wx,wy);
		XFlush(d);
		// Close Display
	} else {
		printf("Can't Open Display!!\n");
		return 1;
	}

	return 0;
}

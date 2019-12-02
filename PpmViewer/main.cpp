#ifdef WIN32_
#define WIN32 1
#endif


#include "PpmWindow.hpp"
int main(int argc, char* argv[])
{
	PpmWindow win{ new PpmDocument{ "bunny.ppm" }, 0, 0, 500, 500, "PPME v0.06 " };
	win.end();
	win.show();
	return Fl::run();
}
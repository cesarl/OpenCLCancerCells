#include "App.hpp"
#undef main

int main(int argc, char **argv)
{
	App app;
	if (!app.init())
		return EXIT_FAILURE;
	app.generateBuffers(128 * 128 );
	app.generateBuffers();
	while (app.run())
	{ }
	app.deactivate();
	return EXIT_SUCCESS;
}
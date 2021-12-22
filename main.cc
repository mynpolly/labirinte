#include <iostream>
#include <SDL2/SDL.h>

#include "MazeWindow.h"

int WinMain(int, char **)
{
	try {
		MazeWindow w;

		w.main_loop();
	} catch (const std::exception &e) {
		std::cerr <<
				"Во время выполнения программы\n"
				"произошла следующая ошибка:\n" <<
				e.what() <<
				std::endl;
		return 1;
	}


	return 0;
}

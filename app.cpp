#include "app.h"

void App::run() {
	while (true) {
		menus[currMenuIdx]->prompt();
	}
}
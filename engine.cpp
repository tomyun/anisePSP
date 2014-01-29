#include "trace.h"
#include "engine.h"

Engine::Engine(Option *option)
{
	this->option = option;
}


Engine::~Engine()
{
}


bool Engine::on()
{
	//TODO: move this method into constructor?

	//TODO: initialize font

	//TODO: initialize video, mouse and keyboard (SDL related)
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_JOYSTICK);

	SDL_WM_SetCaption(TITLE, NULL);

	SDL_Joystick *_joystick = NULL;
	if (SDL_NumJoysticks() > 0) {
		_joystick = SDL_JoystickOpen(0);
	}

	memory = new Memory(option);
	timer = new Timer();
	input = new Input(memory, timer);
	file = new File(memory, option);
	sound = new Sound(file, option);
	video = new Video(memory, timer, option);

	script = new Script(memory, timer, input, sound, video, file, option);

	return true;
}


bool Engine::off()
{
	delete script;
	delete video;
	delete sound;
	delete input;
	delete timer;
	delete memory;
	delete file;

	SDL_Quit();

	printf("[Engine::off()] successfully turned off\n");

	return true;
}


bool Engine::run()
{
	script->load(option->script_file_name.c_str());
	SCRIPTCALL condition = script->parse();

	if (condition == RETURN_ERROR) {
		PRINT_ERROR("[Engine::run()] terminated by error\n");
		return false;
	}
	else {
		return true;
	}
}

// 제작: AmesianX in POWERHACKER.NET
// 배포: powerhacker.net

#include "engine.h"
#include "trace.h"

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <psppower.h>
#include <pspgu.h>
#include <stdio.h>

PSP_MODULE_INFO("anisePSP", 0x1000, 1, 1);

PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

void MyExceptionHandler(PspDebugRegBlock *regs) {
	/* Do normal initial dump, setup screen etc */

	pspDebugScreenInit();

	pspDebugScreenSetBackColor(0x00FF0000);
	pspDebugScreenSetTextColor(0xFFFFFFFF);
	pspDebugScreenClear();

	pspDebugScreenPrintf("Exception Details:\n");
	pspDebugDumpException(regs);

	sceKernelDelayThread(1000);
	while(1);

//	sceGuTerm();
//	sceKernelExitGame();
}

/**
 * Function that is called from _init in kernelmode before the
 * main thread is started in usermode.
 */
__attribute__ ((constructor))
void loaderInit() {
	pspKernelSetKernelPC();
	pspDebugInstallErrorHandler(MyExceptionHandler);
}

/* Exit callback */
SceKernelCallbackFunction exit_callback(int /*arg1*/, int /*arg2*/, void * /*common*/)
{
	scePowerSetClockFrequency(222,222,111);
	SDL_CloseAudio();
	SDL_Quit();
	sceGuTerm();
	sceKernelExitGame();

	return 0;
}

/* Callback thread */
int CallbackThread(SceSize /*size*/, void *arg) {
	int cbid;

	cbid = sceKernelCreateCallback("Exit Callback", (SceKernelCallbackFunction)exit_callback, NULL);
	sceKernelRegisterExitCallback(cbid);

	sceKernelSleepThreadCB();
	return 0;
}

/* Sets up the callback thread and returns its thread id */
int SetupCallbacks(void)
{
	int thid = 0;

	thid = sceKernelCreateThread("update_thread", CallbackThread, 0x11, 0xFA0, THREAD_ATTR_USER, 0);
	if(thid >= 0)
	{
		sceKernelStartThread(thid, 0, 0);
	}

	return thid;
}

typedef struct GameConfig
{
	char GamePath[255];
	char GameName[100];
	char GameSound[10];
	char GameLang[20];
} GAMECFG;

GAMECFG GameCfg;

bool GetOption(char *ReadBuff, char *GameData, char *options)
{
	char *ptr;
	char *ptr2;

	int  len = 0;

	if( (ptr = strstr(ReadBuff, options)) != NULL) {
		if( (ptr = strstr(ptr, "=")) != NULL) {
			while(*ptr != '"') {
				ptr++;
			}

			ptr2 = ptr++;

			while(ptr2++) {
				if(*ptr2 == '"') {
					len = ptr2 - ptr;
					strncpy(GameData, ptr, len);
					return true;
				}
			}
		}
	}

	return false;
}

int main(void)
{
	PSPDebugTrace("[anisePSP]\nAmesianX in PowerHacker.net\n");
	pspDebugScreenInit();

	SetupCallbacks();

	FILE    *fd;
	char    buff[2048];
	char    DEBUGBUF[1024];

	char	NEW_PATH[255];
	char	NEW_GAMENAME[100];
	char	NEW_SOUND[10];
	char	*NEW_LANG;


	fd = fopen("ms0:/anisePSP/anisePSP.cfg", "r");

	fread((void *)buff, sizeof(buff), 1, fd);

	fclose(fd);

	bzero(&GameCfg, sizeof(GameCfg));

	if(!GetOption(buff, GameCfg.GamePath, "GAMEPATH")) { sceGuTerm(); sceKernelExitGame(); }
	if(!GetOption(buff, GameCfg.GameName, "GAMENAME")) { sceGuTerm(); sceKernelExitGame(); }
	if(!GetOption(buff, GameCfg.GameSound, "SOUND"))   { sceGuTerm(); sceKernelExitGame(); }
	if(!GetOption(buff, GameCfg.GameLang, "LANGUAGE")) { sceGuTerm(); sceKernelExitGame(); }

	/*
	[ANISEPSP]
	GAMEPATH=ms0:/anisePSP/kawa
	GAMENAME=kawa
	SOUND=0
	LANGUAGE=korean
	*/

	sprintf(NEW_PATH, "-p=%s", GameCfg.GamePath);
	sprintf(NEW_GAMENAME, "%s", GameCfg.GameName);
	sprintf(NEW_SOUND, "-s%s", GameCfg.GameSound);
	if(strncmp(GameCfg.GameLang, "korean", 6) == 0) NEW_LANG = "-lk";
	else NEW_LANG = "-ls";

	scePowerSetClockFrequency(333, 333, 166);

	int new_argc = 5;
//	char *new_argv[] = { "anisePSP", "-p=ms0:/anisePSP/kawa", "-s0", "-ls", "kawa" };
//	char *new_argv[] = { "anisePSP", "-p=ms0:/anisePSP/anisePSP/nanpa2", "-s4", "-lk", "nanpa2" };
	char *new_argv[] = { "anisePSP", NEW_PATH, NEW_SOUND, NEW_LANG, NEW_GAMENAME };

	sprintf(DEBUGBUF, "[DEBUG] new_argv = \"anisePSP\", \"%s\", \"%s\", \"%s\", \"%s\" / GameCfg.GameLang = %s", NEW_PATH, NEW_SOUND, NEW_LANG, NEW_GAMENAME, GameCfg.GameLang);
	PSPDebugTrace(DEBUGBUF);

	Option *option = new Option();

	if (option->initialize(new_argc, new_argv) == false);

	Engine *engine = new Engine(option);
	engine->on();
	engine->run();
	engine->off();

	delete engine;
	delete option;

	sceKernelSleepThread();

	return 0;
}

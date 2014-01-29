#include "input.h"
#include "video.h"
#include "trace.h"
#include <pspctrl.h>

Input::Input(Memory *memory, Timer *timer)
{
	this->memory = memory;
	this->timer = timer;

	// AmesianX
	sceCtrlSetSamplingMode(1);
	sceCtrlSetSamplingCycle(0);

	keyboard_status = 0;
	mouse_status = 0;

	is_left_clicked = false;
	is_right_clicked = false;

	is_quit = false;
	is_capture = false;

	for (int i = 0; i < 2; i++) {
		for (int y = 0; y < CURSOR_HEIGHT; y++) {
			for (int x = 0; x < CURSOR_WIDTH; x++) {
				cursor_image[i][(y * CURSOR_WIDTH) + x] = 0;
				cursor_mask[i][(y * CURSOR_WIDTH) + x] = 0;
			}
		}
	}

	cursor[CURSOR_FIRSTFRAME] = NULL;
	cursor[CURSOR_SECONDFRAME] = NULL;

	current_cursor_frame = 0;

	old_mouse_x = mouse_x = 0;
	old_mouse_y = mouse_y = 0;

	movecnt = 2;

#ifdef _WIN32_WCE_IBEE
	IBEE_key_func = false;
#endif

	hideCursor();
}


Input::~Input()
{
	if (cursor[CURSOR_FIRSTFRAME] != NULL) {
		SDL_FreeCursor(cursor[CURSOR_FIRSTFRAME]);
	}
	if (cursor[CURSOR_SECONDFRAME] != NULL) {
		SDL_FreeCursor(cursor[CURSOR_SECONDFRAME]);
	}
}

bool Input::refreshKeyboard()
{
	keyboard_status = 0;
	static int temp = 0;

	SceCtrlData paddata;
	sceCtrlPeekBufferPositive(&paddata, 1);

	if (paddata.Ly == 0xff) paddata.Buttons=PSP_CTRL_DOWN;  // DOWN
	if (paddata.Ly == 0x00) paddata.Buttons=PSP_CTRL_UP;    // UP
	if (paddata.Lx == 0x00) paddata.Buttons=PSP_CTRL_LEFT;  // LEFT
	if (paddata.Lx == 0xff) paddata.Buttons=PSP_CTRL_RIGHT; // RIGHT

	new_pad = paddata.Buttons;

	if (new_pad & PSP_CTRL_CIRCLE) {
				keyboard_status |= INPUT_OK;
				is_left_clicked = true;
				paddata.Buttons = 0x00;
	}

	if (new_pad & PSP_CTRL_CROSS) {
				keyboard_status |= INPUT_CANCEL;
				is_right_clicked = true;
				paddata.Buttons = 0x00;
	}

	if (new_pad & PSP_CTRL_UP) {
				keyboard_status |= INPUT_UP;
	}

	if (new_pad & PSP_CTRL_DOWN) {
				keyboard_status |= INPUT_DOWN;
	}

	if (new_pad & PSP_CTRL_LEFT) {
				keyboard_status |= INPUT_LEFT;
	}

	if (new_pad & PSP_CTRL_RIGHT) {
				keyboard_status |= INPUT_RIGHT;
	}

	if (new_pad & PSP_CTRL_START) {
				keyboard_status |= INPUT_CTRL;
				paddata.Buttons = 0x00;
	}

	if (new_pad & PSP_CTRL_SELECT) {
				is_quit = true;
				return false;
	}

	if (new_pad & PSP_CTRL_TRIANGLE) {
				keyboard_status |= INPUT_END;
				paddata.Buttons = 0x00;
	}

	if (new_pad & PSP_CTRL_SQUARE) {
				keyboard_status |= INPUT_SHIFT;
				paddata.Buttons = 0x00;
	}

	if (new_pad & PSP_CTRL_LTRIGGER) {
				movecnt--;
				if(movecnt < 2) movecnt = 2;
				paddata.Buttons = 0x00;
	}

	if (new_pad & PSP_CTRL_RTRIGGER) {
				movecnt++;
				if(movecnt > 5) movecnt = 5;
				paddata.Buttons = 0x00;
	}

	if (paddata.Ly == 0xff) {
		mouse_y += movecnt;  // DOWN

		if(mouse_y > 400)
			mouse_y = 400;
	}
	if (paddata.Ly == 0x00) {
		mouse_y -= movecnt;  // UP

		if(mouse_y < 0)
			mouse_y = 0;
	}
	if (paddata.Lx == 0x00) {
		mouse_x -= movecnt;  // LEFT

		if(mouse_x < 0)
			mouse_x = 0;
	}
	if (paddata.Lx == 0xff) {
		mouse_x += movecnt;  // RIGHT

		if(mouse_x > 640)
			mouse_x = 640;
	}

	if((old_mouse_x - mouse_x) > movecnt) // LEFT
		mouse_x = old_mouse_x - movecnt;
	if((mouse_x - old_mouse_x) > movecnt) // RIGHT
		mouse_x = old_mouse_x + movecnt;
	if((old_mouse_y - mouse_y) > movecnt) // UP
		mouse_y = old_mouse_y - movecnt;
	if((mouse_y - old_mouse_y) > movecnt) // DOWN
		mouse_y = old_mouse_y + movecnt;

	old_mouse_x = mouse_x;
	old_mouse_y = mouse_y;

	SDL_WarpMouse((Uint16) mouse_x, (Uint16) mouse_y);

	memory->b_SystemVariable->writeWord(iw_Mouse_CoordX, mouse_x);
	memory->b_SystemVariable->writeWord(iw_Mouse_CoordY, mouse_y);

/*
	if (timer->checkCursorTimer() > CURSOR_FRAME) {
		current_cursor_frame ^= 1;
		setCursorImage(current_cursor_frame);
		timer->resetCursorTimer();
	}
*/

	return true;
}

void Input::refreshMouse(word *coord_x, word *coord_y)
{
/*
	int row, column;
	mouse_status = (word) SDL_GetMouseState(&row, &column);

	*coord_x = (word) row;
	*coord_y = (word) column;

	if((mouse_status & SDL_BUTTON_LMASK) == SDL_BUTTON_LMASK)
		printf("Mouse Position(Left Click) : %d x %d\n", *coord_x, *coord_y);
	if((mouse_status & SDL_BUTTON_RMASK) == SDL_BUTTON_RMASK)
		printf("Mouse Position(Right Click) : %d x %d\n", *coord_x, *coord_y);
*/
	refreshKeyboard();
	*coord_x = mouse_x;
	*coord_y = mouse_y;
/*
	memory->b_SystemVariable->writeWord(iw_Mouse_CoordX, *coord_x);
	memory->b_SystemVariable->writeWord(iw_Mouse_CoordY, *coord_y);

	if (timer->checkCursorTimer() > CURSOR_FRAME) {
		current_cursor_frame ^= 1;
		setCursorImage(current_cursor_frame);
		timer->resetCursorTimer();
	}
*/
}


void Input::refreshMouse()
{
	word coord_x, coord_y;
	refreshMouse(&coord_x, &coord_y);
}


bool Input::refresh()
{
	if (!is_quit) {
		refreshMouse();
		return refreshKeyboard();
	}
	else {
		return false;
	}
}


bool Input::check(word type)
{
	word keyboard = 0;
	word mouse = 0;

	switch (type) {
		case INPUT_OK:
			keyboard = keyboard_status & INPUT_OK;
			mouse = isLeftClicked(); //mouse_status & SDL_BUTTON_LMASK;
			break;

		case INPUT_CANCEL:
			keyboard = keyboard_status & INPUT_CANCEL;
			mouse = isRightClicked(); //mouse_status & SDL_BUTTON_RMASK;
			break;

		case INPUT_UP:
			keyboard = keyboard_status & INPUT_UP;
			break;

		case INPUT_DOWN:
			keyboard = keyboard_status & INPUT_DOWN;
			break;

		case INPUT_LEFT:
			keyboard = keyboard_status & INPUT_LEFT;
			break;

		case INPUT_RIGHT:
			keyboard = keyboard_status & INPUT_RIGHT;
			break;

		case INPUT_CTRL:
			keyboard = keyboard_status & INPUT_CTRL;
			break;

		case INPUT_END:
			keyboard = keyboard_status & INPUT_END;
			break;

		case INPUT_SHIFT:
			keyboard = keyboard_status & INPUT_SHIFT;
			break;
	}

	return ((keyboard != 0) || (mouse != 0));
}

bool Input::isCapture()
{
	if (is_capture) {
		is_capture = false;
		return true;
	}
	else {
		return false;
	}
}


bool Input::isKeyPressed()
{
	//TODO: need refreshKeyboard()?
	// refreshKeyboard();
	return (keyboard_status != 0);
}


bool Input::isLeftClicked()
{
	refreshMouse();

	bool ret = is_left_clicked;
	is_left_clicked = false;

	return ret;
/*
	refreshMouse();

	return ((mouse_status & SDL_BUTTON_LMASK) == SDL_BUTTON_LMASK);
*/
}


bool Input::isRightClicked()
{
	refreshMouse();

	bool ret = is_right_clicked;
	is_right_clicked = false;

	return ret;
/*
	refreshMouse();

	return ((mouse_status & SDL_BUTTON_RMASK) == SDL_BUTTON_RMASK);
*/
}


bool Input::isCursorVisible()
{
	if (SDL_ShowCursor(SDL_QUERY) == SDL_ENABLE) {
		return true;
	}
	else {
		return false;
	}
}


void Input::showCursor()
{
	SDL_ShowCursor(SDL_ENABLE);
}


void Input::hideCursor()
{
	SDL_ShowCursor(SDL_DISABLE);
}


void Input::setCursorPosition(word coord_x, word coord_y)
{
	SDL_WarpMouse((Uint16) coord_x, (Uint16) coord_y);

	mouse_x = coord_x;
	mouse_y = coord_y;

	memory->b_SystemVariable->writeWord(iw_Mouse_CoordX, mouse_x);
	memory->b_SystemVariable->writeWord(iw_Mouse_CoordY, mouse_y);

	if (timer->checkCursorTimer() > CURSOR_FRAME) {
		current_cursor_frame ^= 1;
		setCursorImage(current_cursor_frame);
		timer->resetCursorTimer();
	}
}

void Input::loadCursorImage(word offset)
{
	MemorySegment *segment = memory->getCurrentSegment();
	MemoryBlock *source = segment->get(&offset);

	for (int i = 0; i < 2; i++) {
		int x, y;
		for (y = 0; y < CURSOR_HEIGHT; y++) {
			for (x = 0; x < CURSOR_WIDTH; x++) {
				cursor_image[i][(y * CURSOR_WIDTH) + x] = source->queryByte(offset++);
			}
		}

		for (y = 0; y < CURSOR_HEIGHT; y++) {
			for (x = 0; x < CURSOR_WIDTH; x++) {
				cursor_mask[i][(y * CURSOR_WIDTH) + x] = ~(source->queryByte(offset++));
			}
		}

		for (y = 0; y < CURSOR_HEIGHT; y++) {
			for (x = 0; x < CURSOR_WIDTH; x++) {
				cursor_image[i][(y * CURSOR_WIDTH) + x] ^= cursor_mask[i][(y * CURSOR_WIDTH) + x];
			}
		}

		cursor[i] = SDL_CreateCursor(cursor_image[i], cursor_mask[i], CURSOR_SIZE, CURSOR_SIZE, 0, 0);
	}
}


void Input::setCursorImage(int cursor_frame)
{
	SDL_SetCursor(cursor[cursor_frame]);
}

void Input::reset()
{
	is_left_clicked = false;
	is_right_clicked = false;
}

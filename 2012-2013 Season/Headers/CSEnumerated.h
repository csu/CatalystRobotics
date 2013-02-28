#ifndef ENUMS_H
#define ENUMS_H

#pragma systemFile

typedef enum ControllerMeta
{
	CONTROLLER_A = 1,
	CONTROLLER_B = 2,
};

typedef enum ControllerHat
{
	HAT_NONE = -1,
	HAT_N = 0,
	HAT_NE = 1,
	HAT_E = 2,
	HAT_SE = 3,
	HAT_S = 4,
	HAT_SW = 5,
	HAT_W = 6,
	HAT_NW = 7,
};

typedef enum ControllerJoystick
{
	JOYSTICK_L = 0,
	JOYSTICK_R = 1,
};

typedef enum ControllerJoystickAxis
{
	AXIS_X = 0,
	AXIS_Y = 1,
};

typedef enum ControllerButton //not done defining these yet
{
	BUTTON_A = 2,
};

#endif

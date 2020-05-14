#include "keyboard.h"
#include "../rebel.h"

Keys c_lastKeyPressed;

bool KeyIsDown(Keys key)
{
	return (glfwGetKey(g_rebel.window.glWindow, key) == GLFW_PRESS);
}

bool KeyIsUp(Keys key)
{
	if (glfwGetKey(g_rebel.window.glWindow, key) == GLFW_PRESS)
		c_lastKeyPressed = key;
	
	if (c_lastKeyPressed == key && glfwGetKey(g_rebel.window.glWindow, key) == GLFW_RELEASE)
	{
		c_lastKeyPressed = KEY_UNKNOWN;
		return true;
	}
	return false;
}

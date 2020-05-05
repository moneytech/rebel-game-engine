#pragma once

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

#include "core/window.h"
#include "chibi/eval.h"
#include "graphics/sprite.h"
#include "graphics/shader.h"
#include "input/keyboard.h"

typedef struct Rebel {
	TShader defaultShader;
	Window window;
	sexp scriptCtx;
} Rebel;

extern Rebel g_rebel;

typedef struct Foo {
	unsigned int bar;
} Foo;

typedef struct Tebel {
	Foo foo;
	unsigned int x;
	unsigned int y;
} Tebel;

extern Tebel g_tebel;

namespace rebel
{
	void Init(unsigned int windowWidth, unsigned int windowHeight, const char* windowName);
	void ProcessInputs();
	void Destroy();
}

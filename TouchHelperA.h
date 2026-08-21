#pragma once

#include "VectorStruct.h"

extern int Touch_ID;
extern int Touch_I;
extern int Touch_I_bak;
extern Vector2 Touch_Clicks;    
extern int Touch_Global_SLOT;
extern int Touch_Temporary_SLOT;
extern int Touch_Temporary_SLOT_Bak;

/** 初始化 evdev 触摸/鼠标、可选 uinput 注入；读事件由 Touch_PumpAll 在主循环中驱动 */
bool Touch_Init(int w, int h, uint32_t orientation_, bool readOnly);
void UpdateScreenData(int w, int h, uint32_t orientation_);
/** 每帧调用：非阻塞排空触摸与鼠标 fd 的 input_event，更新 ImGui / Finger / Upload */
void Touch_PumpAll();

void Touch_Close();
void Touch_Down(float x, float y);
void Touch_Move(float x, float y);
void Touch_Up();


#pragma once
#include <Windows.h>

struct DesktopUtils {
    static void getDesktopSize(unsigned int& width, unsigned int& height) {
        RECT desktop;
        const HWND hDesktop = GetDesktopWindow();
        GetWindowRect(hDesktop, &desktop);
        width = desktop.right;
        height = desktop.bottom;
    }
};

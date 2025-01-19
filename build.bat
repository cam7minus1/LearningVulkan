@echo off

call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"

SET includes=/Isrc ^
            /I%VULKAN_SDK%/include ^
            /I..\externals\GLFW\include ^
            /I..\externals\GLM

SET links=/link ^
    /LIBPATH:%VULKAN_SDK%\Lib ^
    /LIBPATH:..\externals\GLFW\lib-vc2022 ^
    vulkan-1.lib ^
    glfw3.lib ^
    user32.lib ^
    gdi32.lib ^
    shell32.lib

SET defines=/DDEBUG

REM -------------------------------------
REM The crucial part: /MD for dynamic CRT
REM -------------------------------------
cl /EHsc /MD %includes% %defines% src\main.cpp %links%


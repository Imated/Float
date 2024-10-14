workspace "Float"
    language "C++"
    architecture "x86_64"
    configurations { "Debug", "Release" }
    
    filter { "configurations:Debug" }
    symbols "On"
    
    filter { "configurations:Release" }
    optimize "On"
    
    filter {} -- Reset the filter
    
    targetdir ("Build/Bin/%{prj.name}/%{cfg.longname}")
    objdir ("Build/Obj/%{prj.name}/%{cfg.longname}")
    
    startproject "app"

project "Float"
    kind "ConsoleApp"
    targetname "Float"
    
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    pchheader "pch.h"
    pchsource "src/pch.cpp"
    
    files
    {
        "src/**.h",
        "src/**.cpp",
        "assets"
    }
    
    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
    }
    
    includedirs
    {
        "src",
        "libs/glad/include/",
        "libs/glm/glm/",
        "libs/SDL2/include/",
        "libs/",
    }
    
    links
    {
        "opengl32.lib",
        "winmm.lib",
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"

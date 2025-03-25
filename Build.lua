-- premake5.lua
workspace "SFML-PreMake"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "App"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }
      defines{"BASE_PLATFORM_WINDOWS"}

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Core"
	include "Core/Build-Core.lua"
   include "Core/Vendor/SFML/Build-Sfml.lua"
   include "Core/Vendor/RapidJSON/rapidjson-1.1.0/rapidjson-1.1.0/Build-Rapid.lua"
group ""

include "App/Build-App.lua"
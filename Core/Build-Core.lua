project "Core"
   kind "StaticLib"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   pchheader "Corepch.h"
   pchsource "Source/Corepch.cpp"
   files { "Source/**.h", "Source/**.cpp" }
   defines{"SFML_STATIC", "FLAC__NO_DLL", "AL_STATIC", "_CRT_SECURE_NO_WARNINGS"}

   includedirs
   {
      "Source", "Vendor/SFML/include", "Vendor/SFML/extlibs/libs-msvc-universal/x64", 
      "Vendor/RapidJSON/rapidjson-1.1.0/rapidjson-1.1.0/include"
   }

   libdirs{"Vendor/SFML/extlibs/libs-msvc-universal/x64"}
   links{
        "SFML", "RapidJSON",
		"freetype.lib","winmm.lib","opengl32.lib", "flac.lib","openal32.lib",
        "ogg.lib", "vorbis.lib","vorbisfile.lib", "vorbisenc.lib"
   }

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

 


   filter "system:windows"
       systemversion "latest"
       defines { }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"
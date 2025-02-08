project "App"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp"}
   defines{"SFML_STATIC","FLAC__NO_DLL", "AL_STATIC"}
   includedirs
   {
      "Source",
      "Media",
      "../Core/Vendor/SFML/include",

	  -- Include Core
	  "../Core/Source"
   }

   links
   {
      "Core", "SFML"
   }

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   postbuildcommands{
    '{COPY} "../Core/Vendor/SFML/extlibs/bin/x64/openal32.dll" "../Binaries/"'.. OutputDir .. '"/%{prj.name}"',
    '{COPYDIR} "Media" "../Binaries/"'.. OutputDir .. '"/%{prj.name}/Media"'
}

   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }

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

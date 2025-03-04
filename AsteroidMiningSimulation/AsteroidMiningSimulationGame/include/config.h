#pragma once
#include <string>
#include <filesystem>

inline std::string GetResourceDir()
{
	namespace fs = std::filesystem;

	// Get the directory where the executable is located
	fs::path exeDir = fs::current_path();

#ifdef NDEBUG  // Release build
	return (exeDir / "assets").string();
#else
	return (exeDir / "assets").string(); // Same structure for debug mode
#endif
}

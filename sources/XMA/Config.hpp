#ifndef _XMAGL_CONFIG_HPP
#define _XMAGL_CONFIG_HPP


#define XMA_DEBUG true

// ---------------------------------------------------------------------------------------------------------------------
// OPERATING SYSTEM
// ---------------------------------------------------------------------------------------------------------------------

#if defined(_WIN32)
    #define XMA_SYSTEM_WINDOWS
#elif defined(__APPLE__) && defined(__MACH__)
    #include "TargetConditionals.h"
    #if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
        #define XMA_SYSTEM_IOS
    #elif TARGET_OS_MAC
        #define XMA_SYSTEM_MACOS
    #else
        #error This Apple operating system is not supported by XMA
    #endif
#elif defined(__unix__)
#if defined(__ANDROID__)
        #define XMA_SYSTEM_ANDROID
    #elif defined(__linux__)
        #define XMA_SYSTEM_LINUX
    #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
        #define XMA_SYSTEM_FREEBSD
    #else
        #error This UNIX operating system is not supported by XMA
    #endif
#else
    #error This operating system is not supported by XMA
#endif

// ---------------------------------------------------------------------------------------------------------------------
// OpenGL
// ---------------------------------------------------------------------------------------------------------------------

#include <GL/glew.h>

#if defined(XMA_SYSTEM_WINDOWS)
#ifdef _MSC_VER
        #include <windows.h>
    #endif
    #include <GL/gl.h>
#elif defined(XMA_SYSTEM_LINUX) || defined(XMA_SYSTEM_FREEBSD)
#if defined(XMA_OPENGL_ES)
        #include <GLES/gl.h>
        #include <GLES/glext.h>
    #else
        #include <GL/gl.h>
    #endif
#elif defined(XMA_SYSTEM_MACOS)
    #include <OpenGL/gl.h>
#elif defined (XMA_SYSTEM_IOS)
#include <OpenGLES/ES1/gl.h>
    #include <OpenGLES/ES1/glext.h>
#elif defined (XMA_SYSTEM_ANDROID)
    #include <GLES/gl.h>
    #include <GLES/glext.h>
    #include <GLES2/gl2ext.h>
#endif

// ---------------------------------------------------------------------------------------------------------------------
// SDL
// ---------------------------------------------------------------------------------------------------------------------

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_opengl.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_net.h>

// ---------------------------------------------------------------------------------------------------------------------
// GLM
// ---------------------------------------------------------------------------------------------------------------------

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

// ---------------------------------------------------------------------------------------------------------------------
// STL
// ---------------------------------------------------------------------------------------------------------------------

#include <cstdlib>
#include <csignal>
#include <csetjmp>
#include <cstdarg>
#include <typeinfo>
#include <typeindex>
#include <type_traits>
#include <bitset>
#include <functional>
#include <utility>
#include <ctime>
#include <chrono>
#include <cstddef>
#include <initializer_list>
#include <tuple>
#include <new>
#include <memory>
#include <scoped_allocator>
#include <climits>
#include <cfloat>
#include <cstdint>
#include <cinttypes>
#include <limits>
#include <exception>
#include <stdexcept>
#include <cassert>
#include <system_error>
#include <cerrno>
#include <cctype>
#include <cwctype>
#include <cstring>
#include <cwchar>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>
#include <valarray>
#include <random>
#include <numeric>
#include <ratio>
#include <cfenv>
#include <iosfwd>
#include <ios>
#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <strstream>
#include <iomanip>
#include <streambuf>
#include <cstdio>
#include <locale>
#include <clocale>
#include <codecvt>
#include <regex>
#include <atomic>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <future>
#include <condition_variable>

// ---------------------------------------------------------------------------------------------------------------------
// XMA
// ---------------------------------------------------------------------------------------------------------------------

#define XMA_PRIVATE_DATA() private: struct Data; std::unique_ptr<Data> m_data;
#define XMA_PROTECTED_DATA() protected: struct Data; std::unique_ptr<Data> m_data;
#define XMA_THROW(msg) throw std::runtime_error(msg);

#include <XMA/Assert.hpp>
#include <XMA/Debug.hpp>

// ---------------------------------------------------------------------------------------------------------------------

#endif

#ifndef _XMAGL_CORE_INPUT_HXX
#define _XMAGL_CORE_INPUT_HXX

#include <XMA/Core/Config.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

namespace Mouse
{
    enum Button
    {
        LEFT   = 1,
        MIDDLE = 2,
        RIGHT  = 3,
        X1     = 4,
        X2     = 5,
        LMASK  = (1 << ((1)-1)),
        MMASK  = (1 << ((2)-1)),
        RMASK  = (1 << ((3)-1)),
        X1MASK = (1 << ((4)-1)),
        X2MASK = (1 << ((5)-1)),
    };
}

// ---------------------------------------------------------------------------------------------------------------------

namespace Key
{
    enum Code
    {
        RETURN = SDLK_RETURN,
        ESCAPE = SDLK_ESCAPE,
        BACKSPACE = SDLK_BACKSPACE,
        TAB = SDLK_TAB,
        SPACE = SDLK_SPACE,
        EXCLAIM = SDLK_EXCLAIM,
        QUOTEDBL = SDLK_QUOTEDBL,
        HASH = SDLK_HASH,
        PERCENT = SDLK_PERCENT,
        DOLLAR = SDLK_DOLLAR,
        AMPERSAND = SDLK_AMPERSAND,
        QUOTE = SDLK_QUOTE,
        LEFTPAREN = SDLK_LEFTPAREN,
        RIGHTPAREN = SDLK_RIGHTPAREN,
        ASTERISK = SDLK_ASTERISK,
        PLUS = SDLK_PLUS,
        COMMA = SDLK_COMMA,
        MINUS = SDLK_MINUS,
        PERIOD = SDLK_PERIOD,
        SLASH = SDLK_SLASH,
        NUM0 = SDLK_0,
        NUM1 = SDLK_1,
        NUM2 = SDLK_2,
        NUM3 = SDLK_3,
        NUM4 = SDLK_4,
        NUM5 = SDLK_5,
        NUM6 = SDLK_6,
        NUM7 = SDLK_7,
        NUM8 = SDLK_8,
        NUM9 = SDLK_9,
        COLON = SDLK_COLON,
        SEMICOLON = SDLK_SEMICOLON,
        LESS = SDLK_LESS,
        EQUALS = SDLK_EQUALS,
        GREATER = SDLK_GREATER,
        QUESTION = SDLK_QUESTION,
        AT = SDLK_AT,
        LEFTBRACKET = SDLK_LEFTBRACKET,
        BACKSLASH = SDLK_BACKSLASH,
        RIGHTBRACKET = SDLK_RIGHTBRACKET,
        CARET = SDLK_CARET,
        UNDERSCORE = SDLK_UNDERSCORE,
        BACKQUOTE = SDLK_BACKQUOTE,
        A = SDLK_a,
        B = SDLK_b,
        C = SDLK_c,
        D = SDLK_d,
        E = SDLK_e,
        F = SDLK_f,
        G = SDLK_g,
        H = SDLK_h,
        I = SDLK_i,
        J = SDLK_j,
        K = SDLK_k,
        L = SDLK_l,
        M = SDLK_m,
        N = SDLK_n,
        O = SDLK_o,
        P = SDLK_p,
        Q = SDLK_q,
        R = SDLK_r,
        S = SDLK_s,
        T = SDLK_t,
        U = SDLK_u,
        V = SDLK_v,
        W = SDLK_w,
        X = SDLK_x,
        Y = SDLK_y,
        Z = SDLK_z,
        CAPSLOCK = SDLK_CAPSLOCK,
        F1 = SDLK_F1,
        F2 = SDLK_F2,
        F3 = SDLK_F3,
        F4 = SDLK_F4,
        F5 = SDLK_F5,
        F6 = SDLK_F6,
        F7 = SDLK_F7,
        F8 = SDLK_F8,
        F9 = SDLK_F9,
        F10 = SDLK_F10,
        F11 = SDLK_F11,
        F12 = SDLK_F12,
        PRINTSCREEN = SDLK_PRINTSCREEN,
        SCROLLLOCK = SDLK_SCROLLLOCK,
        PAUSE = SDLK_PAUSE,
        INSERT = SDLK_INSERT,
        HOME = SDLK_HOME,
        PAGEUP = SDLK_PAGEUP,
        DELETE = SDLK_DELETE,
        END = SDLK_END,
        PAGEDOWN = SDLK_PAGEDOWN,
        RIGHT = SDLK_RIGHT,
        LEFT = SDLK_LEFT,
        DOWN = SDLK_DOWN,
        UP = SDLK_UP,
        NUMLOCKCLEAR = SDLK_NUMLOCKCLEAR,
        KP_DIVIDE = SDLK_KP_DIVIDE,
        KP_MULTIPLY = SDLK_KP_MULTIPLY,
        KP_MINUS = SDLK_KP_MINUS,
        KP_PLUS = SDLK_KP_PLUS,
        KP_ENTER = SDLK_KP_ENTER,
        KP_1 = SDLK_KP_1,
        KP_2 = SDLK_KP_2,
        KP_3 = SDLK_KP_3,
        KP_4 = SDLK_KP_4,
        KP_5 = SDLK_KP_5,
        KP_6 = SDLK_KP_6,
        KP_7 = SDLK_KP_7,
        KP_8 = SDLK_KP_8,
        KP_9 = SDLK_KP_9,
        KP_0 = SDLK_KP_0,
        KP_PERIOD = SDLK_KP_PERIOD,
        APPLICATION = SDLK_APPLICATION,
        POWER = SDLK_POWER,
        KP_EQUALS = SDLK_KP_EQUALS,
        F13 = SDLK_F13,
        F14 = SDLK_F14,
        F15 = SDLK_F15,
        F16 = SDLK_F16,
        F17 = SDLK_F17,
        F18 = SDLK_F18,
        F19 = SDLK_F19,
        F20 = SDLK_F20,
        F21 = SDLK_F21,
        F22 = SDLK_F22,
        F23 = SDLK_F23,
        F24 = SDLK_F24,
        EXECUTE = SDLK_EXECUTE,
        HELP = SDLK_HELP,
        MENU = SDLK_MENU,
        SELECT = SDLK_SELECT,
        STOP = SDLK_STOP,
        AGAIN = SDLK_AGAIN,
        UNDO = SDLK_UNDO,
        CUT = SDLK_CUT,
        COPY = SDLK_COPY,
        PASTE = SDLK_PASTE,
        FIND = SDLK_FIND,
        MUTE = SDLK_MUTE,
        VOLUMEUP = SDLK_VOLUMEUP,
        VOLUMEDOWN = SDLK_VOLUMEDOWN,
        KP_COMMA = SDLK_KP_COMMA,
        KP_EQUALSAS400 = SDLK_KP_EQUALSAS400,
        ALTERASE = SDLK_ALTERASE,
        SYSREQ = SDLK_SYSREQ,
        CANCEL = SDLK_CANCEL,
        CLEAR = SDLK_CLEAR,
        PRIOR = SDLK_PRIOR,
        RETURN2 = SDLK_RETURN2,
        SEPARATOR = SDLK_SEPARATOR,
        OUT = SDLK_OUT,
        OPER = SDLK_OPER,
        CLEARAGAIN = SDLK_CLEARAGAIN,
        CRSEL = SDLK_CRSEL,
        EXSEL = SDLK_EXSEL,
        KP_00 = SDLK_KP_00,
        KP_000 = SDLK_KP_000,
        THOUSANDSSEPARATOR = SDLK_THOUSANDSSEPARATOR,
        DECIMALSEPARATOR = SDLK_DECIMALSEPARATOR,
        CURRENCYUNIT = SDLK_CURRENCYUNIT,
        CURRENCYSUBUNIT = SDLK_CURRENCYSUBUNIT,
        KP_LEFTPAREN = SDLK_KP_LEFTPAREN,
        KP_RIGHTPAREN = SDLK_KP_RIGHTPAREN,
        KP_LEFTBRACE = SDLK_KP_LEFTBRACE,
        KP_RIGHTBRACE = SDLK_KP_RIGHTBRACE,
        KP_TAB = SDLK_KP_TAB,
        KP_BACKSPACE = SDLK_KP_BACKSPACE,
        KP_A = SDLK_KP_A,
        KP_B = SDLK_KP_B,
        KP_C = SDLK_KP_C,
        KP_D = SDLK_KP_D,
        KP_E = SDLK_KP_E,
        KP_F = SDLK_KP_F,
        KP_XOR = SDLK_KP_XOR,
        KP_POWER = SDLK_KP_POWER,
        KP_PERCENT = SDLK_KP_PERCENT,
        KP_LESS = SDLK_KP_LESS,
        KP_GREATER = SDLK_KP_GREATER,
        KP_AMPERSAND = SDLK_KP_AMPERSAND,
        KP_DBLAMPERSAND = SDLK_KP_DBLAMPERSAND,
        KP_VERTICALBAR = SDLK_KP_VERTICALBAR,
        KP_DBLVERTICALBAR = SDLK_KP_DBLVERTICALBAR,
        KP_COLON = SDLK_KP_COLON,
        KP_HASH = SDLK_KP_HASH,
        KP_SPACE = SDLK_KP_SPACE,
        KP_AT = SDLK_KP_AT,
        KP_EXCLAM = SDLK_KP_EXCLAM,
        KP_MEMSTORE = SDLK_KP_MEMSTORE,
        KP_MEMRECALL = SDLK_KP_MEMRECALL,
        KP_MEMCLEAR = SDLK_KP_MEMCLEAR,
        KP_MEMADD = SDLK_KP_MEMADD,
        KP_MEMSUBTRACT = SDLK_KP_MEMSUBTRACT,
        KP_MEMMULTIPLY = SDLK_KP_MEMMULTIPLY,
        KP_MEMDIVIDE = SDLK_KP_MEMDIVIDE,
        KP_PLUSMINUS = SDLK_KP_PLUSMINUS,
        KP_CLEAR = SDLK_KP_CLEAR,
        KP_CLEARENTRY = SDLK_KP_CLEARENTRY,
        KP_BINARY = SDLK_KP_BINARY,
        KP_OCTAL = SDLK_KP_OCTAL,
        KP_DECIMAL = SDLK_KP_DECIMAL,
        KP_HEXADECIMAL = SDLK_KP_HEXADECIMAL,
        LCTRL = SDLK_LCTRL,
        LSHIFT = SDLK_LSHIFT,
        LALT = SDLK_LALT,
        LGUI = SDLK_LGUI,
        RCTRL = SDLK_RCTRL,
        RSHIFT = SDLK_RSHIFT,
        RALT = SDLK_RALT,
        RGUI = SDLK_RGUI,
        MODE = SDLK_MODE,
        AUDIONEXT = SDLK_AUDIONEXT,
        AUDIOPREV = SDLK_AUDIOPREV,
        AUDIOSTOP = SDLK_AUDIOSTOP,
        AUDIOPLAY = SDLK_AUDIOPLAY,
        AUDIOMUTE = SDLK_AUDIOMUTE,
        MEDIASELECT = SDLK_MEDIASELECT,
        WWW = SDLK_WWW,
        MAIL = SDLK_MAIL,
        CALCULATOR = SDLK_CALCULATOR,
        COMPUTER = SDLK_COMPUTER,
        AC_SEARCH = SDLK_AC_SEARCH,
        AC_HOME = SDLK_AC_HOME,
        AC_BACK = SDLK_AC_BACK,
        AC_FORWARD = SDLK_AC_FORWARD,
        AC_STOP = SDLK_AC_STOP,
        AC_REFRESH = SDLK_AC_REFRESH,
        AC_BOOKMARKS = SDLK_AC_BOOKMARKS,
        BRIGHTNESSDOWN = SDLK_BRIGHTNESSDOWN,
        BRIGHTNESSUP = SDLK_BRIGHTNESSUP,
        DISPLAYSWITCH = SDLK_DISPLAYSWITCH,
        KBDILLUMTOGGLE = SDLK_KBDILLUMTOGGLE,
        KBDILLUMDOWN = SDLK_KBDILLUMDOWN,
        KBDILLUMUP = SDLK_KBDILLUMUP,
        EJECT = SDLK_EJECT,
        SLEEP = SDLK_SLEEP,
    };
}

// ---------------------------------------------------------------------------------------------------------------------

class Engine;

// ---------------------------------------------------------------------------------------------------------------------

class Input
{
    XMA_PRIVATE_DATA();

    friend class Engine;

    public:

        bool isKeyPressed(Key::Code key) const;
        bool isMouseButtonPressed(Mouse::Button button) const;
        bool isMouseButtonUp(Mouse::Button button) const;
        bool isMouseButtonDown(Mouse::Button button) const;

        bool isMouseMove() const;
        bool isMouseScroll() const;

        glm::vec2 getMouseMove() const;
        glm::vec2 getMouseScroll() const;
        glm::vec2 getMousePosition() const;
        glm::vec2 getMousePositionRelative() const;
        glm::vec2 getMousePositionGlobal() const;

    private:

        Input();
};

// ---------------------------------------------------------------------------------------------------------------------

using InputUptr = std::unique_ptr<Input>;

// ---------------------------------------------------------------------------------------------------------------------

}}

#endif
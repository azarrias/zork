#ifndef _STYLEMOD_H_
#define _STYLEMOD_H_

#include <ostream>

namespace Style {
	enum Code {
		RESET = 0,
		BOLD = 1,
		UNDERLINE = 4,
		ENCIRCLED = 52,
		OVERLINED = 53,
		FG_BLACK = 30,
		FG_RED = 31,
		FG_GREEN = 32,
		FG_YELLOW = 33,
		FG_BLUE = 34,
		FG_MAGENTA = 35,
		FG_CYAN = 36,
		FG_LIGHT_GRAY = 37, 
		FG_DEFAULT = 39,
		BG_BLACK = 40,
		BG_RED = 41,
		BG_GREEN = 42,
		BG_YELLOW = 43,
		BG_BLUE = 44,
		BG_MAGENTA = 45,
		BG_CYAN = 46,
		BG_LIGHT_GRAY = 47,
		BG_DEFAULT = 49
	};
	class Modifier {
		Code code;
		bool useSGR;
	public:
		Modifier(Code pCode, bool show = true) 
			: code(pCode), useSGR(show){}
		Code getCode() const { return code; }
		bool getUseStyles() const { return useSGR; }
	};
	std::ostream& operator<<(std::ostream& os, const Modifier& mod) {
		if (mod.getUseStyles()) return os << "\033[" << mod.getCode() << "m";
		else return os;
	}
}

#endif
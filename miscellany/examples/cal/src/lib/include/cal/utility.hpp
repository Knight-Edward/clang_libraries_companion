#pragma once

#include <string>
#include <format>
#include "llvm/Support/raw_ostream.h"

namespace cal {

#if 0
template<class... Ts>
void print(std::format_string<Ts...> fmt, Ts&&... args) {
	llvm::outs() << std::format(fmt, std::forward<Ts>(args)...);
}
#else
template <typename... Args>
void print(std::string_view fmt, Args&&... args) {
	llvm::outs() << std::vformat(fmt,
	  std::make_format_args(std::forward<Args>(args)...));
}
#endif

#if 0
// C++23?
template<class... Ts>
void log(std::format_string<Ts...> fmt, Ts&&... args) {
	llvm::errs() << std::format(fmt, std::forward<Ts>(args)...);
}
#else
template <typename... Args>
void log(std::string_view fmt, Args&&... args) {
	llvm::errs() << std::vformat(fmt,
	  std::make_format_args(std::forward<Args>(args)...));
}
#endif

std::string addLineNumbers(const std::string& source, unsigned int startLineNo,
  unsigned int startColNo, bool lineHeader, bool columnHeader);

std::string getClangIncludeDirPathName();

#if defined(CAL_INTERNAL)
std::string getClangVersion(const std::string& pathname);
std::string getClangProgramPath();
#endif

} // namespace cal

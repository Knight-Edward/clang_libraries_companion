function(cl_get_clang_libs out_libs_var)
	if(NOT TARGET clangTooling)
		# Note: This case handles the LLVM/Clang distribution in Fedora 37.
		list(APPEND libs LLVM clang-cpp libclang)
	else()
		list(APPEND libs
			clangTooling
			clangAST
			clangASTMatchers
			clangBasic
			clangDynamicASTMatchers
			clangFrontend
			clangTooling
			clangSerialization
			libclang
		)
	endif()
	message("Clang libraries: ${libs}")
	set(${out_libs_var} ${libs} PARENT_SCOPE)
endfunction(cl_get_clang_libs)

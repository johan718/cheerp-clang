add_subdirectory(diagtool)
add_subdirectory(driver)
add_subdirectory(clang-format)
add_subdirectory(clang-format-vs)

add_subdirectory(c-index-test)
add_subdirectory(libclang)

if(CLANG_ENABLE_ARCMT)
  add_subdirectory(arcmt-test)
  add_subdirectory(c-arcmt-test)
endif()

if(CLANG_ENABLE_STATIC_ANALYZER)
  add_subdirectory(clang-check)
endif()

# We support checking out the clang-tools-extra repository into the 'extra'
# subdirectory. It contains tools developed as part of the Clang/LLVM project
# on top of the Clang tooling platform. We keep them in a separate repository
# to keep the primary Clang repository small and focused.
# It also may be included by LLVM_EXTERNAL_CLANG_TOOLS_EXTRA_SOURCE_DIR.
add_llvm_external_project(clang-tools-extra extra)

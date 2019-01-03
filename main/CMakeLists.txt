link_directories("${CMAKE_SOURCE_DIR}/lib/x86/")

file(GLOB_RECURSE FILE_INC "./*.h")
aux_source_directory("./" FILE_SRC)
add_executable(EnttDemo ${FILE_INC} ${FILE_SRC})
target_compile_features(EnttDemo INTERFACE cxx_std_17)
target_link_libraries(EnttDemo SDL2 SDL2main)

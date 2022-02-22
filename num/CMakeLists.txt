find_package(OpenCV 4 REQUIRED)
aux_source_directory(. LIB_SRCS)			
add_library (number ${LIB_SRCS})
target_link_libraries(number ${OpenCV_LIBS})
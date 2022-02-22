find_package(OpenCV 4 REQUIRED)
find_package(fmt REQUIRED)
aux_source_directory(. LIB_SRCS)			# 添加当前目录下所有的源文件
add_library (bp ${LIB_SRCS})				# 当前目录下的文件生成一个链接库
target_link_libraries(bp 
	${OpenCV_LIBS}
	fmt::fmt
)
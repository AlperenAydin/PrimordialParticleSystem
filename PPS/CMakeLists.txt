aux_source_directory(./src SOURCES)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_library(PPS_lib ${SOURCES})
target_include_directories(PPS_lib PUBLIC ./include)
target_link_libraries( PPS_lib PUBLIC ${OpenCV_LIBS} )

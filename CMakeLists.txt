project(nms_gpu_test)

find_package(CUDA REQUIRED)
message("CUDA FOUND")
message(${PROJECT_SOURCE_DIR})

# remove the conflict between CUDA and PCL's VTK
get_directory_property(dir_defs DIRECTORY ${PROJECT_SOURCE_DIR} COMPILE_DEFINITIONS)
set(vtk_flags)
foreach(it ${dir_defs})
    message(${dir_defs})
    if(it MATCHES "vtk*")
    list(APPEND vtk_flags ${it})
    endif()
endforeach()
foreach(d ${vtk_flags})
    remove_definitions(-D${d})
endforeach()

# must use c++ 14, c++ 11 would invocke an error
SET(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};--disable-warnings;--ptxas-options=-v;-use_fast_math;-lineinfo;-std=c++14)

cuda_add_executable(nms_gpu_test
                    cpp_test.cpp
                    rbbox_overlaps_kernel.cu
                    rbbox_overlaps_kernel.hpp)

                    # cuda_add_library(gpu_cluster SHARED
#                  pcl_cluster/gpu_rideware_cluster.h
#                  pcl_cluster/gpu_rideware_cluster.cu
# )

# target_link_libraries(perception_detection3d
#                       perception_common
#                       ${OpenCV_LIBRARIES}
#                       ${catkin_LIBRARIES}
#                       ${PCL_LIBRARIES}
#                       gpu_cluster
# )

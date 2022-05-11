cmake_minimum_required(VERSION 3.8)
project(shapes_demo_typesupport)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

set(idl_files
  "idl/KeylessShapeType.idl"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${idl_files}
)

ament_export_include_directories(${PROJECT_BINARY_DIR}/rosidl_generator_c)

ament_package()

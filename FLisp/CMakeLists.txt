add_executable (FLisp "FLisp.cpp"   "running.cpp" "running.h" "type.h" "error.cpp" "error.h"     "type.cpp" "list_spliting.cpp" "list_spliting.h"
        vm.cpp
        vm.h)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FLisp PROPERTY CXX_STANDARD 20)
endif()


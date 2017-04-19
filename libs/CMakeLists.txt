add_library(ukuleleLib
        ${PROJECT_SOURCE_DIR}/libs/ukuleleSuppliers.cpp
        ${PROJECT_SOURCE_DIR}/libs/ukuleleFactory.cpp
        ../src/ui/mainwindow.cpp)

#install (TARGETS MathFunctions DESTINATION bin)
#install (FILES MathFunctions.h DESTINATION include)
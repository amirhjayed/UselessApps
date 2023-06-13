cmake_minimum_required(VERSION 3.16)

set(APP_NAME UselessApps)

project(UselessApps VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

file(GLOB_RECURSE TARGET_H include/*.h)
file(GLOB_RECURSE TARGET_SRC src/*.cpp)

qt_add_executable(${APP_NAME}
    ${TARGET_H}
    ${TARGET_SRC}
)

qt_add_qml_module(${APP_NAME}
    URI UselessApps
    VERSION 1.0
    QML_FILES resources/qml/main.qml
)

set_target_properties(${APP_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(${APP_NAME}
    PRIVATE Qt6::Quick)

target_include_directories(${APP_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

install(TARGETS ${APP_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

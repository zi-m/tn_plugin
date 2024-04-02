cmake_minimum_required(VERSION 3.15)
project(tn_plugin_src)


install(DIRECTORY include/ DESTINATION include/tn/tn_plugin)


#
# tn_plugin
#

add_library(tn_plugin STATIC
        "tn_plugin.cpp"
)

add_library(tn::tn_plugin ALIAS tn_plugin)

target_include_directories(tn_plugin
        PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
        PUBLIC "$<INSTALL_INTERFACE:include/tn/tn_plugin>"
)

target_link_libraries(tn_plugin
        PUBLIC tn::tn_log
        PUBLIC Boost::filesystem
)

target_compile_features(tn_plugin
        PUBLIC cxx_std_20
)

set_target_properties(tn_plugin PROPERTIES
        PREFIX ""
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS NO
        POSITION_INDEPENDENT_CODE ON
)

install(TARGETS tn_plugin EXPORT "tn-plugin-config"
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
)
        
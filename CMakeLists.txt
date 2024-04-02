cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(tn_plugin)

find_package(tn-log CONFIG REQUIRED)

add_subdirectory(src)

install(EXPORT "tn-plugin-config" NAMESPACE tn:: DESTINATION "share/tn-plugin")

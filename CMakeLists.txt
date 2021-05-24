cmake_minimum_required(VERSION 3.2)

project(ArchitectureMVP VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(HEADERS
    ${HEADER_DIR}/BackGroundWorker.h
    ${HEADER_DIR}/ConcreteModel.h
    ${HEADER_DIR}/ConcretePresenter.h
    ${HEADER_DIR}/ConcreteView.h
    ${HEADER_DIR}/IModel.h
    ${HEADER_DIR}/IPresenter.h
    ${HEADER_DIR}/IView.h
    ${HEADER_DIR}/Threading.h
)

set(SOURCES
    ${SOURCE_DIR}/BackGroundWorker.cpp
    ${SOURCE_DIR}/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_auto_type)
target_include_directories(${PROJECT_NAME} 
    PUBLIC
        ${HEADER_DIR}
)

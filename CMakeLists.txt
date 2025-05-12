# 최소 요구 CMake 버전
cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름과 버전
project(tcpcsp VERSION 1.0)

# C 표준 설정
set(CMAKE_C_STANDARD 99)

INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/gscsp/build)
INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/gscsp/lib/libparam_client/include)
INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/gscsp/lib/libutil/include)
INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/gscsp/lib/libgscsp/include)
INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/gscsp/lib/libgscsp/lib/libcsp/include)
INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/gscsp/lib/libgscsp/lib/libcsp/src)
INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/gscsp/build/lib/libgscsp/lib/libcsp/include)
INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/gscsp/lib/libfp_client/include)
INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/gscsp/lib/libftp_client/include)
INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/gscsp/lib/libgosh_client/include)


# src 폴더 내 모든 .c 파일을 자동으로 찾아서 변수에 저장
file(GLOB SOURCES "src/*.c")

# 실행 파일 생성
add_executable(tcpcsp ${SOURCES})

TARGET_LINK_LIBRARIES(tcpcsp ${CMAKE_CURRENT_SOURCE_DIR}/gscsp/build/libcsp-client.so)

# 필요 시 추가 라이브러리 링크
# target_link_libraries(tcpcsp PRIVATE <libname>)

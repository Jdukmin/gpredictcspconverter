# csp_client

CSP(Cubesat Space Protocol)가 쉘로 구현되어 있는 패키지이다.

아래 순서대로 명령어를 입력하여 빌드한다.

    ./tools/buildtools/gsbuildtools_bootstrap.py
    ./waf distclean configure build

### Architecture 변경

아래는 예시로 32-bit architecture에서 configure 하는 명령어이다.

    ./waf distclean configure --arch=x86

### Toolchain 변경

아래는 예시로 OBC의 toolchain을 사용하여 configure 하는 명령어이다.

    ./waf distclean configure --toolchain=arm-buildroot-linux-gnueabi-

### OBC의 toolchain과 architecture를 적용하여 configure

아래는 OBC의 toolchain과 architecture를 적용하여 configure 하는 명령어이다.

configure 전에 환경변수를 설정해주어야 한다.

    export PATH=/usr/armv5-eabi--glibc--stable-2020.02-2/bin:$PATH
    export LD_LIBRARY_PATH=/usr/armv5-eabi--glibc--stable-2020.02-2/lib:$LD_LIBRARY_PATH
    ./waf distclean configure --toolchain=arm-buildroot-linux-gnueabi- --arch=arm

아래는 'compiler_settings.json' 파일에서 수정해야 하는 OBC의 compiler setting이다.

    {       
        "name": "Linux/z7000, 32 bit",      
        "gs_part": "z7000",     
        "gs_arch": "arm",       
        "gs_os": "linux",       
        "expected_cc_version": "7.2.0",     
        "CFLAGS": ["-std=gnu99","-O3","-funsafe-math-optimizations", "-fassociative-math", "-ffast-math", "-mfloat-abi=soft", "-mcpu=arm926ej-s"],
        "warnings": ["-Wall", "-Wextra", "-Wshadow", "-Wcast-align", "-Wwrite-strings"],        
        "warnings_relaxed": ["-Wno-unused-parameter"],
        "warnings_strict": ["-Wunused-parameter", "-Wconversion"],
        "docker-container": "comms-sdk-bld",
        "docker-args": ""       
    },

### BeagleBone Black board의 architecture를 적용하여 configure

아래는 BeagleBone Black board의 architecture를 적용하여 configure 하는 명령어이다.

    ./waf distclean configure --arch=armv7-a

아래는 'compiler_settings.json' 파일에 추가해야 하는 BeagleBone Black board의 compiler setting이다.

    {
        "name": "BeagleBone Black Cortex-A8, 32 bit, 4GB eMMC, 512MB RAM",
        "gs_part": "am335x",
        "gs_arch": "armv7-a",
        "gs_os": "linux",
        "toolchain": "arm-linux-gnueabihf-",
        "expected_cc_version": "9.2.1",
        "CFLAGS": ["-std=gnu99", "-march=armv7-a", "-mthumb", "-marm", "-mfpu=neon", "-mfloat-abi=hard"],
        "CFLAGS_RELEASE": ["-O3"],
        "CFLAGS_DEBUG": ["-g"],
        "CXXFLAGS": ["-march=armv7-a", "-mthumb", "-marm", "-mfpu=neon", "-mfloat-abi=hard"],
        "CXXFLAGS_RELEASE": ["-O3"],
        "CXXFLAGS_DEBUG": ["-g"],
        "LDFLAGS": ["-march=armv7-a", "-mthumb", "-marm", "-mfpu=neon", "-mfloat-abi=hard"],
        "warnings": ["-Wall", "-Wextra", "-Wshadow", "-Wcast-align", "-Wwrite-strings"],
        "warnings_relaxed": ["-Wno-unused-parameter"],
        "warnings_strict": ["-Wunused-parameter", "-Wconversion"],
        "docker-container": "pasw-arm-linux-gnueabihf",
        "docker-args": ""
    },

### configure 시 설치해야 하는 패키지

아래는 configure 시 설치해야 하는 패키지의 설치 명령어이다.

    sudo apt install libsocketcan-dev
    sudo apt install libzmq3-dev
    sudo apt install pkg-config

아래는 패키지를 32-bit architecture 용으로 설치하는 명령어이다.

    sudo dpkg --add-architecture i386
    sudo apt update
    sudo dpkg --print-foreign-architectures
    sudo apt install libsocketcan-dev:i386
    sudo apt install libzmq3-dev:i386
    sudo apt install pkg-config:i386

32-bit architecture 용 패키지 설치는 Ubuntu-18.04 이전 버전에서만 가능하다.

## 실행

### KISS

KISS 인터페이스를 사용할 경우 아래 명령어를 입력하여 실행한다.

    ./csp-client -a28 -k/dev/ttyUSB0,speed=115200 -R"6/5 KISS"

* 28 : PC(OBC) node (default가 28이므로 28로 설정하고 싶은 경우 생략 가능)
* /dev/ttyUSB0 : UART 포트
* speed=115200 : UART baudrate
* "6/5 KISS" : Routing table (6 : CAM node)

### CAN

CAN 인터페이스를 사용할 경우 아래 명령어를 입력하여 실행한다.

    ./csp-client -a28 -ccan0 -R"6/5 CAN"

* 28 : PC(OBC) node (default가 28이므로 28로 설정하고 싶은 경우 생략 가능)
* can0 : CAN 포트
* "6/5 CAN" : Routing table (6 : CAM node)

## libcsp-client.so 공유 라이브러리 생성

가장 상위 디렉토리의 'wscript'에서 configure 함수를 아래와 같이 수정한다.

ctx.env.append_unique('CFLAGS', ['-fPIC', '-m32']) 줄이 추가되었다.

'-m32'는 32-bit architecture를 대상으로 할 때만 추가하며, 이 때는 configure 시 반드시 --arch=x86로 설정해주어야 한다.

과거 버전의 cFS를 PC에서 실행하는 경우에는 공유 라이브러리 호환성 문제로 '-m32' 옵션이 필요하지만, OBC 또는 BeagleBone Black board에서 실행하는 경우에는 '-m32' 옵션을 사용하는 경우 오히려 문제가 발생한다.

또한 payc, utrx 등의 패키지 빌드 시에도 32-bit로 빌드된 라이브러리를 사용하면 문제가 발생한다.

    def configure(ctx):
        ctx.env.append_unique('CFLAGS', ['-fPIC', '-m32'])
    
        ctx.load('gs_gcc gs_doc')
    
        ctx.gs_get_build_info('DEFINES', appName=APPNAME)
    
        # Options for libgscsp/libcsp
        ctx.options.enable_rdp = True
        ctx.options.enable_crc32 = True
        ctx.options.enable_hmac = True
        ctx.options.enable_xtea = True
        ctx.options.enable_if_kiss = True
        ctx.options.enable_if_can = True
        ctx.options.enable_if_i2c = True
        ctx.options.enable_if_zmqhub = True
        ctx.options.with_rtable = 'cidr'
        ctx.options.enable_can_socketcan = True
        ctx.options.with_router_queue_length = 100
        ctx.options.with_conn_queue_length = 100
    
        # Options for clients
        ctx.options.gssb_twi_handler = 0
        ctx.options.gssb_enable_istage = True
        ctx.options.gssb_enable_msp = True
        ctx.options.gssb_enable_sunsensor = True
        ctx.options.gssb_enable_ar6 = True
        ctx.options.gssb_enable_ant6 = True
        ctx.options.gssb_enable_i4 = True
        ctx.options.enable_nanopower2_client = True
        ctx.options.enable_bpx_client = True
    
        gs_gcc.gs_recurse(ctx)

같은 'wscript'에서 build 함수를 아래와 같이 수정한다.

ctx.program 부분이 ctx.shlib으로 수정되었다.

    def build(ctx):
        gs_gcc.gs_recurse(ctx)
    
        use = [t.name for t in ctx.get_all_task_gen() if hasattr(t, 'typ') and t.typ == 'objects']
    
        ctx.shlib(source=ctx.path.ant_glob('src/*.c'),
                    target=APPNAME,
                    use=use,
                    lib=ctx.env.LIBS + ['m', 'dl', 'rt', 'pthread'])
        os.system('cp lib/libaardvark/lib/lib64/libaardvark_c.so build/libaardvark_c.so')

## aardvark 관련 컴파일 에러

아래는 aardvark 관련 라이브러리가 64-bit로 제공되어서 발생하는 에러이다.

Aardvark는 I2C/SPI 호스트 어댑터로, 사용하지 않을 것이므로 관련 부분을 모두 주석처리하여도 무방하다.

    ../src/main.c:16:10: fatal error: gs/aardvark/command_line.h: No such file or directory
     #include <gs/aardvark/command_line.h>
              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~

src/main.c 스크립트의 aardvark 관련 부분(16, 93, 100번째 줄)을 아래와 같이 모두 주석처리한다.

    //#include <gs/aardvark/command_line.h>
    
    //gs_aardvark_register_initialize_functions();
    
    //gs_aardvark_command_line_argp,

## utf-8 관련 컴파일 에러

tools/buildtools/gs/buildtools/compiler_settings.py 스크립트의 utf-8 관련 부분 34, 35번째 줄을 주석처리하고, 59, 64번째 줄의 json.load 함수의 input 중 "utf-8"를 제거한다.

    # elif isinstance(input, unicode):
    #     return input.encode('utf-8')

    settings = json.load(ifile)

    local_settings = json.load(fp)

## libsocketcan, libzmq 관련 에러

PC에 해당 라이브러리가 없을 경우 발생하는 에러이다.

64-bit 라이브러리는 있는데 32-bit 라이브러리는 없는 경우 32-bit로 컴파일 시에도 발생한다.

가장 상위 디렉토리의 'wscript'에서 option을 아래와 같이 False로 설정한다.

    ctx.options.enable_if_zmqhub = False
    ctx.options.enable_can_socketcan = False

이 방법은 에러 메세지는 뜨지 않게 하지만 해당 기능을 사용할 수 없게 되므로 OBC에서 CAN을 사용하는 경우 등에서는 True로 설정해야 한다.

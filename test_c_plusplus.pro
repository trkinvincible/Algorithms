TEMPLATE = app
CONFIG += console c++1z#c++ 17
CONFIG += openssl-linked
PKGCONFIG += openssl

CONFIG -= app_bundle
QT += core
QT += network
QT -= gui
QT += widgets

LIBS += -latomic -lboost_system -pthread -lssl -lcrypto \
        -lpthread -Wl,--no-as-needed \
        -lprofiler -ltcmalloc \
        -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free

SOURCES += main.cpp

HEADERS += \
    cond_variable_lock.h \
    command.h \
    add_2_no_to_get_val.h \
    find_common_elemnt.h \
    bfs_binarytree.h \
    build_binary_tree.h \
    generate_test_data.h \
    learn_variadic_templates.h \
    try_cplusplus_17.h \
    bbm_interview_questions.h \
    move_schematics.h \
    visa_interview.h \
    jump_trading.h \
    razer_interview.h \
    learn_atomics.h \
    practice.h \
    smiths.h \
    boost_asio.h \
    qt_network.h
    altonomy.h

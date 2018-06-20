TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -pthread

SOURCES += main.cpp

HEADERS += \
    cond_variable_lock.h \
    command.h \
    add_2_no_to_get_val.h \
    find_common_elemnt.h \
    bfs_binarytree.h \
    build_binary_tree.h \
    generate_test_data.h \
    learn_variadic_templates.h

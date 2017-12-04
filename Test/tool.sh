if [ "$1" = "init" ]; then
    qmake
    make
fi

if [ "$1" = "run" ]; then
    make check
fi

if [ "$1" = "clean" ]; then
    make clean
    rm -f *.moc *.o *~ core *.core moc_predefs.h target_wrapper.sh Makefile
    rm -fr Test.app
fi

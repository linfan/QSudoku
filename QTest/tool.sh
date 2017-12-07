if [ "$1" = "init" ]; then
    qmake
    make
fi

if [ "$1" = "run" ]; then
    make check
fi

if [ "$1" = "clean" ]; then
    rm -f *~ core *.core target_wrapper.sh Makefile
    rm -fr QTest.app MediumFiles ../build-QTest*
fi

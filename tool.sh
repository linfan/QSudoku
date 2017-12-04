if [ "$1" = "format" ]; then
    for f in `find . -name '*.cpp' -or -name '*.h'`; do 
        astyle --style=java --pad-oper --pad-comma --pad-header \
            --indent=spaces --suffix=none --max-code-length=120 $f;
    done
fi

if [ "$1" = "clean" ]; then
    rm -fr ../build-Qsudoku-*
fi

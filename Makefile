format:
	for f in `find . -name '*.cpp' -or -name '*.h'`; do \
		astyle --style=java --pad-oper --pad-comma --pad-header \
		       --indent=spaces --suffix=none --max-code-length=120 $$f; \
	done

clean:
	rm -fr ../build-Qsudoku-*

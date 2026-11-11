find . -type f -perm -111 -exec sh -c 'f="{}"; [ -e "${f}.cpp" ] && echo "$f"' \;
find . -type f -perm -111 -exec sh -c 'f="{}"; [ -e "${f}.cpp" ] && rm "$f"' \;

find . -type d -name "*.dSYM" -exec sh -c 'f="{}"; [ -e "${f%.dSYM}.cpp" ] && echo "$f"' \;
find . -type d -name "*.dSYM" -exec sh -c 'f="{}"; [ -e "${f%.dSYM}.cpp" ] && rm -rf "$f"' \;

find . -name "tempCodeRunnerFile.cpp" -type f -exec echo {} \;
find . -name "tempCodeRunnerFile.cpp" -type f -exec rm {} \;